/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok

   Catagory: Ternary Search Algorithm.
   Comment:
*/
#include <bits/stdc++.h>
using namespace std;
#define abs_err 0.0000001

struct point {
   double x;
   double y;
   double z;
};
point pp[3];
double sq (double a) {return a*a;}
double point_dis (point a, point b) {
   double tem = sq(a.x-b.x) + sq(a.y-b.y) + sq(a.z-b.z);
   return sqrt (tem);
}

double TS () {
   double one3, two3;
   int cn = 100;
   while (cn--) {
      point fa, la; //fa is 1st one-third, la is 2nd one-third.
      fa.x = (2*pp[0].x + pp[1].x) /3.0;
      fa.y = (2*pp[0].y + pp[1].y) /3.0;
      fa.z = (2*pp[0].z + pp[1].z) /3.0;

      la.x = (pp[0].x + 2*pp[1].x) /3.0;
      la.y = (pp[0].y + 2*pp[1].y) /3.0;
      la.z = (pp[0].z + 2*pp[1].z) /3.0;

      one3 = point_dis (fa, pp[2]); //distance between 1st one-third of AB and
      two3 = point_dis (la, pp[2]);

      if (one3 > two3) pp[0] = fa;
      else pp[1] = la;
   }
   return abs(one3+two3) /2.0;
}
int main ()
{
   int tc, cs = 0;
   //freopen ("in.txt", "r", stdin);
   scanf (" %d", &tc);
   while (tc--) {
      for (int i = 0; i < 3; i++) scanf (" %lf %lf %lf", &pp[i].x, &pp[i].y, &pp[i].z);
      //double res = ternary (pp[0], pp[1]);
      double res = TS();
      printf ("Case %d: %.10lf\n", ++cs, res);
   }
   return 0;
}
/*
7
0 0 1 0 1 1 0 1 0
0 0 0 1 1 1 0 0 1

0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 2 2 2

1 14 5 8 2 11 3 13 9
13 7 20 19 17 12 14 9 7
4 12 9 9 13 10 2 15 19
*/
