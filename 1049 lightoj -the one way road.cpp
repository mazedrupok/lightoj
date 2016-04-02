#include <bits//stdc++.h>
using namespace std;

#define SIZE 105
#define MOD 20071027

#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

using namespace std;

int row, column, n;

bool Left[SIZE];
bool Right[SIZE];

int weightLeft;
int weightRight;

int main()
{
	int tc, t = 0, i, j, k, m, x, y, z, a, b, c, value, l;
	unsigned d, mx;
	char ch;
	bool flag;

	//freopen("input.txt", "r", stdin);
	scanf("%d", &tc);

	for(t = 1; t <= tc; t++)
	{
		scanf("%d", &n);
		memset(Left, 0, sizeof Left);
		memset(Right, 0, sizeof Right);

		weightLeft = weightRight = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			/* If left of a, and right of b empty, then place b to the left of a (b <-- a) */
			if(!Left[a] && !Right[b])
			{
				Left[a] = Right[b] = true;
				weightLeft += c;
			}
			/* Otherwise place b to the right of a (a --> b) */
			else
			{
				Right[a] = Left[b] = true;
				weightRight += c;
			}
		}

		printf("Case %d: %d\n", t, min(weightLeft, weightRight));
	}

	return 0;
}
