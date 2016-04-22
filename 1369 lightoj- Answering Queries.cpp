#include <bits/stdc++.h>
using namespace std;
long long f(vector<int> &vc, int n) {
	int i;
	long long res=0;
	for(i = 0; i < n; i++)
		res += ((long long) n-1 - 2*i) * vc[i];
	return res;
}

int main()
{
	int tc, cs = 0;
	scanf(" %d", &tc);
	while (tc--) {
		int n, q;
		scanf(" %d %d", &n, &q);
		vector<int> vc(n);
		int j;
		for(j = 0; j < n; j++) scanf(" %d", &vc[j]);

		long long res = f(vc, n);

		printf("Case %d:\n", ++cs);
		while (q--) {
			int t;
			scanf(" %d", &t);

			if(t == 1) printf("%lld\n", res);
			else {
				int x,v;
				scanf(" %d %d", &x, &v);
				res += ((long long) n-1 - 2*x) * (v-vc[x]);
				vc[x] = v;
			}
		}
	}
	return 0;
}
/*
  for an array,
   1 3 6 5 9
   0th element added      4 times or, (n-1 - 2 X 0) times
   1th element added      2 times or, (n-1 - 2 X 1) times
   2nd element added      0 times or, (n-1 - 2 X 2) times
   3rd element subtracted 2 times or, (n-1 - 2 X 3) times
   4th element subtracted 4 times or, (n-1 - 2 X 4) times
*/
