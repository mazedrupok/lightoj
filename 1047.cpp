/**
   MMM   MMM     A     ZZZZZZZ EEEEEEE DDDDD
   MM MMM MM    AAA    Z   ZZ  EE    E DDDDDDD
   MM  M  MM   AA AA      ZZ   EEEE    DD   DD
   MM     MM  AAAAAAA   ZZ   Z EE    E DDDDDDD
   MMM   MMM AA     AA ZZZZZZZ EEEEEEE DDDDD
   
 Name:     Md. Abdul Mazed (RUPOK)
           Noakhali Science & Technology University
 Email:    mazedrupok@gmail.com || mazed4g@gmail.com
 FB id:    www.facebook.com/mazedrupok
 github:   www.github.com/mazedrupok
 problem:  
 Catagory: Dynamic Programming (Rock-Climb)
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define inf 1e9
int n, ara[22][3], dp[22][3];
int func (int i, int j) {
    if (i == n) return 0;
    int mn = inf;
    if (dp[i][j] != -1) return dp[i][j];
    for (int k = 0; k <= 2; k++) {
        if (k == j) continue;
        mn = min (mn, ara[i][j] + (dp[i+1][k] = func(i+1, k)));
    }
    return dp[i][j] = mn;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int tc, cs = 0;
	scanf (" %d", &tc);
	while (tc--) {
        memset (dp, -1, sizeof (dp));
        scanf (" %d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++) scanf (" %d", &ara[i][j]);
        int res = min (func(0,0), min(func(0,1), func(0,2)));
        printf ("Case %d: %d\n", ++cs, res);
	}
    return 0;
}
