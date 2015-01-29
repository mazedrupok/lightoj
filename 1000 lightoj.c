       #include <stdio.h>

       int main()
       {
          int tc;
          scanf("%d", &tc);
          int i, a, b;
          for (i = 1; i <= tc; ++i) {
             scanf("%d %d", &a, &b);
             printf("Case %d: %d\n", i, a+b);
          }
          return 0;
       }

