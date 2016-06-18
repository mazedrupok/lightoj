/**
 Name:     Md. Abdul Mazed (RUPOK)
           Noakhali Science & Technology University
 Email:    mazedrupok@gmail.com || mazed4g@gmail.com
 FB id:    www.facebook.com/mazedrupok
 github:   www.github.com/mazedrupok
 helpful:  http://ojsolver.blogspot.com/2016/04/uva-10566-lightoj-1062-crossed-ladders.html
 Catagory: Binary Search & same angle triangle geometry
*/
#include <bits//stdc++.h>
using namespace std;
#define MX 100005
#define read(f)  freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdout)
#define LL long long
#define ULL unsigned long long
#define inf        INT_MAX
#define mod        1000000007
#define PI         acos(-1.0)
#define set0(ar)   memset(ar,0,sizeof ar)
#define set1(ar)   memset(ar,1,sizeof ar)
#define setneg(a)  memset(a,-1,sizeof(a))
#define setinf(ar) memset(ar,126,sizeof ar)
template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

double x, y, c;
double bin_ser (double lo, double hi) {
    int cnt = 100;
    double wide;
    while (cnt--) {
        wide = (lo+hi) /2;
        double h1 = sqrt (x*x - wide*wide);
        double h2 = sqrt (y*y - wide*wide);
        double test = (h1*h2) / (h1+h2);
        if (test <= c) hi = wide;
        else lo = wide;
    }
    return wide = (lo+hi) /2;
}
int main ()
{
    int tc, cs = 0;
    cin >> tc;
    while (tc--) {
        cin >> x >> y >> c;
        printf ("Case %d: %.10lf\n", ++cs, bin_ser(0, min(x, y)));
    }
    return 0;
}
