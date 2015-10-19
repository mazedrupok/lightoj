#include <stdio.h>
#include <string.h>
char str[1000100];
char substr[1000100];
int b[1000100];
void kmpPre(char *substr)
{
   const int m = strlen(substr);
   int i = 0, j = -1;
   b[i] = -1;
   while(i < m)
   {
      while(j >= 0 && substr[i] != substr[j])
         j = b[j];
      i++;
      j++;
      b[i] = j;
   }
}
int kmp(char *str, char *substr)
{
   int i = 0, j = 0, count = 0;
   const int n = strlen (str);
   const int m = strlen (substr);
   kmpPre (substr);
   while (i < n)
   {
      while (j>=0 && str[i] != substr[j])
         j=b[j];
      i++;
      j++;
      if (j==m)
      {
         count++;
         j=b[j];
      }
   }
   return count;
}
int main()
{
   int cas, k, n;
   scanf("%d", &cas);
   for (k = 1; k <= cas; k++)
   {
      scanf (" %d", &n);
      scanf(" %s", str);
      printf ("Case %d:\n", k);
      while (n--) {
         scanf (" %s", substr);
         printf("%d\n", k, kmp(str, substr));
      }
   }
   return 0;
}
