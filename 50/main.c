#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int max_pali(char *a, int n)
{
	int max_len[100][100] = {0};

	int i, j;
	int max = 0;
	int start, end;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (i == j)
			{
				max_len[j][i] = 1;
			}
			else if (a[i] == a[j])
			{
				if (j == (i - 1))
					max_len[j][i] = 2;
				else
					max_len[j][i] = max_len[j+1][i-1] + 2;
			}
			if (max_len[j][i] > max)
			{
				start = j;
				end = i;
				max = max_len[j][i];
			}
		}
	}

	char xx[100];
	strncpy(xx, a + start, end - start + 1);
	xx[end-start+1] = 0;
	printf("%s\n", xx);
	return max;
}

int main()
{
	char a[] = "123654456987 abcdefgfedcba1222344";

	int ret = max_pali(a, sizeof(a) - 1);
	printf("%d", ret);
	return 0;
}
