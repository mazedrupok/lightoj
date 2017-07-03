#include <bits/stdc++.h>
#define ll long long
#define sc(N) scanf (" %d", &N)
#define scc(N) scanf (" %c", &N)
#define scs(N) scanf (" %s", N)
#define For(i,N) for (int i = 0; i < N; i++)
#define pb push_back
#define mk make_pair
#define pr pair<int,int>
#define ff first
#define ss second
using namespace std;
 
const int N = 205;
const int inf = 10000000;
int dx4[]={0,0,-1,1}; int dy4[]={1,-1,0,0}; //4 direction
bool vis[2][N][N];
char str[N][N];
int r, c;
pr D, P;
vector <pr> port;
int check(pr T)
{
    int x = T.ff; int y = T.ss;
    if(x < 0 || x >= r || y < 0 || y >= c) return 1;
    if(str[x][y] == '#' || vis[0][x][y]) return 1;
    return 0;
}
int bfs()
{
    queue<pair<pr, pr> >q;
    q.push (mk(P, mk(0,0)));
    memset(vis, 0, sizeof (vis));
    vis[0][P.ff][P.ss] = 1;
 
    while(!q.empty())
    {
        pr u = q.front().ff;
        int step = q.front().ss.ff;
        int k = q.front().ss.ss;
        q.pop();
        if(u == D) return step;
 
        if(str[u.ff][u.ss] == '*') {
            int flag=0;
            For (i, port.size()) {
                pr v = port[i];
                if(v == u) { flag = 1; continue; }
                if(!vis[1][v.ff][v.ss]) {
                    vis[1][v.ff][v.ss] = 1;
                    q.push(mk(v, mk(step+1, 1)));
                }
            }
            if(flag) { port.clear(); port.pb (u); }
            if(k == 0) continue;
        }
        For (i, 4) {
            pr v;
            v.ff = u.ff + dx4[i];
            v.ss = u.ss + dy4[i];
            if(check(v)) continue;
            vis[0][v.ff][v.ss] = 1;
            q.push(mk(v, mk(step+1, 0)));
        }
    }
    return -1;
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, i, j;
    int cs = 0;
    sc (tc);
    while(tc--)
    {
        port.clear();
        sc (r); sc (c);
        For (i, r)
        For (j, c) {
            scc (str[i][j]);
            if(str[i][j]=='P') P = mk (i, j);
            else if(str[i][j]=='D') D = mk (i, j);
            else if(str[i][j]=='*') port.pb (mk(i, j));
        }
//        For (i, r) {
//            For (j, c) {
//                cout << str[i][j];
//            } cout << endl;
//        }
        printf("Case %d: ", ++cs);
        int ret = bfs ();
        if(ret == -1) printf("impossible\n");
        else printf ("%d\n", ret);
    }
    return 0;
}
