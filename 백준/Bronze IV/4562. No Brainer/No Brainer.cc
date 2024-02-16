#include <stdio.h>

int main()
{
    int n,i;
    int X, Y;
    scanf("%d", &n); // input lines
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &X, &Y);
        if(X < Y) printf("NO BRAINS\n");
        if(X >= Y) printf("MMM BRAINS\n"); 
    }
    return 0;
}