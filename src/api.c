#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "constants.h"
#include "pass_types.h"
#include "ntt.h"
#include "rng.h"
#include "pass.h"
#include "api.h"

#include "poly.h"
#include "formatc.h"
#include "bsparseconv.h"
#include "hash.h"
//#include "fastrandombytes.h"

#define CLEAR(f) memset((f), 0, PASS_N*sizeof(int64))

#define RAND_LEN (4096)

//static uint16 randpool[RAND_LEN];
//static int randpos;


int crypto_sign_keypair(int64 *pk, int64 *sk) {

//	int64 key[PASS_N];
    gen_key(sk);

    // printf("\n\nKey: ");
    // for(int i=0; i<PASS_N; i++)
    //   printf("%lld, ", ((long long int) key[i]));

//	int64 pubkey[PASS_N] = {0};
    gen_pubkey(pk, sk);

    // printf("\n\nPubkey: ");
    // for(int i=0; i<PASS_N; i++)
    //   printf("%lld, ", ((long long int) pubkey[i]));

//  sk = (unsigned char*)key;
//  pk = (unsigned char*)pubkey;

    return 0;
}


// sm-->h, smlen-->z, m-->message, mlen-->msglen, sk-->key
int crypto_sign(unsigned char *sm, unsigned long long *smlen,
                const unsigned char *m, unsigned long long mlen,
                const int64 *sk) {
    return sign(sm, smlen, sk, m, mlen);
}

// m-->h, mlen-->z
int crypto_sign_open(unsigned char *m, unsigned long long *mlen,
                     const unsigned char *sm, unsigned long long smlen,
                     int64 *pk) {
    return verify_one_signature(m, mlen, pk, sm, smlen);
}


int crypto_aggregate() {
    return agregate();
}

int crypto_aggregated_open() {
    return verify();
}
