#include "palindrome.h"

unsigned long reverse_number(unsigned long n);

/**
 * is_palindrome - Determine if an integer is a palindrome.
 * @n: Integer to check.
 *
 * Return: 1 if palindrome; otherwise, 0.
 */
int is_palindrome(unsigned long n)
{
	unsigned long reverse;

	reverse = reverse_number(n);

	while (n > 0)
	{
		if (n % 10 != reverse % 10)
			return (0);
		
		n /= 10;
		reverse /= 10;
	}
	return (1);
}

/**
 * reverse_number - Reverses a number.
 * @n: The number to reverse.
 *
 * Return: A number reversed.
 */
unsigned long reverse_number(unsigned long n)
{
	unsigned long reverse = 0;

	while (n > 0)
	{
		reverse = (reverse * 10) + (n % 10);

		n /= 10;
	}

	return (reverse);
}