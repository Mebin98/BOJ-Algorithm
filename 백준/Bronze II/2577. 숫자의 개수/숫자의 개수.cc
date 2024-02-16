#include <stdio.h>




int ten(int);

int main()
{
	int nat[3];
	int i;
	int num;
	int arr[100];
	
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &nat[i]);
	}

	num = nat[0] * nat[1] * nat[2];

	int cnt = 1;
	int index = 0; // index 이면 1자리 수, 2이면 2자리 수
	while ((num / cnt) >= 1)
	{
		cnt *= 10;
		index++;
	} // no problem 

	
	/*
		pseudo code
		arr[i] = num / ten(index)
		num = num - (arr[i]*ten(index))
		index --;
		i++;
		arr[i] = (num - (arr[0]*ten(index))) / ten(index)
	*/ 
	i = 0;
	while (1)
	{
		arr[i] = num / ten(index);
		num = num - (arr[i] * ten(index));
		if (ten(index) == 1)
		{
			break; 
		}
		index--;
		i++;	
	}


	int final[10] = {0};

	for (int j = 0; j <= i; j++)
	{
		final[arr[j]] += 1;
	}

	
	for (i = 0; i < 10; i++)
	{
		printf("%d\n" ,final[i]);
	}


	return 0;
}


int ten(int num)
{
	int size = 1;

	for (int i = 0; i < num - 1; i++)
	{
		size *= 10;
	}
	return size;
}