#include <bits/stdc++.h>
using namespace std;
#define MAXN 20005
vector <int> g[MAXN];
vector <int> articulation_points;
vector <pair<int, int> > articulation_edges;
vector <pair<int, int> > res;
int timer = 1, start[MAXN], low[MAXN];

void dfs(int u, int P){
    bool flag=0;
    int child=0;
    start[u] = timer;
    low[u] = timer;
    timer++;
    for (int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if (v == P) continue;
        if(start[v] == 0) { //working as visited array
            dfs(v, u);
            if (low[v] > start[u])
                articulation_edges.push_back (make_pair (u, v));
            ++child;
            low[u] = min(low[u], low[v]);
            if (low[v] >= start[u]) flag = true;
        }
        else low[u] = min(low[u], start[v]);
    }
    if((u==1 && child > 1) || (u != 1 && flag))
        articulation_points.push_back(u); //u is an AP.
}

int main() {
	int n, m, u, v, tc, cs = 0;
	scanf (" %d", &tc);
	while (tc--) {
        scanf (" %d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf (" %d %d", &u, &v);
            g[u].push_back (v);
            g[v].push_back (u);
        }
        memset (start, 0, sizeof (start));
        timer = 1;
        dfs (1, -1);  //strongly connected
    	printf ("Case %d: %d\n", ++cs, articulation_points.size());

	//clear section
        vector <int> tt[MAXN]; swap (tt, g);
        articulation_edges.clear();
        articulation_points.clear();
	}
}
