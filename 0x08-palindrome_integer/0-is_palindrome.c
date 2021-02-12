#include "palindrome.h"

/**
 * is_palindrome - Checks whether or not a given arg is a palindrome.
 * @n: Number to be checked.
 * Stores reversed number and compares to original.
 * Return: 1 if palindrome, and 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
    unsigned long int reversed = 0, remainder = 0, tmp = n;

	if (n < 10)
		return (1);
	while (tmp != 0)
	{
		remainder = tmp % 10;
		reversed = reversed * 10 + remainder;
		tmp /= 10;
	}
	if (reversed == n)
		return (1);
	return (0);
}
