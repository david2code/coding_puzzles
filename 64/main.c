#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int find_min_window_str(char *str_s, char *str_t)
{

	int expect_map[256] = {0};
	int process_map[256] = {0};

	int s_len = strlen(str_s);
	int t_len = strlen(str_t);
	
	int i;
	for (i = 0; i < t_len; i++)
	{
		expect_map[str_t[i]]++; 	
	}

	int start = 0;
	int find_num = 0;
	int min = 10000000;
	for (i = 0; i < s_len; i++)
	{
		if (expect_map[str_s[i]])
		{
				printf("i %d\n", i);
			process_map[str_s[i]]++;
			if (process_map[str_s[i]] <= expect_map[str_s[i]])
			{
				printf("i %d\n", i);
				find_num++;
				if (find_num == t_len)
				{
					while(start < i)
					{
						if (expect_map[str_s[start]])
						{
						if (process_map[str_s[start]] > expect_map[str_s[start]])
						{
							process_map[str_s[start]]--;
						}
						else
							break;
						}
						
						start++;
					}	
					if ((i - start) < min)
						min = i - start;
					printf("start %d, end %d\n", start, i);
					process_map[str_s[start]]--;
					start++;
					find_num--;
				}
				
			}
		}	
	}
	printf("min %d\n", min);
	return 0;
}

int main()
{
	char str_s[] = "AD0BECODEBANC";
	char str_t[] = "ABC";

	
	find_min_window_str(str_s, str_t);
	return 0;
}
