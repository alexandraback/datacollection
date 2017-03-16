#include <iostream>
#include <cstring>
using namespace std;
int T, n, p1, p2;
char s1[200], s2[200];
bool won;
int main()
{
    scanf( "%d", &T);
    for ( int I = 1; I <= T; ++I )
    {
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        scanf( "%d", &n);
        scanf( "%s", s1+1);
        scanf( "%s", s2+1);
 //       printf( "!%lu %lu!\n", strlen(s1+1), strlen(s2+1));
        for (int i = 0; i < n - 2; ++i )
            scanf( "%s", s1);
        if (n > 2) continue;
        p1 = 1; p2 = 1;
        won = true;
        s1[0] = 0; s2[0] = 0;
        int su = 0;
        while ( (s1[p1] != '\0' || s2[p2] != '\0' ) && won)
        {
            while ((s1[p1] != s2[p2]) && won )
            {
                if (s1[p1] == s1[p1-1]) p1++;
                else if (s2[p2] == s2[p2-1]) p2++;
                else won = false;
                su++;
            }
            p1++; p2++;
   //         printf( "%d %d\n", p1, p2);
        }
        if (!won)
            printf( "Case #%d: Fegla Won\n", I);
        else printf( "Case #%d: %d\n", I, su);


    }
}
