#include <cstdio>
//#include <algorithm>
#include <cstring> //used for memset.
#include <iostream>
//#include <cmath>
//#include <string>
//#include <map>
//#include <list>
//#include <queue>
//#include <utility>
using namespace std;
bool visited[50][50];
char str[50][50];
int r, c, n;
void dfs (int p, int q) {
   if (p+1 < r) //p & q cant cross broader. for one node there is four adjacent.
   if (str[p+1][q] == '.' && !visited[p+1][q]) {
      n++;
      visited[p+1][q] = true;
      dfs (p+1, q);
   }
   if (p-1 >= 0)
   if (str[p-1][q] == '.' && !visited[p-1][q]) {
      n++;
      visited[p-1][q] = true;
      dfs(p-1, q);
   }
   if (q+1 < c)
   if (str[p][q+1] == '.' && !visited[p][q+1]) {
      n++;
      visited[p][q+1] = true;
      dfs(p, q+1);
   }
   if (q-1 >= 0)
   if (str[p][q-1] == '.' && !visited[p][q-1]) {
      n++;
      visited[p][q-1] = true;
      dfs(p, q-1);
   }
}
int main () {
   int cas, k, i, j, x, y;
   char temp;
   //freopen ("in.txt", "r", stdin);
   scanf (" %d", &cas);
   for (k = 1; k <= cas; k++) {
      scanf (" %d %d", &c, &r);  //1st colomn then row inputed.
      memset (visited, 0, sizeof(visited)); // set all not visited.
      memset(str, ' ', sizeof(str)); //Set different value, because previous case value remain
      for (i = 0; i < r; i++) {
         for (j = 0; j < c; j++) {
            scanf (" %c", &str[i][j]);
            if (str[i][j] == '@') {x = i; y = j;} //taking initial position
         }
      }
      n = 1;
      visited[x][y] = true; //true node wont be consider for further recurrance
      dfs(x, y);
      printf ("Case %d: %d\n", k, n);
      n = 0;
   }
}
