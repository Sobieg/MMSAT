/*
 * CPASSREF/verify_one_signature.c
 *
 *  Copyright 2013 John M. Schanck
 *
 *  This file is part of CPASSREF.
 *
 *  CPASSREF is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by //-V1042
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  CPASSREF is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CPASSREF.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <string.h>

#include "constants.h"
#include "pass_types.h"
#include "poly.h"
#include "hash.h"
#include "formatc.h"
#include "ntt.h"
#include "pass.h"
#include "api.h"


#define CLEAR(f) memset((f), 0, PASS_N*sizeof(int64))

int verify_one_signature(const unsigned char *h, const int64 *z, const int64 *pubkey, const unsigned char *message,
                         uint64 msglen, enum algname scheme) {
    int i;
    b_sparse_poly c;
    int64 Fc[PASS_N] = {0};
    int64 Fz[PASS_N] = {0};
    unsigned char msg_digest[HASH_BYTES];
    unsigned char h2[HASH_BYTES];

    if (reject(z))
        return INVALID;

    CLEAR(c.val);
    formatc(&c, h);

    ntt(Fc, c.val);
    ntt(Fz, z);

    for (i = 0; i < PASS_t; i++) {
        Fz[S[i]] -= Fc[S[i]] * pubkey[S[i]];
    }

    poly_cmod(Fz);

    crypto_hash_sha512(msg_digest, message, msglen);
    hashc(h2, Fz, pubkey, msg_digest, HASH_BYTES, scheme);

    for (i = 0; i < HASH_BYTES; i++) {
        if (h2[i] != h[i])
            return INVALID;
    }

    return VALID;
}
/**
 *
 * @param z
 * @param msg_digests mu
 * @param pks f^hat
 * @param coms y^hat
 * @param sign_num K
 * @return
 */
int verify_agregate(const int64 *z, const unsigned char *msg_digests, const int64 *pks, const int64 *coms,
                    uint64 sign_num) {
    return INVALID;
}