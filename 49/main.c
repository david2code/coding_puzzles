#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int max_seq_len(int a[], int n)
{
	int map[1000] = {0};

	int i;
	for (i = 0; i < n; i++)
	{
		map[a[i]] = 1;
	}

	int max = 0;
	for (i = 0; i < n; i++)
	{
		int num = a[i];
		int prev;
		for (prev = num - 1; prev >= 0; prev --)
		{
			if (map[prev])
				map[num] ++;
			else
				break;
		}

		if (map[num] > max)
			max = map[num];

	}
	return max;
}

int main()
{
	int a[] = {5,100,4,200,1,3,2,7,8,9,99,13,458,11,66,10,99,12}; 

	int ret = max_seq_len(a, sizeof(a) / sizeof(int));
	printf("%d", ret);
	return 0;
}
