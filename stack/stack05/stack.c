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

bool validateRange(Validator* pThis, int val)
{
	bool ret = false;

	if( pThis != NULL )
	{
		Range* pRange = (Range*)(pThis->pData);
		if( pRange != NULL )
		{
			ret = (pRange->min <= val) && (pRange->max >= val);
		}
	}

	return ret;
}

bool validatePrevious(Validator* pThis, int val)
{
	bool ret = false;

	if( pThis != NULL )
	{
		PreviousValue* pPrevious = (PreviousValue*)(pThis->pData);

		if( pPrevious != NULL ) 
		{
			if( pPrevious->previousValue > val )
			{
				return false;
			}
			else
			{				
				pPrevious->previousValue = val;
				ret = true;
			}
		}
	}

	return ret;
}

bool validate(Validator* p, int val)
{
	if( p == NULL )
	{
		return true;
	}
	else
	{
		return p->validate(p, val);
	}
}

int StackLength(Stack* p)
{
	int ret = 0;

	if( p != NULL )
	{
		ret = p->top;
	}

	return ret;
}

bool push(Stack* p, int val)
{
	bool ret = false;

	if( p != NULL )
	{
		if( !isStackFull(p) && validate(p->pValidator, val) )
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
