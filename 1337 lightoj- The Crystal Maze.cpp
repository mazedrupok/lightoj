#include <bits/stdc++.h>
using namespace std;
int cnt, row, col;
char s[501][501];
int p[501][501];
int visit[501][501];
void DFS (int r, int c) {
   if (r < 0 || r >= row) return;
   if (c < 0 || c >= col) return;
   if (visit[r][c] == 1) return;
   visit[r][c] = 1;
   if (s[r][c] == '#') return;
   if (s[r][c] == 'C') cnt++;
   DFS (r+1, c);
   DFS (r-1, c);
   DFS (r, c+1);
   DFS (r, c-1);
}
void setvalue (int r, int c) {
   if (r < 0 || r >= row) return;
   if (c < 0 || c >= col) return;
   if (visit[r][c] == 1) return;
   visit[r][c] = 1;
   if (s[r][c] == '#') {p[r][c] = 0; return;}

   p[r][c] = cnt;

   setvalue (r+1, c);
   setvalue (r-1, c);
   setvalue (r, c+1);
   setvalue (r, c-1);
}
int main ()
{
   int q, tc, cas = 0, x, y;
   //freopen ("in.txt", "r", stdin);
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d %d %d", &row, &col, &q);
      for (int i = 0; i < row; i++)
         for (int j = 0; j < col; j++) scanf(" %c", &s[i][j]);
      for (int i = 0; i < row; i++)
         for (int j = 0; j < col; j++) p[i][j] = -1;

      printf ("Case %d:\n", ++cas);
      while (q--) {
         scanf (" %d %d", &x, &y);

         if (p[x-1][y-1] != -1) printf ("%d\n", p[x-1][y-1]);
         else {
            cnt = 0;
            for (int i = 0; i < row; i++)
               for (int j = 0; j < col; j++) visit[i][j] = 0;

            DFS (x-1, y-1);
            for (int i = 0; i < row; i++)
               for (int j = 0; j < col; j++) visit[i][j] = 0;

            setvalue (x-1, y-1);
            printf ("%d\n", p[x-1][y-1]);
         }
      }
   }
   return 0;
}
