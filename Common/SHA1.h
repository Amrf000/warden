#pragma once

#include <cstdint>

#define SHA1_DIGEST_SIZE 20

typedef struct {
    uint32_t state[5];
    uint32_t count[2];
    char buffer[64];
} SHA1_CONTEXT;

void SHA1_Final(uint8_t *const digest, SHA1_CONTEXT *context);

void SHA1_Init(SHA1_CONTEXT *context);

uint8_t *SHA1_InterleaveHash(uint8_t *digest, const uint8_t *data, uint32_t len);

void SHA1_Update(SHA1_CONTEXT *context, const uint8_t *data, uint32_t len);


