#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int multiply(char *str_1, char *str_2)
{
	int str1_digit[100] = {0};
	int str2_digit[100] = {0};

	char *p_str = str_1;
	int str1_len = 0;
	while(*p_str != 0)
	{
		str1_digit[str1_len++] = *p_str - '0';
		p_str++;
	}
	
	p_str = str_2;
	int str2_len = 0;
	while(*p_str != 0)
	{
		str2_digit[str2_len++] = *p_str - '0';
		p_str++;
	}

	int result = 0;
	int i, j;
	int mm = 1;
	for (i = str2_len - 1; i >= 0; i--)
	{
		int sig_sum = 0;
		int nn = 1;
		for (j = str1_len - 1; j >= 0; j--)
		{
			sig_sum += (str2_digit[i] * str1_digit[j] * nn);
			nn *= 10;
			printf("dig2 %d, dig1 %d, sum %d\n", str2_digit[i], str1_digit[j], sig_sum);
		}

		result += sig_sum * mm;
		mm *= 10;	
	}
	
	printf("result %d\n", result);
	return 0;
}

int main()
{
	char str_1[] = "123698";
	char str_2[] = "15023";

	
	multiply(str_1, str_2);
	return 0;
}
