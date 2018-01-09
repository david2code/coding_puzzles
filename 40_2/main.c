#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

bool isInterleave(char *s1, char *s2, char *s3)
{
	bool match[100][100] = {0};

	int s1_len = strlen(s1);
	int s2_len = strlen(s2);
	int s3_len = strlen(s3);

	int i ,j,k;

	match[0][0] = true;

	if (s2[0] == s3[0])
		match[0][1] = true;
	else
		match[0][1] = false;

	if (s1[0] == s3[0])
		match[1][0] = true;
	else
		match[1][0] = false;

		for (i = 1; i <= s1_len; i++)
		{
			if (s1[i - 1] == s3[i - 1])
				match[i][0] = match[i - 1][0];
			else
				match[i][0] = false;
			printf("i %d j %d match %d\n", i, 0, match[i][0]);
		}
		for (j = 1; j <= s2_len; j++)
		{
			if (s2[j - 1] == s3[j - 1])
				match[0][j] = match[0][j - 1];
			else
				match[0][j] = false;
			printf("i %d j %d match %d\n", 0, j, match[0][j]);
		}
			

		for (i = 1; i <= s1_len; i++)
			for (j = 1; j <= s2_len; j++)
			{
				if (s2[j-1] == s3[i+j-1])
				{
					match[i][j] = match[i][j-1];
				}
				else if (s1[i-1] == s3[i+j-1])
				{
					match[i][j] = match[i-1][j];
				}
				else	
					match[i][j] = false; 
				printf("i %d j %d match %d\n", i, j, match[i][j]);
				
			}	
			
	return match[s1_len][s2_len];

}

int main()
{
	char s1[] = "aabcc";
	char s2[] = "dbbca";
	char s3[] = "aadbbcbcac";
	//char s3[] = "aadbbbaccc";

	bool ret = isInterleave(s1, s2, s3);
	printf("%d", ret);
	return 0;
}
