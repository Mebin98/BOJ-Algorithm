#include <stdio.h>


int main()
{
    char sum[80];
    int i, total = 0;
    
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &sum[i]);
        total += sum[i];
    }
    printf("%d", total);
    
    return 0;
}