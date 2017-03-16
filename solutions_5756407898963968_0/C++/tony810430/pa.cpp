#include<stdio.h>


int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("pa.out","w",stdout);
    int T;
    int x,y;
    int a[4][4],b[4][4];
    scanf(" %d",&T);

    for(int cas = 1; cas <= T; cas++ ){
        scanf(" %d",&x);
        x--;
        for( int i = 0; i < 4; i++ )
            for( int j = 0; j < 4; j++ )
                scanf(" %d",&a[i][j]);
        scanf(" %d",&y);
        y--;
        for( int i = 0; i < 4; i++ )
            for( int j = 0; j < 4; j++ )
                scanf(" %d",&b[i][j]);

        int cnt=0,cand=-1;
        for( int i = 0; i < 4; i++ ){
            for( int j = 0; j < 4; j++ ){
                if( a[x][i] == b[y][j] ){
                    cand = a[x][i];
                    cnt++;
                }
            }
        }
        printf("Case #%d: ",cas);
        if( cnt == 0 )puts("Volunteer cheated!");
        else if( cnt == 1 )printf("%d\n",cand);
        else    puts("Bad magician!");
    }

    return 0;
}
