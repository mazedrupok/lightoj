#include <bits/stdc++.h>
#define SIZE 55

using namespace std;

int my[SIZE];
int opt[SIZE];
int points[SIZE][SIZE];

bool compare(const int &i, const int &j) {
	return i > j; //large to small
}

int max(int a, int b, int c) {
	if(a >= b && a >= c) return a;
	else if(b >= a && b >= c) return b;
	else return c;
}

int main()
{
	int N, tc;
	scanf("%d", &tc);

	for(int i = 0; i < tc; i++) {
		scanf("%d", &N);
		for(int j = 0; j < N; j++) scanf("%d", &my[j]);
		for(int j = 0; j < N; j++) scanf("%d", &opt[j]);

		sort(my, my + N, compare);
		sort(opt, opt + N, compare);

		for(int j = 0; j <= N; j++)
			points[j][0] = points[0][j] = 0;

		int point;
		for(int j = 1; j <= N; j++)
			for(int k = 1; k <= N; k++) {
				if(my[j - 1] > opt[k - 1]) point = 2;
				else if(my[j - 1] == opt[k - 1]) point = 1;
				else point = 0;

				points[j][k] = max(points[j-1][k], points[j][k - 1], points[j - 1][k - 1] + point);
			}

		cout << "Case " << i + 1 << ": " << points[N][N] << endl;
	}

	return 0;
}
