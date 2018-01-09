#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

bool isInterleave(char *s1, char *s2, char *s3)
{
	int s1_len = strlen(s1);
	int s2_len = strlen(s2);
	int s3_len = strlen(s3);
	
	if (s3_len != (s1_len + s2_len))
		return false;
	
	int i = 0, j = 0, k = 0;
	while(i < s1_len && j < s2_len)
	{
		if (s1[i] == s3[k])
		{
			i++;
		}
		else if (s1[j] == s3[k])
		{
			j++;
		}
		else
		{
			return false;
		}
		k++;
	}
	while(i < s1_len)
	{
		if (s1[i] == s3[k])
		{
			i++;
			k++;
		}
		else
		{
			return false;
		}
	}

	while(j < s2_len)
	{
		if (s2[j] == s3[k])
		{
			j++;k++;
		}
		else
		{
			return false;
		}
	}
	return false;

}

int main()
{
	char s1[] = "C";
	char s2[] = "CA";
	char s3[] = "CAC";

	bool ret = isInterleave(s1, s2, s3);
	printf("%d", ret);
	return 0;
}
