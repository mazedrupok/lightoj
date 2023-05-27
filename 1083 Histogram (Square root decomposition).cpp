// Add some code

#include <iostream>
using namespace std;

#define N 30002
#define SqrtN 175
#define LL long long
#define ULL unsigned long long
const int inf = 1e9;

int ara[N];
int sqrtSegment[SqrtN];
int n;

void buildMin() {
    for (int i = 0; i*i < n; i++) {
        sqrtSegment[i] = inf;
        int start = i * SqrtN;
        int end = start + SqrtN;
        
        sqrtSegment[i] = start;
        for (int j = start + 1; j < end && j < n; j++) {
            if (ara[j] < ara[sqrtSegment[i]])
                sqrtSegment[i] = j;
        }
    }
}

int queryMin(int start, int end) {
    int minIndex = start;

    for (int i = start; i <= end; ) {
        if (i % SqrtN == 0 && i + SqrtN <= end) {
            int index = sqrtSegment[i / SqrtN];
            if (ara[index] < ara[minIndex]) {
                minIndex = index;
            }

            i += SqrtN;
        }
        else {
            if (i <= end && ara[i] < ara[minIndex]) {
                minIndex = i;
            }
            i++;
        }
    }

    return minIndex;
}

int getArea(int start, int end) {
    if (start > end) return 0;
    if (start == end) return ara[start];
    
    int minIndex = queryMin(start, end);
    int result = ara[minIndex] * (end - start + 1);
    result = max(result, getArea(start, minIndex - 1));
    result = max(result, getArea(minIndex + 1, end));
    return result;
}

int main ()
{
    int tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        for (int i = 0; i < n; i++) scanf (" %d", &ara[i]);
        buildMin();
        LL res = getArea(0, n-1);
        printf ("Case %d: %lld\n", ++cs, res);
    }
    return 0;
}
