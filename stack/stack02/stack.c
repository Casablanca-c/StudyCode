/*
 * stack.c
 *
 *  Created on: Jan 13, 2022
 *      Author: dephi-fan
 */
#include <stdbool.h>
#include "stack.h"


static bool isStackFull(const Stack* p)
{
	bool ret = false;

	if( p != NULL )
	{
		ret = (p->top == p->size);
	}

	return ret;
}

static bool isStackEmpty(const Stack* p)
{
	bool ret = false;

	if( p != NULL )
	{
		ret = (p->top == 0);
	}

	return ret;
}


bool push(Stack* p, int val)
{
	bool ret = false;

	if( p != NULL )
	{
		if( !isStackFull(p) )
		{
			p->pBuf[p->top++] = val;

			ret = true;
		}
	}

	return ret;
}
bool pop(Stack* p, int* pRet)
{
	bool ret = false;

	if( p != NULL )
	{
		if( !isStackEmpty(p) )
		{
			*pRet = p->pBuf[--(p->top)];

			ret = true;
		}
	}

	return ret;
}
