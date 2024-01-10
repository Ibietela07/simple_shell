#include "shell.h"
#include <stdio.h>

/**
 *print_world - a function that prints world to the standard output
 *
 * Return: always 0.
 */

int print_world(void)
{
	printf("world");
	return(0);
}

/**
 * main - start point of the program
 * 
 * Return: void
 */
int main(void)
{
	print_world();
	return(0);
}
