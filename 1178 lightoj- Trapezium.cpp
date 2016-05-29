/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok
   Category:
   Problem link:
   Comment:
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 10005
#define read(f) freopen(f, "r", stdin)
#define write(f) freopen(f, "w", stdout)
typedef long long LL;
double sq (double a) {return a*a;}
int main ()
{
   int tc, cs = 0;
   double a, b, c, d, h, area, x, s, t_area;
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %lf %lf %lf %lf", &a, &b, &c, &d);
      x = fabs (a-c);
      s = .5 * (x + b + d); //Surface of Triangle
      t_area = sqrt (s * (s-b) * (s-d) * (s-x)); //Triangle area
      h = (2 * t_area) /x; //area = .5 * base * hight
      area = .5 * (a+c) * h;
      printf ("Case %d: %.7lf\n", ++cs, area);
   }
   return 0;
}

