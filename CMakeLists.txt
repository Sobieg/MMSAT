cmake_minimum_required(VERSION 3.23)
project(MMSAT C)

set(CMAKE_C_STANDARD 17)

set(PASS_SRC
        src/api.c src/api.h
        src/bench.c
        src/bsparseconv.c src/bsparseconv.h
        src/constants.h
        src/crypto_hash_sha512.c src/crypto_hash_sha512.h
        src/crypto_stream.c
        src/crypto_stream_salsa20.h
        src/formatc.c src/formatc.h
        src/hash.c src/hash.h
        src/key.c
        src/ntt.c src/ntt.h
        src/pass.h
        src/pass_types.h
        src/poly.c src/poly.h
        src/randombytes.c src/randombytes.h
        src/rng.c src/rng.h
        src/sign.c
        src/verify.c
        src/agregate.c)

include_directories(src)

add_executable(MMSAT ${PASS_SRC})
