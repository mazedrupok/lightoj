#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main()
{
    int t, i, j, k, l, a, b, c, d, n, x, y, z;
    double p, q, r, ar[50];
    const double pi = 2.0 * acos(0.0);
    const double e = log10(exp(1.0));
    char str[100];
    ar[0] = 0;
    for (i = 1; i <= 15; i++) ar[i] = ar[i - 1] + log10(i) + 1e-9;

    scanf("%d", &t);
    getchar();
    for (i = 1; i <= t; i++)
    {
        n = 0, b = 0, gets(str);
        for (j = 0; str[j] != 0; j++)
        {
            if (isdigit(str[j])) n = n * 10 + str[j] - 48;
            else break;
        }
        j++;
        for (; str[j] != 0; j++)
        {
            if (isdigit(str[j])) b = b * 10 + str[j] - 48;
            else break;
        }
        j++;
        if (n < 15)
        {
            p = ar[n] / log10(b);
            p += 1e-9;
            d = ceil(p);
        }
        else
        {
            p = ((0.5 * log(2.0 * pi * n)) + (n * log(n)) - n) * e;
            p += 1e-9;
            p = p / log10(b);
            p += 1e-9;
            d = ceil(p);
        }
        printf("Case %d: %d\n", i, d);
    }
    return 0;
}
