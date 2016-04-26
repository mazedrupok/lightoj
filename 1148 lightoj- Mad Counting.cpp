#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int tc, cs = 0, i, j, k, n, a[50], res;
	scanf(" %d", &tc);
	while (tc--) {
		scanf(" %d", &n);
		for(i = 0; i < n; i++) scanf(" %d", &a[i]);
		sort(a, a + n);
		for(i = res = 0; i < n; i++) {
			for(j = i; j < n && a[j] == a[i]; j++);
			k = j - i; //counting more same.
			res += ((k + a[i]) / (a[i] + 1)) * (a[i] + 1);
			i = j - 1;
		}
		printf("Case %d: %d\n", ++cs, res);
	}
	return 0;
}
