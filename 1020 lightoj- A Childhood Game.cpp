#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, tc, cs = 0;
    char s[7];
    scanf("%ld", &tc);
    while(tc--) {
        scanf("%d %s", &n, s);
        printf ("Case %d: ", ++cs);
        if(strcmp(s, "Alice")==0) {
            if(n%3 == 1) printf("Bob");
            else printf("Alice");
        }
        else {
            if(n%3 == 0) printf("Alice");
            else printf("Bob");
        }
        printf ("\n");
    }
    return 0;
}
