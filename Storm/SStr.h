// Copyright (c) 2024. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
// Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
// Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
// Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
// Vestibulum commodo. Ut rhoncus gravida arcu.

//
// Created by liuyawu on 2024/3/24.
//

#ifndef WARDEN_SSTR_H
#define WARDEN_SSTR_H

#include <cstdint>

#define STORM_MAX_PATH 260
#define STORM_MAX_STR 0x7FFFFFFF

char *SStrChr(char *string, char search);

const char *SStrChr(const char *string, char search);

char *SStrChrR(char *string, char search);

const char *SStrChrR(const char *string, char search);

int SStrCmp(const char *string1, const char *string2, size_t maxchars);

int SStrCmpI(const char *string1, const char *string2, int maxchars);

size_t SStrCopy(char *dest, const char *source, size_t destsize);

char *SStrDupA(const char *string, const char *filename, uint32_t linenumber);

char *SStrDup(const char *string);

unsigned int SStrHashHT(const char *str);

size_t SStrLen(const char *string);

void SStrLower(char *string);

uint32_t SStrPack(char *dest, const char *source, uint32_t destsize);

size_t SStrPrintf(char *dest, size_t maxchars, const char *format, ...);

const char *SStrStr(const char *string, const char *search);

void SStrTokenize(
        const char **string,
        char *buffer,
        unsigned int bufferchars,
        const char *whitespace,
        int *quoted);

float SStrToFloat(const char *string);

int32_t SStrToInt(const char *string);

void SStrUpper(char *string);

#endif //WARDEN_SSTR_H
