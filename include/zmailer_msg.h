/*  =========================================================================
    zmailer_msg - zmailer msg protocol

    Codec header for zmailer_msg.

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

     * The XML model used for this code generation: zmailer_msg.xml, or
     * The code generation script that built this file: zproto_codec_c
    ************************************************************************
    =========================================================================
*/

#ifndef ZMAILER_MSG_H_INCLUDED
#define ZMAILER_MSG_H_INCLUDED

/*  These are the zmailer_msg messages:

    MAIL - Send a message by Mail (using predefined other parameters)
        version             number 2    Version
        from                string      From field
        to                  longstr     To field
        subject             longstr     Subject of the mail
        request             longstr     Content text of the mail
*/


#define ZMAILER_MSG_MAIL                    1

#include <czmq.h>

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
#ifndef ZMAILER_MSG_T_DEFINED
typedef struct _zmailer_msg_t zmailer_msg_t;
#define ZMAILER_MSG_T_DEFINED
#endif

//  @interface
//  Create a new empty zmailer_msg
zmailer_msg_t *
    zmailer_msg_new (void);

//  Destroy a zmailer_msg instance
void
    zmailer_msg_destroy (zmailer_msg_t **self_p);

//  Receive a zmailer_msg from the socket. Returns 0 if OK, -1 if
//  there was an error. Blocks if there is no message waiting.
int
    zmailer_msg_recv (zmailer_msg_t *self, zsock_t *input);

//  Send the zmailer_msg to the output socket, does not destroy it
int
    zmailer_msg_send (zmailer_msg_t *self, zsock_t *output);

//  Print contents of message to stdout
void
    zmailer_msg_print (zmailer_msg_t *self);

//  Get/set the message routing id
zframe_t *
    zmailer_msg_routing_id (zmailer_msg_t *self);
void
    zmailer_msg_set_routing_id (zmailer_msg_t *self, zframe_t *routing_id);

//  Get the zmailer_msg id and printable command
int
    zmailer_msg_id (zmailer_msg_t *self);
void
    zmailer_msg_set_id (zmailer_msg_t *self, int id);
const char *
    zmailer_msg_command (zmailer_msg_t *self);

//  Get/set the from field
const char *
    zmailer_msg_from (zmailer_msg_t *self);
void
    zmailer_msg_set_from (zmailer_msg_t *self, const char *value);

//  Get/set the to field
const char *
    zmailer_msg_to (zmailer_msg_t *self);
void
    zmailer_msg_set_to (zmailer_msg_t *self, const char *value);

//  Get/set the subject field
const char *
    zmailer_msg_subject (zmailer_msg_t *self);
void
    zmailer_msg_set_subject (zmailer_msg_t *self, const char *value);

//  Get/set the request field
const char *
    zmailer_msg_request (zmailer_msg_t *self);
void
    zmailer_msg_set_request (zmailer_msg_t *self, const char *value);

//  Self test of this class
void
    zmailer_msg_test (bool verbose);
//  @end

//  For backwards compatibility with old codecs
#define zmailer_msg_dump    zmailer_msg_print

#ifdef __cplusplus
}
#endif

#endif
