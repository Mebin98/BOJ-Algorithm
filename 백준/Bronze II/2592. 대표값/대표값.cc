#include <stdio.h> 

// 출력은 잘 되는데? 
// 메모리
// 10~1000 (10의 배수) -> 100개



int main()
{
	int i;
	int average = 0; 
	int num[10];
	int mode[100] = { 0 };
	int max = 0;

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
		average += num[i];
		mode[num[i] / 10] += 1; 
	}
	average /= 10; 
	printf("%d\n", average);
	int realMax; 
	for (i = 0; i < 100; i++)
	{
		if (mode[i] > max)
		{
			max = mode[i]; 
			realMax = i * 10;
		}
	}
	printf("%d\n", realMax);



	

	
	return 0;
}