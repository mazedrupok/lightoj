#include <bits/stdc++.h>
#define MAXN 205
#define mk make_pair
#define pb push_back
using namespace std;
int pr[MAXN], rank[MAXN];
set <pair<int, pair<int,int> > > e;

int find(int x){
    return pr[x] = (pr[x] == x ? x : find(pr[x]));
}
void unionByRank (int p, int q) {
    p = find (p);
    q = find (q);
    if (rank[p] < rank[q]) pr[p] = q;
    else pr[q] = p;
    if (rank[p] == rank[q]) rank[p]++;
}
int mst (int n) {
    for (int i = 1; i <= n; i++) {pr[i] = i; rank[i] = 0;}
    set <pair<int, pair<int,int> > > :: iterator it;
    set <pair<int, pair<int,int> > > temp;
    int cnt_edge = 0, path_cost = 0;
    for (it = e.begin(); it != e.end(); it++) {
        int w = (*it).first;
        int u = (*it).second.first;
        int v = (*it).second.second;
        u = find(u);
        v = find(v);
        if (u != v) {
            unionByRank (u, v);
            path_cost += w;
            temp.insert (mk(w, mk(u, v)));
            cnt_edge++;
        }
        if (cnt_edge == n-1) {
            e = temp;
            return path_cost;
        }
    }
    return -1;
}
int main()
{
    int n, m, tc, cs = 0;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d", &n, &m);
        printf("Case %d:\n", ++cs);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            e.insert (mk(w, mk(u, v)));
            printf("%d\n", mst(n));
        }
        e.clear();
    }
    return 0;
}

