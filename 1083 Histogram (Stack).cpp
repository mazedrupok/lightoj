// Add some code

#include <iostream>
#include <stack>
using namespace std;

#define N 30003
#define LL long long
#define ULL unsigned long long
#define mk make_pair

int ara[N] = { 0 };
int n;

int getArea() {
    ara[n+1] = 0; // insert a min value
    stack<pair<int, int> > st;
    
    int i = 1;
    int result = 0;
    
    while(i <= n + 1) {
        if (st.empty()) {
            st.push(mk(ara[i], i));
            i++;
        }
        
        while (i < n + 1 && st.top().first <= ara[i]) {
            st.push(mk(ara[i], i));
            i++;
        }
        
        int j = 0;
        
        while (!st.empty() && st.top().first >= ara[i]) {
            j = st.top().second;
            result = max(result, st.top().first * (i - j));
            st.pop();
        }
        
        if (i < n + 1 && j > 0) {
            st.push(mk(ara[i], j));
            i++;
        }
    }
    return result;
}
int main ()
{
    int tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        for (int i = 1; i <= n; i++) scanf (" %d", &ara[i]);
        LL res = getArea();
        printf ("Case %d: %lld\n", ++cs, res);
    }
    return 0;
}
