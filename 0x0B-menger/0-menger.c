#include "menger.h"

/**
 * menger - Draws a 2d Menger Sponge
 * @level: Level of the Menger Sponge to draw
 * If level is lower than 0, function does nothing.
 */
void menger(int level)
{
	int i = 0, j = 0, o = 1;
	int size = pow(3, level);
	char conprin;

	if (level == 0)
		printf("#\n");
	if (level == 1)
		printf("###\n# #\n###\n");
	if (level > 1)
	{
		for (; i < size; i++)
		{
			for (; j < size; j++)
			{
				conprin = '#';
				for (o = 1; o < size; o *= 3)
				{
					if ((i / o) % 3 == 1 && (j / o) % 3 == 1)
					{
						conprin = ' ';
					}
				}
				printf("%c", conprin);
			}
			printf("\n");
		}
	}
}
