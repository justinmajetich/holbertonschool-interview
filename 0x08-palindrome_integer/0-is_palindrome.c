#include "palindrome.h"

int is_palindrome_utility(unsigned long n, unsigned long *nCopy);

/**
 * is_palindrome - Determine if an integer is a palindrome.
 * @n: Integer to check.
 *
 * Return: 1 if palindrome; otherwise, 0.
 */
int is_palindrome(unsigned long n)
{
	unsigned long nCopy = n;

	return (is_palindrome_utility(n, &nCopy));
}

/**
 * is_palindrome_utility - Recursively scan an integer to detect palindrome.
 * @n: Number to check.
 * @nCopy: Duplicate of number to check.
 *
 * Return: 1 if palindrome; otherwise, 0.
 */
int is_palindrome_utility(unsigned long n, unsigned long *nCopy)
{
	/* Base case */
	if (n > 0 && n < 10)
		return (n == *nCopy % 10);

	if (!is_palindrome_utility(n / 10, nCopy))
		return (0);

	*nCopy /= 10;

	return (n % 10 == *nCopy % 10);
}
