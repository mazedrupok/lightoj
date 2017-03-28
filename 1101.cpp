#include <bits/stdc++.h>
using namespace std;
//LCA using sparse table
//Complexity: O(NlgN,lgN)
#define mx 50005
#define pb push_back
int L[mx]; //Label
int ST[mx][33]; //Sparse Table
int DT[mx][33]; //distance Table
int P[mx]; //Parent
int dis[mx]; //max edge
vector<int>g[mx];
vector<int>cost[mx];
//------------------mst-------------------
struct node {
   int u, v, w;
   node (int a, int b, int c) {u = a; v = b; w = c;}
   bool operator < (const node& p) const {return w < p.w;} //if present nodes cost is greater,
};                                                        //it means present nodes is greater..
vector <node > edge;
int par[mx];
int find(int u) {
	if(u != par[u]) par[u] = find(par[u]);
	return par[u];
}
void mst (int n) {
   sort (edge.begin(), edge.end());
   for (int i = 1; i <= n; i++) par[i] = i; //Creating disjoint set as node numbers..
   int count = 0, s = 0;
   int u, v, w;
   for (int i = 0; i < (int ) edge.size(); i++) {
      int u = find (edge[i].u); int v = find (edge[i].v);
      if (u != v) {  //checking connection & cycle..
         par[u] = v;
         count++;
         s += edge[i].w; //adding minimum edges value..
         u = edge[i].u; v = edge[i].v; w = edge[i].w;
         g[u].pb (v); g[v].pb (u);
         cost[u].pb (w); cost[v].pb (w);
         if (count == n-1) break; //node number of spanning tree is n-1..
      }
   }
   edge.clear();
   //return s;
}
//-------------------------------------------
bool seen[mx] = {0};
void dfs (int u, int parant, int label, int dist) {
    L[u] = label;
    P[u] = parant;
    dis[u] = dist;
    seen[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; int w = cost[u][i];
        if (seen[v] == 0) {
            dfs (v, u, label+1, w);
        }
    }
}
void lca_init (int n) {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 30; j++) {
            if (j == 0) {ST[i][j] = P[i]; DT[i][j] = dis[i];}
            else {ST[i][j] = -1; DT[i][j] = -1; }
        }
    for (int j = 1; (1<<j) <= n; j++) {
        for (int i = 0; i <= n; i++) {
            if (ST[i][j-1] != -1) {
                ST[i][j] = ST[ ST[i][j-1] ][j-1];
                DT[i][j] = max (DT[i][j-1], DT[ ST[i][j-1] ][j-1]);
            }
        }
    }
}
int find_lca (int u, int v) {
    if (L[u] < L[v]) swap (u, v);
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        if (L[u] - (1 << i) >= L[v]) {
            ans = max (ans, DT[u][i]);
            u = ST[u][i];
        }
    }
    if (u == v) return ans;
    for (int i = 30; i >= 0; i--) {
        if (ST[u][i] != -1 && ST[u][i] != ST[v][i]) {
            ans = max (ans, max (DT[u][i], DT[v][i]));
            u = ST[u][i]; v = ST[v][i];
        }
    }
    //return P[u];
    ans = max (ans, max (DT[u][0], DT[v][0]));
    return ans;
}
int main()
{
//   freopen ("in.txt", "r", stdin);
//   freopen ("out.txt", "w", stdout);
    int n, e, u, v, w, q, tc, cs = 0;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &e);
        for (int i = 0; i < e; i++) {
            scanf (" %d %d %d", &u, &v, &w);
            edge.pb (node(u, v, w));
        }
        mst (n);

        memset (P, -1, sizeof (P));
        memset (seen, 0, sizeof (seen));
        dfs (1, -1, 0, 0); //node starting from 1
        lca_init(n);
        printf ("Case %d:\n", ++cs);
        scanf (" %d", &q); //query
        while (q--) {
            scanf (" %d %d", &u, &v);
            printf ("%d\n", find_lca(u, v));
        }
        vector<int>tt[mx];
        vector<int> ttt[mx];
        swap (tt, g); swap (ttt, cost);
    }
    return 0;
}

