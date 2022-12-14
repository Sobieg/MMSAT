/*
 * CPASSREF/pass.h
 *
 *  Copyright 2013 John M. Schanck
 *
 *  This file is part of CPASSREF.
 *
 *  CPASSREF is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
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

#ifndef CPASSREF_PASS_H_
#define CPASSREF_PASS_H_

#include "api.h"

/* Return values for verify_one_signature */
#define VALID 0
#define INVALID (-1)


static const int64 S[PASS_t] = {
#include PASS_EVAL_POINTS
};

int gen_key(int64 *f);

int gen_pubkey(int64 *pkey, int64 *skey);

int init_fast_prng();

int mknoise(int64 *y);

int reject(const int64 *z);

int
sign(unsigned char *h, int64 *z, const int64 *key, const int64 *pk, const unsigned char *message,
     const unsigned long long int msglen, enum algname scheme);

int verify_one_signature(const unsigned char *h, const int64 *z, const int64 *pubkey, const unsigned char *message,
                         uint64 msglen, enum algname scheme);

int
agregate(const int64 *coms, const int64 *zs, const unsigned char *msg_digests, const int64 *pks, const uint64 sign_num);

int
verify_agregate(const int64 *z, const unsigned char *msg_digests, const int64 *pks, const int64 *coms, uint64 sign_num);

#endif
