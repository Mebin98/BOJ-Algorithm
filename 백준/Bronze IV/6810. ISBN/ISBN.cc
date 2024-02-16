#include <stdio.h>

int main()
{
	char number[80];
	int i;
	int total = 91;

	for (i = 0; i < 3; i++)
	{
		scanf("%d", &number[i]);
		if ((i % 2) != 0)
		{
			number[i] *= 3;
		}
		total += number[i];
	}


	printf("The 1-3-sum is %d", total);

	return 0;
}