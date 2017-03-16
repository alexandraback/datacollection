#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[5][5],d[5][5];
int main()
{
    freopen("C://Users//Jo//Documents//A-small-attempt2.in","r",stdin);
    freopen("C://Users//Jo//Documents//out.txt","w",stdout);
    int t;
    int a,b;
    int cas=1;
    cin>>t;
    while(t--){
        cin>>a;
        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++){
                scanf("%d",&s[i][j]);
                //cout<<s[i][j];
            }
        }
        cin>>b;
        //cout<<b<<endl;
        for(int i=1;i<=4;i++){
            for(int j=1;j<=4;j++){
                scanf("%d",&d[i][j]);
            }
        }
        int flag=0;
        int ans;
        for(int j=1;j<=4;j++){
            for(int i=1;i<=4;i++){
                if(d[b][j]==s[a][i]){
                    flag++;
                    ans=s[a][i];
                }
            }
        }
        printf("Case #%d: ",cas++);
        if(flag==0)printf("Volunteer cheated!\n");
        else if(flag>1){
            printf("Bad magician!\n");
        }
        else printf("%d\n",ans);
    }
    return 0;
}
