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
#define STORM_MAX_PATH 260
#define STORM_MAX_STR 0x7FFFFFFF

unsigned int SStrHashHT(const char *str);

char *SStrDup(const char *string);

int SStrCmp(const char *string1, const char *string2, size_t maxchars);

int SStrCmpI(const char *string1, const char *string2, int maxchars);

size_t SStrLen(const char *string);

size_t SStrCopy(char *dest, const char *source, size_t destsize);

void SStrTokenize(
        const char **string,
        char *buffer,
        unsigned int bufferchars,
        const char *whitespace,
        int *quoted);

char *SStrChr(const char *string, char search);

#endif //WARDEN_SSTR_H
