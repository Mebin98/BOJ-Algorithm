#include <stdio.h>

int main()
{
    int number,i;
    scanf("%d", &number);
    for(i = 0; i < number; i++)
    {
        printf("%d\n", number - i);
    }
    return 0;
}