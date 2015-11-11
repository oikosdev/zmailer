/*  =========================================================================
    zmailer_server - zmailer_server

    =========================================================================
*/

/*
@header
    Description of class for man page.
@discuss
    Detailed discussion of the class, if any.
@end
*/

#include "zmailer.h"
//  TODO: Change these to match your project's needs
#include "../include/zmailer_msg.h"
#include "../include/zmailer_server.h"

//  ---------------------------------------------------------------------------
//  Forward declarations for the two main classes we use here

typedef struct _server_t server_t;
typedef struct _client_t client_t;

//  This structure defines the context for each running server. Store
//  whatever properties and structures you need for the server.

struct _server_t {
    //  These properties must always be present in the server_t
    //  and are set by the generated engine; do not modify them!
    zsock_t *pipe;              //  Actor pipe back to caller
    zconfig_t *config;          //  Current loaded configuration

    //  TODO: Add any properties you need here
};

//  ---------------------------------------------------------------------------
//  This structure defines the state for each client connection. It will
//  be passed to each action in the 'self' argument.

struct _client_t {
    //  These properties must always be present in the client_t
    //  and are set by the generated engine; do not modify them!
    server_t *server;           //  Reference to parent server
    zmailer_msg_t *message;     //  Message in and out

    //  TODO: Add specific properties for your application
};

struct upload_status {
 int lines_read;
 zmailer_msg_t *msg;
};


//  Include the generated server engine
#include "zmailer_server_engine.inc"

//  Allocate properties and structures for a new server instance.
//  Return 0 if OK, or -1 if there was an error.

static int
server_initialize (server_t *self)
{
    //  Construct properties here
   return 0;
}

//  Free properties and structures for a server instance

static void
server_terminate (server_t *self)
{
    //  Destroy properties here
}

//  Process server API method, return reply message if any

static zmsg_t *
server_method (server_t *self, const char *method, zmsg_t *msg)
{
    return NULL;
}

//  Allocate properties and structures for a new client connection and
//  optionally engine_set_next_event (). Return 0 if OK, or -1 on error.

static int
client_initialize (client_t *self)
{
    //  Construct properties here
    const char *password = zconfig_get (self->server->config, "/zmailer_server/password", "");
    zsys_info ("at initialize: %s", password);
    return 0;
}

//  Free properties and structures for a client connection

static void
client_terminate (client_t *self)
{
    //  Destroy properties here
}

//  ---------------------------------------------------------------------------
//  Selftest

void
zmailer_server_test (bool verbose)
{
    printf (" * zmailer_server: ");
    if (verbose)
        printf ("\n");

    //  @selftest
    zactor_t *server = zactor_new (zmailer_server, "server");
    if (verbose)
        zstr_send (server, "VERBOSE");

    zstr_sendx (server, "LOAD", ".config/zmailer.cfg", NULL);
    //zstr_sendx (server, "BIND", "ipc://@/zmailer_server", NULL);
    
    zsock_t *client = zsock_new (ZMQ_DEALER);
    assert (client);
    zsock_set_rcvtimeo (client, 2000);
    zsock_connect (client, "ipc://@/zmailer_server");

    //  TODO: fill this out
    zmailer_msg_t *request = zmailer_msg_new ();
    zmailer_msg_set_id (request, ZMAILER_MSG_HELLO);
    zmailer_msg_send (request, client);
    sleep (1);
    zmailer_msg_destroy (&request);
    zmailer_msg_t *request2 = zmailer_msg_new ();
    zmailer_msg_set_id (request2, ZMAILER_MSG_MAIL);
    zmailer_msg_set_from (request2, "oikosdev <cb@oikosdev.net>");
    zmailer_msg_set_to   (request2, "<christophe.beauce@gmail.com>");
    zmailer_msg_set_subject (request2, "Test");
    zmailer_msg_set_request (request2, "This is a test email for you !");
    zmailer_msg_send (request2, client);
    sleep (1);
    zmailer_msg_destroy (&request2);
    zsock_destroy (&client);
    zactor_destroy (&server);
    //  @end
    printf ("OK\n");
}


//  ---------------------------------------------------------------------------
//  echo
//

