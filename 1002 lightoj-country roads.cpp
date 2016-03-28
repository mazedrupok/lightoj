#include <bits/stdc++.h>

#define MAXX 505
#define INF 1e9
using namespace std;

int weight[MAXX][MAXX];
vector<int>G[MAXX];
int dis[MAXX];

struct DATA{
    int city, dist;
    bool operator < (const DATA &p) const {
      return p.dist > dist;
    }
};


void dijkstra(int src)
{
    int len;
    priority_queue<DATA >Q;
    DATA u, v;
    u.city = src;
    u.dist = 0;

   dis[u.city] = 0;

    Q.push(u);
    while(!Q.empty()) {
        u = Q.top(); Q.pop();
        if(u.dist != dis[u.city]) continue;

        len = G[u.city].size();
        for (int i = 0; i < len; i++) {
            v.city = G[u.city][i]; //u G connected with v..
            v.dist = max(u.dist, weight[u.city][v.city]);
            if(v.dist < dis[v.city]) {
                dis[v.city] = v.dist;
                Q.push(v);
            }
        }

    }
}

int main()
{
    int tc, cas = 0;
    int cities, roads;
    scanf (" %d", &tc);
    int p, q, w;
    int src;

    while(tc--) {
        for (int i = 0; i < MAXX; i++) {
            G[i].clear();
            dis[i] = INF;
            for (int j = 0; j < MAXX; j++) {
                weight[i][j] = INF;
                weight[j][i] = INF;
            }
        }

        scanf (" %d %d", &cities, &roads);
        for (int i = 0; i < roads; i++) {
            scanf (" %d %d %d", &p, &q, &w);
            if(w < weight[p][q]) {
                weight[p][q] = w;
                weight[q][p] = w;
                G[p].push_back(q);
                G[q].push_back(p);
            }
        }

        scanf (" %d", &src);
        dijkstra(src);

        printf("Case %d:\n", ++cas);

        for (int i = 0; i < cities; i++) {
            if(dis[i] == INF)
                printf("Impossible\n");
            else
                printf("%d\n", dis[i]);
        }

    }

    return 0;
}
