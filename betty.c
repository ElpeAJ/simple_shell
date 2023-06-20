#include <stdio.h>
#include <stdlib.h>

/**
 * main - function
 *
 * Return: Always 0
 *
 */

int main(void)
{
	int a = 20;
	int b = 9;
	int c = 5;
	int result;

	result = a - b - c;

	printf("Subtract a - b - c\n");
	printf("%d - %d - %d = %d\n", a, b, c, result);

	return (0);
}
