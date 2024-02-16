#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    
    if((a >= -10000) && (b <= 10000))
    {
        if (a > b) printf(">");
        if (a < b) printf("<");
        if (a == b) printf("==");
    }
    return 0;
}