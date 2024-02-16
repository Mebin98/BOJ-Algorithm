#include <stdio.h>

int main()
{
	int player[5][4] = { 0 };
	int sum[5] = { 0 };
	
	int i, j;
	int max = 0;
	int index = 0;

	for (i = 0; i < 5; i++)
	{
		scanf("%d %d %d %d", &player[i][0], &player[i][1], &player[i][2], &player[i][3]);
		sum[i] += (player[i][0] + player[i][1] + player[i][2] + player[i][3]);
		if (sum[i] > max)
		{
			max = sum[i];
			index = i + 1; 
		}
	}

	printf("%d %d", index, max);

	

	
	
	return 0;
}