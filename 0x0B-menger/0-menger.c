#include "menger.h"

/**
 * menger - Draws a 2d Menger Sponge
 * @level: Level of the Menger Sponge to draw
 * If level is lower than 0, function does nothing.
 */
void menger(int level)
{
	int i, j, o;
	int size = pow(3, level);
	char print;

	if (level == 0)
		printf("#\n");
	if (level == 1)
		printf("###\n# #\n###\n");
	if (level > 1)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				print = '#';
				for (o = 1; o < size; o *= 3)
				{
					if ((i / o) % 3 == 1 && (j / o) % 3 == 1)
						print = ' ';
				}
				printf("%c", print);
			}
			printf("\n");
		}
	}
}
