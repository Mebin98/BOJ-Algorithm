#include <stdio.h>

int main()
{
	int first, second, third;
	int diff;
    scanf("%d", &third);
	scanf("%d", &second);

	diff = second - third;
	first = second + diff;
	printf("%d", first);

	return 0;
}
