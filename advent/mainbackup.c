#include "lists.h"

/**
 *  * main - check the code for Holberton School students.
 *   *
 *    * Return: Always 0.
 *     */
int main(void)
{
	int cur, prev = 0, total_pos = 0;
	FILE *fptr = fopen("list.txt", "r");
	char dataToBeRead[50];

	if (!fptr)
	{
		printf("bad file!\n");
		exit(-1);
	}
	else
	{
		while(fgets(dataToBeRead, 50, ftpr) != NULL)
		{
			printf("%s", dataToBeRead);
			cur = atoi(dataToBeRead);
			if (cur > prev && prev != 0)
				total_pos++;
			else if (prev == 0)
			{
				prev = cur;
				continue;
			}
			else
				continue;
		}
		printf("Total number of increases: %i\n", total_pos);
	}
	return (0);
}
