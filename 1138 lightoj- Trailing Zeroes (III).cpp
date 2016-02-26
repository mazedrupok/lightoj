/*
    Md. Abdul Mazed
    Noakhali Science & Technology University
    mazed4g@gmail.com
    http://www.facebook.com/mazedrupok/bd
    github.com/mazedrupok
    problem category: Binary Search, Number Theory
        :) :) :)
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
int n,m;
int numOfZero(int u) {
    int i, t, res;
    for(res=0,i=5;i<=u;i*=5)
        res+=u/i;
    return res;
}
int fen() {
     int x = 0, y = INF;
     while(x <= y) {
         m = (x+y) >> 1;
         if(numOfZero(m)>n) y=m-1;
         else x=m+1;
     }
     y -= y%5;
     if(numOfZero(y) == n)return y;
     return -1;
}
int main()
{
    int k, kk, t;
    scanf(" %d", &k);
    kk=0;
    while(k--) {
        scanf(" %d",&n);
        printf("Case %d: ",++kk);
        t=fen();
        if(t!=-1) printf("%d\n",t);
        else printf("impossible\n");
    }
    return 0;
}
