#include "holberton.h"

/**
 * wildcmp - Compares two strings.
 * @s1: First string to compare.
 * @s2: Second string to compare, can contain *, that can replace
 * any string.
 *
 * Return: 1 if strings are identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == *s2 && *s1 != '\0')
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s1 == *s2)
		return (1);
	if (*s2 == '*' && *(s2 + 1) != *s1 && *(s2 + 1) != '*')
		return (wildcmp(s1 + 1, s2));
	if (*s2 == '*' && *(s2 + 1) != *s1 && *(s2 + 1) == '*')
		return (wildcmp(s1, s2 + 1));
	if (*s2 == '*' && wildcmp(s1, s2 + 1) == 0)
		return (wildcmp(s1 + 1, s2));
	if (*s2 == '*' && wildcmp(s1, s2 + 1) == 1)
		return (1);
	return (0);
}
