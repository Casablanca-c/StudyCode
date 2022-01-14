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

	printf("---- stack1: with no check ----------\n");
	Stack stack = newStack(buf);
	
	for(i = 0; i < 16; i++)
	{
		push(&stack, i+1);
	}

	while (StackLength(&stack))
	{
		pop(&stack, &ret);
		printf("pop: %d\n", ret);
	}

	printf("---- stack2: with range check ----------\n");
	Range range = {3, 10};
	Validator validator = rangeValidator(&range);
	Stack stack2 = newStackWithValidator(buf, &validator);
	for(i = 0; i < 16; i++)
	{
		push(&stack2, i+1);
	}

	while (StackLength(&stack2))
	{
		pop(&stack2, &ret);
		printf("pop: %d\n", ret);
	}

	printf("---- stack3: with previous value check ----------\n");
	PreviousValue previous = {3};
	Validator validator2 = prevoiusValidator(&previous);
	Stack stack3 = newStackWithValidator(buf, &validator2);
	for(i = 0; i < 16; i++)
	{
		push(&stack3, i+1);
	}

	while (StackLength(&stack3))
	{
		pop(&stack3, &ret);
		printf("pop: %d\n", ret);
	}

	return 0;
}
