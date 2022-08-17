#include <string.h>
#include <stdlib.h>

#include "constants.h"
#include "pass_types.h"
#include "poly.h"
#include "hash.h"
#include "formatc.h"
#include "ntt.h"
#include "pass.h"

/**
 *
 * @param coms y^hat
 * @param zs z
 * @param msg_digests mu
 * @param pks f^hat
 * @return
 */
int agregate(const int64 *coms, const int64 *zs, const unsigned char *msg_digests, const int64 *pks,
             const uint64 sign_num) {


    // in MMSAT paper c_i is just an hashc, and not formatC of hash.
    unsigned char* cs = calloc(sign_num, sizeof(unsigned char) * HASH_BYTES);

    for (int i = 0; i < sign_num; i++) {
        hashc(cs[i], coms[i], pks[i],msg_digests[i], HASH_BYTES, MMSA);
    }
//    /* beta = */ hashb(cs, sign_num);

    free(cs);
    cs = NULL;

}