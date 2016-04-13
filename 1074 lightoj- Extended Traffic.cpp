#include <algorithm>
#include <bitset>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <ctime>
#include <vector>
using namespace std;
const long long INF = 2000000;
struct data{
    int from,to;
    long long int  w;
};
vector < data > edge;
int bn[205];
long long int d[205];
int ce, cv;
void bellman(int src){
    d[src]   = 0;
    long long int now;
    int from, to;
    for( int v = 1; v < cv; v++ ){
        for(int e = 0; e < ce; e++ ){
            from = edge[e].from;
            to = edge[e].to;
            now = d[from] + edge[e].w;
            if(now < d[to])
                d[to] = now;
        }
    }


      while(true){
          int e;
        for(e = 0; e < ce; e++ ){
            from = edge[e].from;
            to = edge[e].to;
            if(d[to] == -INF)continue;
            now = d[from] + edge[e].w;
            if(now < d[to]){
                d[to] = -INF;
                break;
            }
        }
        if(  e == ce)break;
    }
}
int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, query, dest, w, cs=1;
    scanf("%d", &test);
    while( test-- ){
        printf("Case %d:\n", cs++);
        scanf("%d", &cv);
        for( int v = 1; v <= cv; v++ )
            scanf("%d", &bn[v]);
        scanf("%d", &ce);
        edge = vector < data > (ce);
        for( int k = 0; k < ce; k++ ){
            scanf("%d %d", &edge[k].from, &edge[k].to);
            w = bn[ edge[k].to ]-bn[ edge[k].from ];
            edge[k].w = w*w*w;
        }
        for(int v = 1; v <= cv; v++ )
                d[v]  = INF;
        bellman(1);
        scanf("%d", &query);
        while( query > 0){
            query--;
            scanf("%d",&dest);
            if(d[dest] < 3 || d[dest] > 200000)puts("?");
            else printf("%lld\n", d[dest]);
        }
    }
	return 0;
}
