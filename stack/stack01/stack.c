/*
 * stack.c
 *
 *  Created on: Jan 13, 2022
 *      Author: dephi-fan
 */
#include "stack.h"

int buf[16];
int top = 0;

bool isStackFull(void)
{
	return ( top == (sizeof(buf) / sizeof(int)) );
}

bool isStackEmpty(void)
{
	return ( top == 0 );
}


bool push(int val)
{
	bool ret = false;

	if( !isStackFull() )
	{
		buf[top++] = val;

		ret = true;
	}

	return ret;
}

bool pop(int* pRet)
{
	bool ret = false;

	if( !isStackEmpty() )
	{
		*pRet = buf[--top];

		ret = true;
	}

	return ret;
}

