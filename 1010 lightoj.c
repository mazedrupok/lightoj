#include<stdio.h>
int mn1(int m,int n);
int main()
{
   int m, n, s, j=1, r;
   long int t;
   scanf(" %ld", &t);
   if(t <= 41000)
      while(t--)
      {
         scanf("%d %d", &m, &n);
         if(m > 200 || n > 200)
            break;
         if(m == 1)
            r = n;
         else if(n == 1)
            r = m;
         else if(m == 2 && n == 2)
            r = 4;
         else if(m == 2 && n > 2)
            r = mn1(m, n);
         else if(n == 2 && m > 2)
            r = mn1(n, m);
         else if(m %2 != 0 && n %2 != 0)
            r = ((m*n) + 1) / 2;
         else
            r = (m*n) / 2;

         printf("Case %d: %d\n", j, r);
         j++;
      }
   return 0;
}
int mn1(int m, int n)
{
   int r, s;
   if(n %2 == 0){
      s = n/2;
   if(s %2 == 0)
      r = s*2;
   else
      r = (s+1)*2;
   }
   else
      r = n+1;
   return r;

}

