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
#include "./zmailer_msg.h"
#include "./zmailer_client.h"

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
    zactor_t *client = zactor_new (zmailer_client, NULL);
    zmailer_client_verbose = verbose;
    zactor_destroy (&client);

    zmailer_client_t *myclient = zmailer_client_new ();
    assert (myclient);
    zmailer_client_constructor (myclient, "ipc://@/zmailer_server");

    //  @end
    printf ("OK\n");
}
