#include <stdio.h>

int main()
{
    int i,j,temp;
    int n[50];
    scanf("%d %d %d", &n[0], &n[1], &n[2]);
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            if(n[j] > n[j + 1])
            {
                temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }
    }
    printf("%d %d %d\n", n[0], n[1], n[2]);
    return 0; 
}