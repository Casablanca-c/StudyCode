/*
 * stack.h
 *
 *  Created on: Jan 13, 2022
 *      Author: dephi-fan
 */

#ifndef INC_STACK_H_
#define INC_STACK_H_

#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif

typedef struct 
{
    const int min;
    const int max;
} Range;

typedef struct 
{
    int top;
    const int size;
    int* const pBuf;
    const Range* const pRange;
} Stack;

bool push(Stack* p, int val);
bool pop(Stack* p, int* pRet);
int StackLength(Stack* p);

#define newStack(buf){                   \
    0, sizeof(buf) / sizeof(int), (buf), \
    NULL                                 \
}

#define newStackWithRangeCheck(buf, pRange){      \
    0, sizeof(buf) / sizeof(int), (buf),          \
    pRange                                        \
}

#ifdef __cplusplus
}
#endif

#endif /* INC_STACK_H_ */
