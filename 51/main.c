#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int max_substr(char *a, int n)
{
	int map[1000] = {0};

	int i, j;
	int max = 0;
	int start = 0;
	int x, y;

	for (i = 0; i < 1000; i++)
		map[i] = -1;
	for (i = 0; i < n; i++)
	{
		if (map[a[i]] == -1)
			map[a[i]] = i;
		else
		{
			int end = i - 1;
			int len = end - start + 1;
			if (len > max)
			{
				x = start;
				y = end;
				max = len;
			}
			while(start < end)
			{
				map[a[start++]] = -1;
			}	
			start = end + 1;

		}
	}
	int end = n - 1;
	int len = end - start + 1;
	if (len > max)
	{
		x = start;
		max = len;
	}

	char xx[100];
	strncpy(xx, a + x, max);
	xx[max] = 0;
	printf("%s\n", xx);
	return max;
}

int main()
{
	char a[] = "123654456987 abcdefgfedcba1222344";

	printf("orig: %s\n", a);
	int ret = max_substr(a, sizeof(a) - 1);
	printf("%d", ret);
	return 0;
}
