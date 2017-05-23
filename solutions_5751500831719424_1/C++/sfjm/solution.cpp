#include<cstdio>
#include<cstring>
#include<vector>
using namespace std ;

char s[110][110];

struct XX
{
    int cnt ;
    char a ;
}g[110][110];
int main()
{
    freopen("A-large (1).in","r",stdin);
    freopen("out.txt","w",stdout);
    int _,ca=1;
    int n , j ,i , flag ;
    int len [ 110 ], cnt , tmp ;
    int ans , sum , ma , mi , c ;
    scanf ("%d",&_);
    //printf("___%d",_);
    while(_--)
    {

        scanf ("%d",&n);
        //printf("nnn:%d\n",n);
        for ( i = 0 ;i < n ; i++ )
        {
            scanf("%s",s[i]);
           // printf("%s\n",s[i]);
            tmp = strlen(s[i]);
            cnt = 1 ;
            len[i]=0;
            for ( j = 1;j<=tmp;j++)
            {
                    if ( s[i][j] == s[i][j-1])
                    {
                        cnt ++;
                    }
                    else
                    {
                        g[i][len[i]].cnt=cnt;
                        cnt = 1 ;
                        g[i][len[i]++].a=s[i][j-1];
                    }
            }
        }
        for ( i = 1 ; i < n ; i++ )
            if ( len[i]!=len[i-1])break;
        if ( i != n)
            flag = 0 ;
        else
        flag = 1 ;

        ans = 0 ;
        for ( i = 0 ; i < len[0] && flag; i++ )
        {
            char t = g[0][i].a;
            for ( j = 0 , sum = 0 , ma = mi = g[0][i].cnt; j < n ; j++ )
            {
                if ( g[j][i].a !=t )
                {
                    flag = 0 ;
                    break;
                }
                if ( g[j][i].cnt > ma )
                    ma = g[j][i].cnt;
                if ( g[j][i].cnt < mi )
                    mi = g[j][i].cnt;
            }
            c = ma * n ;
            if ( !flag ) break ;

            for ( int k = mi ; k <= ma ; k++ )
            {

                for ( j = 0 , sum = 0 ; j < n ; j++ )
                {
                    if ( g[j][i].cnt>k)
                        sum+=g[j][i].cnt-k;
                    else sum+=k-g[j][i].cnt;
                }
                if ( sum < c )c = sum ;
            }
            ans += c ;
        }
        printf("Case #%d: ",ca++);
        if ( !flag ) puts("Fegla Won");
        else printf("%d\n",ans);
    }
    return 0 ;
}
