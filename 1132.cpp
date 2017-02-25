/*
    Soluton Idea:
    --------------
    f(x)=1^k+2^k+3^k+..........+x^k
    f(1)=1
    f(x+1)=f(x)+(x+1)^k
    from Binomial Co efficient we know -
    (x+1)^n= nC0 x^n + nC1 x^n-1 + nC2 x^n-2+..............+ nCn-1 x^1 + nCn x^0
    details: http://lbv-pc.blogspot.com/2012/05/summing-up-powers.html
*/
#include <bits/stdc++.h>
using namespace std;
#define ui unsigned int
#define ll long long
ui mat[60][60], cus[60][60];
vector <ui > v[60];

void generateNCR () { //it can count nCr less than 10000
   v[0].push_back(1); //10000 takes 2 sec..
   v[1].push_back(1);
   v[1].push_back(1);
   for (int i = 2; i < 55; i++) {
      for (int j = 0; j <= i; j++) {
         if (i == j || j == 0) v[i].push_back(1);
         else if (j == 1 || j == i-1) v[i].push_back(i);
         else {
            ui temp = (v[i-1][j-1] + v[i-1][j])  ;
            v[i].push_back(temp);
         }
      }
   }
}
void make_matrix (int k) {
    for (int i = 0; i <= k+1; i++)
        for (int j = 0; j <= k+1; j++) mat[i][j] = 0;
    mat[0][0] = 1;
    for (int i = 0; i <= k; i++) {
        mat[0][i+1] = v[k][i];
    }
    for (int i = 1; i <= k+1; i++) {
        for (int j = i, p = 0; p <= k-i+1; j++, p++) {
            mat[i][j] = v[k-i+1][p];
        }
    }
    for (int i = 0; i <= k+1; i++) {
        for (int j = 0; j <= k+1; j++) {
            cus[i][j] = mat[i][j];
        }
    }
}
void matExpo (ll e, int N) {  //mat ^e  , N = k+2
    if (e <= 1LL) return;
    matExpo (e >> 1, N);
    ui tt[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ui sum = 0;
            for (int k = 0; k < N; k++) sum += (mat[i][k] * mat[k][j]);
            tt[i][j] = sum;
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            mat[i][j] = tt[i][j];

    if (e %2 == 1) { //if odd one more multiply with previous square
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ui sum = 0;
                for (int k = 0; k < N; k++) sum += (tt[i][k] * cus[k][j]);
                mat[i][j] = sum;
            }
        }
    }
}
int main ()
{
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);
    int tc, cs = 0, k;
    ll n; ui res;
    generateNCR ();
    //cout << v[50][50] << endl;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %lld %d", &n, &k);
        printf ("Case %d: ", ++cs);
        if (n == 1) {
            printf ("1\n");
            continue;
        }
        make_matrix (k);
//        cout << endl;
//        for (int i = 0; i < k+2; i++) {
//            for (int j = 0; j < k+2; j++) {
//                cout << mat[i][j] << " ";
//            } cout << endl;
//        }
        matExpo (n-1, k+2);
        res = 0;
        for (int i = 0; i <= k+1; i++) {
            res += mat[0][i];
        }
        printf ("%u\n", res);
    }
    return 0;
}