static void
echo (client_t *self)
{
 zsys_info ("echo !!");
 const char *password = zconfig_get (self->server->config, "/zmailer_server/password", "");
 zsys_info ("configured password: %s", password);
}


//  ---------------------------------------------------------------------------
//  send_email
//

static void
send_email (client_t *self)
{

 assert (self);
 assert (self->message);
 zsys_info ("sending email !");
 sleep (2);

 CURL *curl;
 CURLcode res = CURLE_OK;
 struct curl_slist *recipients = NULL;

 FILE *pFile = fopen ("./data/mail.txt","w");
 // todo
 fprintf (pFile,"Date: Mon, 29 Nov 2010 21:54:29 +1100\r\n");
 zsys_info ("To: %s \r\n", zmailer_msg_to(self->message));
 fprintf (pFile,"To: %s\r\n", zmailer_msg_to(self->message));
 fprintf (pFile, "From: %s\r\n", zmailer_msg_from (self->message));
 fprintf (pFile, "Subject: %s \r\n", zmailer_msg_subject (self->message));
 fprintf (pFile, "\r\n");
 fprintf (pFile, "%s Thank you. \r\n", zmailer_msg_request(self->message));
 // fprintf (pFile, "\r\n.\r\n");
 fclose (pFile);
 sleep (20);

// zfile_t* zf2 = zfile_new ("data","mail.txt");
// zfile_input (zf2);

 FILE * pMail;
 pMail = fopen ("./data/mail.txt","r");
// = zfile_handle (zf2);

 curl = curl_easy_init();
 if(curl) {
    /* Set username and password */ 
    curl_easy_setopt(curl, CURLOPT_USERNAME, zconfig_get (self->server->config, "zmailer_server/user", ""));
    curl_easy_setopt(curl, CURLOPT_PASSWORD, zconfig_get (self->server->config, "zmailer_server/password", ""));
 
    /* This is the URL for your mailserver. Note the use of port 587 here,
     * instead of the normal SMTP port (25). Port 587 is commonly used for
     * secure mail submission (see RFC4403), but you should use whatever
     * matches your server configuration. */ 
    curl_easy_setopt(curl, CURLOPT_URL, zconfig_get (self->server->config, "zmailer_server/server", ""));

    /* In this example, we'll start with a plain text connection, and upgrade
     * to Transport Layer Security (TLS) using the STARTTLS command. Be careful
     * of using CURLUSESSL_TRY here, because if TLS upgrade fails, the transfer
     * will continue anyway - see the security discussion in the libcurl
     * tutorial for more details. */ 
    curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
 
    /* If your server doesn't have a valid certificate, then you can disable
     * part of the Transport Layer Security protection by setting the
     * CURLOPT_SSL_VERIFYPEER and CURLOPT_SSL_VERIFYHOST options to 0 (false).*/
     curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
     curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); 
    /* Note that this option isn't strictly required, omitting it will result in
     * libcurl sending the MAIL FROM command with empty sender data. All
     * autoresponses should have an empty reverse-path, and should be directed
     * to the address in the reverse-path which triggered them. Otherwise, they
     * could cause an endless loop. See RFC 5321 Section 4.5.5 for more details.
     */ 
    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, zmailer_msg_from (self->message));

    /* Add two recipients, in this particular case they correspond to the
     * To: and Cc: addressees in the header, but they could be any kind of
     * recipient. */ 
    recipients = curl_slist_append(recipients, zmailer_msg_to (self->message));
    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
 
    /* We're using a callback function to specify the payload (the headers and
     * body of the message). You could just use the CURLOPT_READDATA option to
     * specify a FILE pointer to read from. */ 
    curl_easy_setopt(curl, CURLOPT_READDATA, pMail);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
 
    /* Since the traffic will be encrypted, it is very useful to turn on debug
     * information within libcurl to see what is happening during the transfer.
     */ 
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
 
    /* Send the message */ 
    res = curl_easy_perform(curl);
 
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* Free the list of recipients */ 
    curl_slist_free_all(recipients);
 
    /* Always cleanup */ 
    curl_easy_cleanup(curl);
  }
assert(pMail); 
}
