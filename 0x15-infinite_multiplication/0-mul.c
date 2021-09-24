#include "holberton.h"

/**
  * main - Execution and termination of infinite multiplication program.
  * @argc: Argument Count.
  * @argv: Argument Vector.
  *
  * Return: 0 if program successful, 98 if Error.
  */
int main(int argc, char *argv[])
{
	int i, l;
	char *result;

	if (argc != 3 || _isdigit(argv[1]) != 0 || _isdigit(argv[2]) != 0)
	{
		_puts("Error\n");
		exit(98);
	}
	result = mul(argv[1], argv[2]);
	l = _strlen(result);
	l--;
	while (result[l] == '0')
		l--;
	if (l == -1)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	for (i = l; i >= 0; i--)
	{
		_putchar(result[i]);
	}
	_putchar('\n');
	free(result);
	return (0);
}

/**
 * _isdigit - Checks if passed string is a digit or not.
 * @str: String to check.
 * Skips int arg from normal isdigit & takes char string directly.
 *
 * Return: 0 for digits, 1 for non-digits.
 */
int _isdigit(char *str)
{
	int i, l;

	l = _strlen(str);
	for (i = 0; i < l; i++)
	{
		if (str[i] > '9' || str[i] < '0')
			return (1);
	}
	return (0);
}

/**
 * mul - Multiplies two positive numbers.
 * @num1: First number.
 * @num2: Second number.
 *
 * Return: Result of multiplying num1 & num2.
 */
char *mul(char *num1, char *num2)
{
	char *result;
	int c, i, j, l1, l2, n1, n2, n1_int, n2_int,  sum;

	l1 = _strlen(num1);
	l2 = _strlen(num2);
	result = malloc(sizeof(char) * (l1 + l2));
	c = 0, sum = 0, n1_int = 0, n2_int = 0;

	for (i = 0; i < (l1 + l2); i++)
		result[i] = '0';
	for (i = l1 - 1; i >= 0; i--)
	{
		c = 0, n1 = num1[i] - '0', n2_int = 0;
		for (j = l2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			if (result[n1_int + n2_int] > 9)
				result[n1_int + n2_int] -= '0';
			sum = n1 * n2 + result[n1_int + n2_int] + c;
			c = sum / 10;
			result[n1_int + n2_int] = (sum % 10) + '0';
			n2_int++;
		}
		if (c > 0)
			result[n1_int + n2_int] += c;
		n1_int++;
	}
	return (result);
}

/**
 * _puts - Writes a string to stdout up with newline appended.
 * @str: String to print.
 *
 * Return: 0 if successful, 1 on Error.
 */
int _puts(char *str)
{
	int i, l;

	l = _strlen(str);
	if (str == NULL)
		return (1);
	for (i = 0; i < l; i++)
		_putchar(str[i]);
	return (0);
}

/**
 * _strlen - Computes length of the string up to, but not including null term.
 * @str: String to check length of.
 *
 * Return: Length of string.
 */
int _strlen(char *str)
{
	int i, l = 0;

	for (i = 0; str[i]; i++)
		l++;
	return (l);
}
