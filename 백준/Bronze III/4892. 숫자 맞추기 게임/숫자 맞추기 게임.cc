#include <stdio.h>

int main()
{
	int n0, n1, n2, n3, n4;
	int count = 1;
	while (1)
	{
		scanf("%d", &n0);
		if (n0 == 0) break;
		n1 = 3 * n0;
		if (n1 % 2 == 0)
		{
			n2 = n1 / 2;
			n3 = 3 * n2;
			n4 = n3 / 9;
			printf("%d. even %d\n", count, n4);
			count++;
		}
		if (n1 % 2 != 0)
		{
			n2 = (n1 + 1) / 2;
			n3 = 3 * n2;
			n4 = n3 / 9;
			printf("%d. odd %d\n", count, n4);
			count++;
		}
    }
		
	return 0;
}