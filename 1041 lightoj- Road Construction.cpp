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
	sort(e.begin(),e.end());
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
			if(count==n-1) break;
		}
	}

	if (count != n-1) printf ("Impossible\n");
	else printf ("%d\n", s);
	return s;
}

int main()
{
	int n,m, tc, u, v, w, ans, cas = 0, as = 0;
	string s1, s2;
	cin >> tc;
	while (tc--) {
	cin>>m;
	map <string, int> mp;
	for (int i = 0; i < m; i++)
	{
	   cin >> s1 >> s2 >> w;
	   if (mp.find(s1) == mp.end()) mp[s1] = ++as;
	   if (mp.find(s2) == mp.end()) mp[s2] = ++as;
		edge get;
		get.u=mp[s1]; get.v=mp[s2]; get.w=w;
		e.push_back(get);
	}
	printf ("Case %d: ", ++cas);
	ans = mst (as);
	e.clear();
	as = 0;
	}
	return 0;

}
