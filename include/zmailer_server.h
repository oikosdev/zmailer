/*  =========================================================================
    zmailer_server - zmailer server

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

     * The XML model used for this code generation: zmailer_server.xml, or
     * The code generation script that built this file: zproto_server_c
    ************************************************************************
    =========================================================================
*/

#ifndef ZMAILER_SERVER_H_INCLUDED
#define ZMAILER_SERVER_H_INCLUDED

#include <czmq.h>

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  To work with zmailer_server, use the CZMQ zactor API:
//
//  Create new zmailer_server instance, passing logging prefix:
//
//      zactor_t *zmailer_server = zactor_new (zmailer_server, "myname");
//
//  Destroy zmailer_server instance
//
//      zactor_destroy (&zmailer_server);
//
//  Enable verbose logging of commands and activity:
//
//      zstr_send (zmailer_server, "VERBOSE");
//
//  Bind zmailer_server to specified endpoint. TCP endpoints may specify
//  the port number as "*" to aquire an ephemeral port:
//
//      zstr_sendx (zmailer_server, "BIND", endpoint, NULL);
//
//  Return assigned port number, specifically when BIND was done using an
//  an ephemeral port:
//
//      zstr_sendx (zmailer_server, "PORT", NULL);
//      char *command, *port_str;
//      zstr_recvx (zmailer_server, &command, &port_str, NULL);
//      assert (streq (command, "PORT"));
//
//  Specify configuration file to load, overwriting any previous loaded
//  configuration file or options:
//
//      zstr_sendx (zmailer_server, "LOAD", filename, NULL);
//
//  Set configuration path value:
//
//      zstr_sendx (zmailer_server, "SET", path, value, NULL);
//
//  Save configuration data to config file on disk:
//
//      zstr_sendx (zmailer_server, "SAVE", filename, NULL);
//
//  Send zmsg_t instance to zmailer_server:
//
//      zactor_send (zmailer_server, &msg);
//
//  Receive zmsg_t instance from zmailer_server:
//
//      zmsg_t *msg = zactor_recv (zmailer_server);
//
//  This is the zmailer_server constructor as a zactor_fn:
//
void
    zmailer_server (zsock_t *pipe, void *args);

//  Self test of this class
void
    zmailer_server_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
