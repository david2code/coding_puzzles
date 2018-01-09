#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int find_shortest_path(int vector[][5], int row, int col)
{
	int *the_array = (int *)malloc(sizeof(int) * col);

	the_array[0] = 0;
	int i, j;
	for (i = 0; i < row; i++)
	{
		the_array[0] = vector[i][0] + the_array[0];
		for (j = 1; j < col; j++)
		{
			if (i == 0)
			{
				the_array[j] = vector[i][j] + the_array[j - 1];
			}		
			else
			{
				the_array[j] = (the_array[j] < the_array[j - 1] ? the_array[j] : the_array[j - 1]) + vector[i][j];
			}
		}
		for (j = 0; j < col; j++)
		{
			printf("%d,", the_array[j]);
		}
		printf("\n");
	}
	printf("%d\n", the_array[col - 1]);
	return 0;
}

int main()
{
	int vector[][5] = {
		{1,3,7,5,9},
		{2,6,1,1,0},
		{8,10,55,8,8},
		{15,18,1,2,3}
	};

	
	int row = sizeof(vector) / sizeof(vector[0]);
	int col = sizeof(vector[0]) / sizeof(int);
	printf("%d %d\n", row, col);

	find_shortest_path(vector, row, col);
	return 0;
}
