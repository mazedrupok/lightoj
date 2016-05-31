/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok
   Category: Computational Geometry & binary Search.
   Problem link: http://lightoj.com/volume_showproblem.php?problem=1137
   Comment:
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 10005
#define PI acos(-1.0)
#define read(f) freopen(f, "r", stdin)
#define write(f) freopen(f, "w", stdout)
typedef long long LL;

int main ()
{
   int tc, cs = 0;
   double L, _L, n, c, theta, r, arc, x;
   cin >> tc;
   while (tc--) {
      cin >> L >> n >> c;
      _L = (1 + n*c) * L;
      double hi = PI, lo = 0.0; theta = (lo+hi) /2.0;
      int cnn = 100;
      while (cnn--) {
         //sin(theta) = (L/2) / r = Orthogonal/Hypotenuse;
         r = (L/2) / sin(theta);
         arc = r*theta;  //S = r*theta;
         if (arc < _L/2) lo = theta;
         else hi = theta;
         theta = (lo+hi) /2.0;
      }
      r = (L/2) / sin(theta);
      x = cos(theta) * r; //cos(theta) = x / r;
      printf ("Case %d: %.10lf\n", ++cs, r-x);
   }
   return 0;
}
