/*  =========================================================================
    zmailer_client - ZMailer Client

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

     * The XML model used for this code generation: zmailer_client.xml, or
     * The code generation script that built this file: zproto_client_c
    ************************************************************************
    =========================================================================
*/

#ifndef ZMAILER_CLIENT_H_INCLUDED
#define ZMAILER_CLIENT_H_INCLUDED

#include <czmq.h>

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
#ifndef ZMAILER_CLIENT_T_DEFINED
typedef struct _zmailer_client_t zmailer_client_t;
#define ZMAILER_CLIENT_T_DEFINED
#endif

//  @interface
//  Create a new zmailer_client, return the reference if successful, or NULL
//  if construction failed due to lack of available memory.
zmailer_client_t *
    zmailer_client_new (void);

//  Destroy the zmailer_client and free all memory used by the object.
void
    zmailer_client_destroy (zmailer_client_t **self_p);

//  Return actor, when caller wants to work with multiple actors and/or
//  input sockets asynchronously.
zactor_t *
    zmailer_client_actor (zmailer_client_t *self);

//  Return message pipe for asynchronous message I/O. In the high-volume case,
//  we send methods and get replies to the actor, in a synchronous manner, and
//  we send/recv high volume message data to a second pipe, the msgpipe. In
//  the low-volume case we can do everything over the actor pipe, if traffic
//  is never ambiguous.
zsock_t *
    zmailer_client_msgpipe (zmailer_client_t *self);

//  Return true if client is currently connected, else false. Note that the
//  client will automatically re-connect if the server dies and restarts after
//  a successful first connection.
bool
    zmailer_client_connected (zmailer_client_t *self);

//  Self test of this class
void
    zmailer_client_test (bool verbose);

//  To enable verbose tracing (animation) of zmailer_client instances, set
//  this to true. This lets you trace from and including construction.
extern volatile int
    zmailer_client_verbose;
//  @end

#ifdef __cplusplus
}
#endif

#endif
