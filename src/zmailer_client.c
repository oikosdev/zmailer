/*  =========================================================================
    zmailer_client - 
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
    zmailer_client - 
        zmailer server
        
        
@discuss
@end
*/

#include "../include/zmailer.h"

//  Structure of our class

struct _zmailer_client_t {
    int filler;     //  TODO: Declare properties
};


//  --------------------------------------------------------------------------
//  Create a new zmailer_client.

zmailer_client_t *
zmailer_client_new ()
{
    zmailer_client_t *self = (zmailer_client_t *) zmalloc (sizeof (zmailer_client_t));
    assert (self);

    //  TODO: Initialize properties

    return self;
}

//  --------------------------------------------------------------------------
//  Destroy the zmailer_client.

void
zmailer_client_destroy (zmailer_client_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        zmailer_client_t *self = *self_p;

        //  TODO: Free class properties

        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}


//  --------------------------------------------------------------------------
//  Print properties of the zmailer_client object.

void
zmailer_client_print (zmailer_client_t *self)
{
    assert (self);
}


//  --------------------------------------------------------------------------
//  Self test of this class.

void
zmailer_client_test (bool verbose)
{
    printf (" * zmailer_client: ");

    //  @selftest
    //  Simple create/destroy test
    zmailer_client_t *self = zmailer_client_new ();
    assert (self);
    zmailer_client_destroy (&self);
    //  @end

    printf ("OK\n");
}
