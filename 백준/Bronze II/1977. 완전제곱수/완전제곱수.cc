#include <iostream>
#include <cmath>

int main()
{
    int x,y;
    int sum = 0;
    double sq_num;
    int int_num;
    int min = 10001;
    std::cin >> x >> y;

    for (int i = x; i <= y; i++)
    {
        sq_num = sqrt(i);
        int_num = sqrt(i);
        if (sq_num - int_num == 0)
        {
            sum += i;
            if (i < min)
            {
                min = i;
            }
        }
    }

    if (sum == 0 && min == 10001)
    {
        std::cout << -1 << std :: endl;
        return 0;
    }

    std::cout << sum << std::endl;
    std::cout << min << std::endl;

    return 0;
}