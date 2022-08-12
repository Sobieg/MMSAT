//
//  api.h
//
//  Created by Bassham, Lawrence E (Fed) on 9/6/17.
//  Copyright © 2017 Bassham, Lawrence E (Fed). All rights reserved.
//


//   This is a sample 'api.h' for use 'sign.c'

#ifndef api_h
#define api_h

//  Set these three values apropriately for your algorithm
// todo: check if this right values
#define CRYPTO_SECRETKEYBYTES 256
#define CRYPTO_PUBLICKEYBYTES 85
#define CRYPTO_BYTES 128

//#define CRYPTO_ALGNAME "MMSAT"

enum algname {
    PASS, MMSA, MMSAT, MMSATK
};

int crypto_sign_keypair(int64 *pk, int64 *sk);

int crypto_sign(unsigned char *h, long long int *z, const unsigned char *msg, unsigned long long msglen,
                const int64 *sk, enum algname scheme);

int crypto_sign_open(unsigned char *h, long long int *z, const unsigned char *sm, unsigned long long smlen,
                     int64 *pk, enum algname scheme);

int crypto_aggregate();

int crypto_aggregated_open();

#endif /* api_h */
