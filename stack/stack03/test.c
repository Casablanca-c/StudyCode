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
	int buf[16] = {0};
	Stack stack = newStack(buf);
	

	for(i = 0; i < 16; i++)
	{
		push(&stack, i+1);
	}

	while(StackLength(&stack))
	{
		pop(&stack, &ret);
		printf("%d\n", ret);
	}

	printf("----------- stack with range check --------------\n");
	Stack stack2 = newStackWithRangeCheck(buf, 5, 12);
	for(i = 0; i < 16; i++)
	{
		push(&stack2, i+1);
	}

	while(StackLength(&stack2))
	{
		pop(&stack2, &ret);
		printf("%d\n", ret);
	}

	return 0;
}
