#include <bits//stdc++.h>
using namespace std;
#define NN 1000100
#define ll long long
ll prime[1000101], primeSize;
bool pri[1000101] = {0};

void gene_prime() { //sieve
    for (int i = 4; i <= NN; i += 2) {
        pri[i] = 1;
    }
    for (int i = 3; i <= NN; i += 2) {
        if (pri[i] == 0) {
            for (int j = i+i; j <= NN; j += i) {
                pri[j] = 1;
            }
        }
    }
    primeSize = 0;
    for (int i = 2; i <= NN; i++) {
        if (pri[i] == 0) prime[primeSize++] = (ll) i;
    }
}
int main ()
{
    gene_prime ();
    int tc, cs = 0, res; ll n;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %lld", &n);
        int ccSize = 0;
        res = 1;
        for (int i = 0; i < primeSize; i++) {
            if (prime[i] > sqrt(n) + 1) break;
            if (n %prime[i] == 0) { //checking prime factor
                int k = 0;
                while (n %prime[i] == 0) {
                    n /= prime[i];
                    k++;
                }
                res *= (k+1); //counting divisors
            }
        }
        if (n > 1) res *= 2;
        printf ("Case %d: %d\n", ++cs, res-1);

    }
    return 0;
}

