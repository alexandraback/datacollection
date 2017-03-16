#include <iostream>
#include <cstring>
using namespace std;
int T, n, p1, p2;
char s[200][200];
bool won;
int b[200], a[200][200];
bool same()
{
    for ( int i = 1; i < n; ++i )
        if (strcmp(s[i], s[0]) != 0)
            return false;
    return true;
}
int main()
{
    scanf( "%d", &T);
    for ( int I = 1; I <= T; ++I )
    {
        memset(s, 0, sizeof(s));
        scanf( "%d", &n);
        for ( int i = 0; i < n; ++i)
        {
            scanf( "%s", s[i]);
            int pp = 0;
            a[i][0] = 1;
            for ( int j = 1; s[i][j]; ++j)
                if (s[i][pp] != s[i][j] )
                {
                    pp++; s[i][pp] = s[i][j];
                    a[i][pp] = 1;
                }
                else a[i][pp]++;
            s[i][pp+1] = 0;
        }

        if (!same())
            printf( "Case #%d: Fegla Won\n", I);
        else
        {
            int su = 0;
            int len = strlen(s[0]);
            for ( int i = 0; i < len; ++i )
            {
                for ( int j = 0; j < n; ++j )
                    b[j] = a[j][i];
                sort(b, b+n);
                for ( int j = 0; j < n/2; ++j)
                    su += b[n-j-1] - b[j];
            }
            printf( "Case #%d: %d\n", I, su);
        }

    }


                

}
