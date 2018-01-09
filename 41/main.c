#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

bool canjump(int a[], int n)
{
	int prev_max_jmp = 0;
	int max_jmp = 0;

	int i;
	for (i = 0; i < n; i++)
	{
		max_jmp = a[i] > prev_max_jmp ? a[i] : prev_max_jmp;
		printf("i %d max_jmp %d\n", i, max_jmp);
		if (max_jmp <= 0)
			return false;
		else if (max_jmp >= (n - i))
			return true;	

		prev_max_jmp = max_jmp - 1;
	}
	return false;
}

int main()
{
	//int a[] = {2,3,1,1,4}; 
	int a[] = {3,2,1,0,4}; 

	bool ret = canjump(a, sizeof(a) / sizeof(int));
	printf("%d", ret);
	return 0;
}
