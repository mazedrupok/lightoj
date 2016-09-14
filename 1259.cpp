#include <bits/stdc++.h>
using namespace std;
bool pri[10000001];
int pStore[664580]; //664579 primes in 10^7,
                    //array takes less than STL vector
int total = 0;
void sieveOfEratosthenes (int limit) { //works in 10^7
   pri[0] = 0; pri[1] = 0;             //prime limitber generator.. start
   for (int i = 2; i <= limit; i++) {
      pri[i] = 1;
   }
   for (int i = 2; i <= sqrt(limit); i++) {
      if (pri[i] == 0) continue;
      for (int j = 2; i*j <= limit; j++) {
         pri[i*j] = 0;
      }
   }
   for (int i = 2; i <= limit; i++) {
       if (pri[i]) pStore[total++] = i;
   }
}

int main()
{
//    clock_t start;
//    double duration;
//    start = clock();
//    freopen ("in.txt", "r", stdin);
//    freopen ("out.txt", "w", stdout);
    sieveOfEratosthenes(10000000); //10^7

    int tc, cs = 0, cnt, n;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d", &n);
        cnt = 0;
        for (int i = 0; pStore[i] <= n/2; i++)
            if (pri[n - pStore[i]] ) cnt++; //p = pStore[i];
                                            //q = n - pStore[i];
                                            //if (q is a prime) cnt++;

        printf ("Case %d: %d\n", ++cs, cnt);
    }
//    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
//    cout<<"Time: "<< duration <<'\n';
    return 0;
}
