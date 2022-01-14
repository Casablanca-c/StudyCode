/*
 * test.c
 *
 *  Created on: Jan 13, 2022
 *      Author: dephi-fan
 */
#include <stdio.h>
#include "stack.h"

int main()
{
	int i = 0;
	int ret = 0;

	for(i = 0; i < 16; i++)
	{
		push(i+1);
	}

	for(i = 0; i < 16; i++)
	{
		pop(&ret);
		printf("%d\n", ret);
	}

	return 0;
}
