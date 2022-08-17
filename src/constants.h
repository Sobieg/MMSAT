/*
 * CPASSREF/constants.h
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

#ifndef CPASSREF_CONST_H_
#define CPASSREF_CONST_H_

/* Parameters */
#ifndef PASS_N
#define PASS_N 769
#endif

#if PASS_N == 433
#define PASS_p 775937
#define PASS_g 268673
#define PASS_k 4095
#define PASS_b 19
#define PASS_t 200
#define PASS_RADER_POLY "../data/433_rader.dat"
#define PASS_PERMUTATION "../data/433_perm.dat"
#define PASS_EVAL_POINTS "../data/433_points.dat"
#define PASS_WISDOM "./data/433_wisdom.dat"
#endif

#if PASS_N == 577
#define PASS_p 743177
#define PASS_g 296108
#define PASS_k 16383
#define PASS_b 24
#define PASS_t 280
#define PASS_RADER_POLY "../data/577_rader.dat"
#define PASS_PERMUTATION "../data/577_perm.dat"
#define PASS_EVAL_POINTS "../data/577_points.dat"
#define PASS_WISDOM "./data/577_wisdom.dat"
#endif


#if PASS_N == 769
#define PASS_p 1047379
#define PASS_g 421722
#define PASS_k 32767
#define PASS_b 29
#define PASS_t 386
#define PASS_RADER_POLY "../data/769_rader.dat"
#define PASS_PERMUTATION "../data/769_perm.dat"
#define PASS_EVAL_POINTS "../data/769_points.dat"
#define PASS_WISDOM "./data/769_wisdom.dat"
#endif

#if PASS_N == 1153
#define PASS_p 968521
#define PASS_g 56574
#define PASS_k 32767
#define PASS_b 36
#define PASS_t 600
#define PASS_RADER_POLY "../data/1153_rader.dat"
#define PASS_PERMUTATION "../data/1153_perm.dat"
#define PASS_EVAL_POINTS "../data/1153_points.dat"
#define PASS_WISDOM "./data/1153_wisdom.dat"
#endif

//todo: new parameters from MMSAT paper

#ifndef MMSA_PARAMSET
//table 19 on page 60 in paper. PARAMSET is number of line in this table
#define MMSA_PARAMSET 1
#endif

#if MMSA_PARAMSET == 1
//#define MMSA_SECURITY 128
//#define MMSA_Bk 3
//#define MMSA_Bq 0.25
//#define MMSA_t (0.33333 * MMSA_N)
//#define MMSA_Prob 0.25

#define MMSA_K 1000
#define MMSA_N 4111
#define MMSA_q //?
#define MMSA_t 1370
#define MMSA_df 1370
#define MMSA_dc 14
#define MMSA_k 83047
#define MMSA_b 28
#define MMSA_beta 484
#define MMSA_deltaBKZ //?
#define MMSA_deltaForge //?
#define MMSA_deltaUSBP_08 //?
#define MMSA_KEYSIZE 4266
#define MMSA_SIGSIZE 8398
#define MMSA_AGGSIGSIZE (1024*49)
#endif


#define UNSAFE_RAND_N (65536 - (65536 % PASS_N))
#define UNSAFE_RAND_k (65536 - (65536 % (2 * PASS_k + 1)))


/* Basic parameter checks */
#if (PASS_k) & (PASS_k + 1)
#error "Parameter k should be one less than a power of two"
#endif

/* Limit required by mknoise in sign.c */
#if PASS_k >= 32768
#error "Parameter k too large."
#endif

/* Limit required by formatc */
#if PASS_b >= 64
#error "Parameter b too large."
#endif

#endif
