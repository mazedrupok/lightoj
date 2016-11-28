#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define gama 0.57721566490
double a[1000005];
int main()
{
    int tc, cs = 0, n, x;
	double res, k;
	a[0] = 0.0;
	for (int i = 1; i <= 1000000; i++) {
		a[i] += a[i-1] + (1.0/i);
	}
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &x);
		if(x <= 1000000) {
			printf("Case %d: %.10f\n", ++cs, a[x]);
		}
		else {
			k = x + .5;
			res = log(k) + gama; //other part less 10^-8
                                //so no need to calculate
			printf("Case %d: %.10f\n", ++cs, res);
		}
	}
}
