/*  =========================================================================
    zmailer_server - 
        zmailer server
        
        

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of CZMQ, the high-level C binding for 0MQ:       
    http://czmq.zeromq.org.                                            
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

/*
@header
    zmailer_server - 
        zmailer server
        
        
@discuss
@end
*/

#include "../include/zmailer.h"

//  Structure of our class

struct _zmailer_server_t {
    int filler;     //  TODO: Declare properties
};


//  --------------------------------------------------------------------------
//  Create a new zmailer_server.

zmailer_server_t *
zmailer_server_new ()
{
    zmailer_server_t *self = (zmailer_server_t *) zmalloc (sizeof (zmailer_server_t));
    assert (self);

    //  TODO: Initialize properties

    return self;
}

//  --------------------------------------------------------------------------
//  Destroy the zmailer_server.

void
zmailer_server_destroy (zmailer_server_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        zmailer_server_t *self = *self_p;

        //  TODO: Free class properties

        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  Print properties of the zmailer_server object.

void
zmailer_server_print (zmailer_server_t *self)
{
    assert (self);
}


//  --------------------------------------------------------------------------
//  Self test of this class.

void
zmailer_server_test (bool verbose)
{
    printf (" * zmailer_server: ");

    //  @selftest
    //  Simple create/destroy test
    zmailer_server_t *self = zmailer_server_new ();
    assert (self);
    zmailer_server_destroy (&self);
    //  @end

    printf ("OK\n");
}
