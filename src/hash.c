/*
 * CPASSREF/hashc.c
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
#include <stdlib.h>

#include "constants.h"
#include "pass_types.h"
#include "hash.h"
#include "pass.h"

/**
 *
 * @param pk — transformed pk, f_hat in paper
 * @param com — commitment, y_hat in paper
 * @param msg — message digest (!)
 * @param msglen — size of message
 * @param scheme
 * @return h — hash-value
 */
int hashc(unsigned char *h, const int64 *com, const int64 *pk, const unsigned char *msg, uint64 msglen,
          enum algname scheme) {


    /**
     * TODO:
     * 1) PASS should be used without pk
     * 2) MMSAT should return polynom, not hash digest
     * 3) Should we use conditional compilation instead of branching? For standalone project i think it would be good,
     * but in DAP we should use just different schemes (or only MMSATK)
     */


    if (scheme == PASS) {
        uint64 inlen = PASS_t + HASH_BYTES;
        unsigned char in[inlen];
        memset(in, 0, inlen);

        for (int i = 0; i < PASS_t; i++) {
            in[i] = (unsigned char) com[S[i]] & 0xff;
        }
        for(int i = 0; i<HASH_BYTES; i++) {
            in[PASS_t + i] = msg[i];
        }

        crypto_hash_sha512(h, in, inlen);

        return 0;
    }
    else if (scheme == MMSA) {
        uint64 inlen = PASS_t + PASS_N * sizeof(int64) + HASH_BYTES;
        unsigned char in[inlen];
        memset(in, 0, inlen);



        for (int i = 0; i < PASS_t; i++) {
            in[i] = (unsigned char) com[S[i]] & 0xff;
        }
        for (int i = 0; i<PASS_N; i++) {
            for (int j = 0; j<sizeof(uint64); j++) {
                in[PASS_t + i * sizeof(uint64) + j] = pk[i] & (0xffull << (8 * j)); //copy pk byte-by-byte
            }
        }
        for(int i = 0; i<HASH_BYTES; i++) {
            in[PASS_t + PASS_N * sizeof(int64) + i] = msg[i];
        }

        crypto_hash_sha512(h, in, inlen);
        // in MMSA no need in using formatC, but hashc should already return polynomial, different from formatC


        return 0;
    }

    return 0;

}

