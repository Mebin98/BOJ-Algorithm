#include <stdio.h>



int main()
{
	int in, out; 
	int sum = 0;
	int record[10];
	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d %d", &out, &in);
		sum += in;
		sum -= out;
		record[i] = sum;
		if (record[i] > max)
		{
			max = record[i];
		}
	}

	printf("%d", max);




	return 0;
}
