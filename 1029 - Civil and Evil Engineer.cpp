#include <bits//stdc++.h>
using namespace std;
struct edge
{
	int u,v,w;
	bool operator < ( const edge& p ) const
	{
		return w < p.w;
	}
};
int pr[105];
vector<edge>e;
int find(int r)
{
   return (pr[r]==r) ? r:  find(pr[r]);
}
int mst(int n)
{
	for(int i=0;i<=n;i++)pr[i]=i;
	//sort(e.begin(),e.end());
	int count=0,s=0;
	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		
		if(u!=v)
		{
			pr[u]=v;
			count++;
			s+=e[i].w;
			if(count==n) break;
		}
	}
	return s;
}

int main(){
//	READ("in");
	int n,m, tc, u, v, w, ans, cas = 0;
	cin >> tc;
	while (tc--) {
	cin>>n;
	while (cin >> u >> v >> w)
	{
	   if (!u && !v && !w) break;
		edge get;
		get.u=u; get.v=v; get.w=w;
		e.push_back(get);
	}
	sort(e.begin(),e.end());
	ans = mst (n);
	reverse (e.begin(), e.end());
	ans += mst (n);
	if (ans %2 == 0) printf ("Case %d: %d\n", ++cas, ans/2);
	else printf ("Case %d: %d/2\n", ++cas, ans);
	e.clear();
	}
	return 0;

}
