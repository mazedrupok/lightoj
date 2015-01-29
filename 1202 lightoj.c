    #include <stdio.h>
    int main ()
    {
       int r1, c1, r2, c2, rd, cd;
       int cas, k;

       scanf (" %d", &cas);
       for (k = 1; k <= cas; k++) {

          scanf (" %d %d %d %d", &r1, &c1, &r2, &c2);
          rd = r1 - r2;
          cd = c1 - c2;
          if (rd < 0) rd = rd * -1;
          if (cd < 0) cd = cd * -1;
          if (rd == cd)
             printf ("Case %d: 1\n", k);

          else if (rd %2 == 0 && cd %2 == 0)
             printf ("Case %d: 2\n", k);

          else if (rd %2 == 1 && cd %2 == 1)
             printf ("Case %d: 2\n", k);

          else
             printf ("Case %d: impossible\n", k);
       }

       return 0;
    }

