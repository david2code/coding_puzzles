#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int jump(int a[], int n)
{
	if (n <= 1)
		return 0;
	int start = 0;
	int end = 0;

	int count = 0;
	while(end < n)
	{
		int pos;
		int max_index = end;
		count++;
		for (pos = start; pos <= end; pos++)
		{
			int far_index = a[pos] + pos;
			if (far_index >= (n - 1))
				return count;

			if (far_index > max_index)
				max_index = far_index;
		}
		if (max_index == end)
			return 0;

		start = end + 1;
		end = max_index;
		printf("start %d, end %d\n", start, end);

	}

	return 0;
}

int main()
{
	//int a[] = {2,3,1,1,4}; 
	int a[] = {3,2,1,0,4}; 

	int ret = jump(a, sizeof(a) / sizeof(int));
	printf("%d", ret);
	return 0;
}
