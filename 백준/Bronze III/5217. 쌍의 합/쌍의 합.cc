#include <stdio.h>

int main()
{
	int count;
	int n,i,j,k;
	scanf("%d", &count);
	for (i = 0; i < count; i++)
	{
		scanf("%d", &n);
		if (n % 2 == 0)
		{
			printf("Pairs for %d: ", n);
			for (j = 1; j < n; j++)
			{
				if (j == n - j) break;
				printf("%d %d", j, n - j); //끝에 콤마 문제 해결 ... 아직 못함 ㅠ
				if ((n - 2 * j) != 2) printf(", ");
			}
			printf("\n");
		}
		if (n % 2 != 0)
		{
			printf("Pairs for %d: ", n);
			for (k = 1; k < n; k++)
			{
				if ((2*k - n) == 1) break;
				printf("%d %d", k, n - k);
				if ((n - 2 * k) != 1) printf(", ");
			}
			printf("\n");
		}
		
	}
	
	return 0;
}
   