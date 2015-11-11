/*  =========================================================================
    zmailer_client - ZMailer Client

    =========================================================================
*/

/*
@header
    Description of class for man page.
@discuss
    Detailed discussion of the class, if any.
@end
*/

#include "czmq.h"
//  TODO: Change these to match your project's needs
#include "../include/zmailer_msg.h"
#include "../include/zmailer_client.h"

// only for testing purpose
#include "../include/zmailer_server.h"

//  Forward reference to method arguments structure
typedef struct _client_args_t client_args_t;

//  This structure defines the context for a client connection
typedef struct {
    //  These properties must always be present in the client_t
    //  and are set by the generated engine. The cmdpipe gets
    //  messages sent to the actor; the msgpipe may be used for
    //  faster asynchronous message flows.
    zsock_t *cmdpipe;           //  Command pipe to/from caller API
    zsock_t *msgpipe;           //  Message pipe to/from caller API
    zsock_t *dealer;            //  Socket to talk to server
    zmailer_msg_t *message;     //  Message to/from server
    client_args_t *args;        //  Arguments from methods

    //  TODO: Add specific properties for your application
} client_t;

//  Include the generated client engine
#include "zmailer_client_engine.inc"

//  Allocate properties and structures for a new client instance.
//  Return 0 if OK, -1 if failed

static int
client_initialize (client_t *self)
{
    return 0;
}

//  Free properties and structures for a client instance

static void
client_terminate (client_t *self)
{
    //  Destroy properties here
}


//  ---------------------------------------------------------------------------
//  Selftest

void
zmailer_client_test (bool verbose)
{
    printf (" * zmailer_client: ");
    if (verbose)
        printf ("\n");

    //  @selftest
    // test actor client
    zactor_t *client = zactor_new (zmailer_client, NULL);
    zmailer_client_verbose = verbose;
    zactor_destroy (&client);
    return; // skip the rest
    //--------------------------
    zactor_t *myserver = zactor_new (zmailer_server, NULL);
    //zstr_sendx (myserver, "BIND", "ipc://@/zmailer_server", NULL);
    zstr_sendx (myserver, "BIND", "tcp://127.0.0.1:9999", NULL);
    sleep (1);
    //--------------------------
    // test the API, using a server actor
    zmailer_client_t *myclient = zmailer_client_new ();
    assert (myclient);
    zmailer_client_constructor (myclient, "tcp://127.0.0.1:9999");
    sleep(2);
    zactor_destroy (&myserver);
    zmailer_client_destroy (&myclient);
    //  @end
    printf ("OK\n");
}

//  ---------------------------------------------------------------------------
//  connect_to_server
//

static void
connect_to_server (client_t *self)
{
  if(zsock_connect (self->dealer, "%s", self->args->endpoint) != 0) 
  {
   zsys_warning ("could not connect to: %s", self->args->endpoint);
  }
  else 
  {
   zsys_info ("connected to: %s", self->args->endpoint);
  }
}
