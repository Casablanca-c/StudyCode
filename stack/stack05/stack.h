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

// introduce a validator
typedef struct Validator
{
    bool (* const validate)(struct Validator *pThis, int val);
    void* const pData;
} Validator;

typedef struct 
{
    const int min;
    const int max;
} Range;

typedef struct
{
    int previousValue;
} PreviousValue;


typedef struct 
{
    int top;
    const int size;
    int* const pBuf;
    Validator* const pValidator;
} Stack;

int StackLength(Stack* p);

bool validateRange(Validator* pThis, int val);
bool validatePrevious(Validator* pThis, int val);

bool push(Stack* p, int val);
bool pop(Stack* p, int* pRet);

#define newStack(buf) {                  \
    0, sizeof(buf) / sizeof(int), (buf), \
    NULL                                 \
}

#define rangeValidator(pRange){ \
    validateRange,              \
    pRange                      \
}

#define prevoiusValidator(pPrevious){  \
    validatePrevious,                  \
    pPrevious                          \
}

#define newStackWithValidator(buf, pValidator) { \
    0, sizeof(buf) / sizeof(int), (buf),         \
    pValidator                                   \
}

#ifdef __cplusplus
}
#endif

#endif /* INC_STACK_H_ */
