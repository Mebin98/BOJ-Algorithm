#include <stdio.h>
#include <string.h>

int main()
{
	int test; // the number of a test case
	int i;
	int index[1000];
	char str[1000][80];
	
	scanf("%d", &test);

	for (i = 0; i < test; i++) 
	{
		scanf("%d %s", &index[i], &str[i]);
		for (int j = index[i]; j <= strlen(str[i]); j++)
		{
			str[i][j - 1] = str[i][j];
		}
	}
	for (i = 0; i < test; i++)
	{
		printf("%s\n", str[i]);
	}



	return 0;
}
