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
#define abs_err 0.00000001

struct point {
   double x;
   double y;
};
point pp[4]; //point a, b, c, d

double dist (point p1, point p2) {
   double temp = (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
   return sqrt (temp);
}
double TS () {
   double one3, two3;
   one3 = dist (pp[0], pp[2]);
   two3 = dist (pp[1], pp[3]);

   while (abs (one3-two3) > abs_err) {
      point fa, la; //first and second 1-3rd for AB respectively.
      point fc, lc; //first and second 1-3rd for CD respectively.
      fa.x = (2*pp[0].x + pp[1].x) /3.0;
      fa.y = (2*pp[0].y + pp[1].y) /3.0;
      la.x = (pp[0].x + 2*pp[1].x) /3.0;
      la.y = (pp[0].y + 2*pp[1].y) /3.0;

      fc.x = (2*pp[2].x + pp[3].x) /3.0;
      fc.y = (2*pp[2].y + pp[3].y) /3.0;
      lc.x = (pp[2].x + 2*pp[3].x) /3.0;
      lc.y = (pp[2].y + 2*pp[3].y) /3.0;

      one3 = dist (fa, fc); //distance of 1st 1-3rd.
      two3 = dist (la, lc); //distance of 2nd 1-3rd.
      if (two3 < one3) {pp[0] = fa; pp[2] = fc;} //moving a to b, c to d
      else {pp[1] = la; pp[3] = lc;}             //moving b to a, d to c

   }
   return abs(one3+two3) /2;
}
int main ()
{
   //freopen ("in.txt", "r", stdin);

   int tc, cs = 0;
   double res = 0.0;
   scanf (" %d", &tc);
   while (tc--) {
      for (int i = 0; i < 4; i++) scanf (" %lf %lf", &pp[i].x, &pp[i].y);
      res = TS ();
      printf ("Case %d: %lf\n", ++cs, res);
   }
   return 0;
}
