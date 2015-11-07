/*  =========================================================================
    hello_msg - hello msg protocol

    Codec header for hello_msg.

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

     * The XML model used for this code generation: hello_msg.xml, or
     * The code generation script that built this file: zproto_codec_c
    ************************************************************************
    =========================================================================
*/

#ifndef HELLO_MSG_H_INCLUDED
#define HELLO_MSG_H_INCLUDED

/*  These are the hello_msg messages:

    HELLO - 

    WORLD - 
*/


#define HELLO_MSG_HELLO                     1
#define HELLO_MSG_WORLD                     2

#include <czmq.h>

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
#ifndef HELLO_MSG_T_DEFINED
typedef struct _hello_msg_t hello_msg_t;
#define HELLO_MSG_T_DEFINED
#endif

//  @interface
//  Create a new empty hello_msg
hello_msg_t *
    hello_msg_new (void);

//  Destroy a hello_msg instance
void
    hello_msg_destroy (hello_msg_t **self_p);

//  Receive a hello_msg from the socket. Returns 0 if OK, -1 if
//  there was an error. Blocks if there is no message waiting.
int
    hello_msg_recv (hello_msg_t *self, zsock_t *input);

//  Send the hello_msg to the output socket, does not destroy it
int
    hello_msg_send (hello_msg_t *self, zsock_t *output);

//  Print contents of message to stdout
void
    hello_msg_print (hello_msg_t *self);

//  Get/set the message routing id
zframe_t *
    hello_msg_routing_id (hello_msg_t *self);
void
    hello_msg_set_routing_id (hello_msg_t *self, zframe_t *routing_id);

//  Get the hello_msg id and printable command
int
    hello_msg_id (hello_msg_t *self);
void
    hello_msg_set_id (hello_msg_t *self, int id);
const char *
    hello_msg_command (hello_msg_t *self);

//  Self test of this class
void
    hello_msg_test (bool verbose);
//  @end

//  For backwards compatibility with old codecs
#define hello_msg_dump      hello_msg_print

#ifdef __cplusplus
}
#endif

#endif
