#include <stdio.h>

int main()
{
    int i;
    char number[10];
    for(i = 0; i < 2; i++)
    {
        scanf("%d", &number[i]);
    }
    printf("%d", number[0] + number[1]);
    return 0;
}