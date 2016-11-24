/*
Lightoj 1028, Tailing Zeros (i)
Counting divisors using N^(1/3) technique
*/
#include <bits//stdc++.h>
using namespace std;
#define NN 1000001 //sqrt(10^12)
#define ll long long
#define pb push_back
ll prime[NN+1], primeSize;
bool pri[NN+1] = {0}; //0 for prime
/////////////////////////////////////////////////////////////////////////
long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
ll power(ll x, unsigned ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1) {
            if (res > 1e9 || x > 1e9) res = mulmod (res, x, p);
            else res = (res*x) % p;
        }
        // y must be even now
        y = y>>1; // y = y/2
        if (x > 1e9) x = mulmod (x, x, p);
        else x = (x*x) % p;
    }
    return res;
}
bool miillerTest(ll d, ll n)
{
    ll a = 2 + rand() % (n - 4);
 
    // Compute a^d % n
    ll x = power(a, d, n);
 
    if (x == 1  || x == n-1)
       return true;
    while (d != n-1)
    {
        if (x > 1e9) x = mulmod (x, x, n);
        else  x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    // Return composite
    return false;
}
bool isPrime(ll n, ll k)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    // Find r such that n = 2^d * r + 1 for some r >= 1
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;
 
    // Iterate given nber of 'k' times
    for (ll i = 0; i < k; i++)
         if (miillerTest(d, n) == false)
              return false;
 
    return true;
}
 
//////////////////////////////////////////////////////////////////////////
 
void gene_prime() { //sieve
    pri[0] = 1; pri[1] = 1;
    for (int i = 2; i <= NN; i++) {
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
    map <ll, int> primeSquare;
    for (int i = 0; i < primeSize; i++) //check if primeSquare
        primeSquare[(ll)prime[i] * (ll)prime[i]] = prime[i];
    int tc, cs = 0, res; ll n;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %lld", &n);
        res = 1;
        for (int i = 0; i*i*i <= n && i < primeSize; i++) {
            if (n %prime[i] == 0) {
                int k = 0;
                while (n %prime[i] == 0) {
                    k++;
                    n /= prime[i];
                }
                res *= (k+1);
            }
        }
        if (isPrime(n, 10) == 1) res *= 2;            //if prime
        else if (primeSquare[n] > 0) res *= 3;//if prime square
        else if (n > 1) res *= 4;             //if multiple of two primes
 
        printf ("Case %d: %d\n", ++cs, res-1);
    }
    return 0;
}
