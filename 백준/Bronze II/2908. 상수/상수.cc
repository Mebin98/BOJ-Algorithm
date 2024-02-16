#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num[2];
	int hundred[2];
	int ten[2];
	int one[2];
	int ans[2];

	scanf("%d %d", &num[0], &num[1]);

	for (int i = 0; i < 2; i++)
	{
		hundred[i] = num[i] / 100;
		ten[i] = (num[i] - (hundred[i] * 100)) / 10;
		one[i] = (num[i] - (hundred[i] * 100) - (ten[i] * 10));
		ans[i] = (one[i] * 100) + (ten[i] * 10) + (hundred[i]);
	}

	if (ans[0] > ans[1])
	{
		printf("%d", ans[0]);
	}
	else if (ans[1] > ans[0])
	{
		printf("%d", ans[1]);
	}
	else
	{
		return -1;
	}

	


	return 0;
}