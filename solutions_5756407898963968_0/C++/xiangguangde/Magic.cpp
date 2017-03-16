#include<algorithm>
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int a[20][20];
int b[20][20];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    int T,i,j,x,y,count=1,flag=1,res=0;
    cin>>T;
    while(T--){
        cin>>x;
        for(i=1; i<=4; i++){
            for(j=1; j<=4; j++){
                cin>>a[i][j];
            }
        }
        cin>>y;
        for(i=1; i<=4; i++){
            for(j=1; j<=4; j++){
                cin>>b[i][j];
            }
        }
        int temp=0;
        for(i=1; i<=4; i++){
            for(j=1 ;j<=4; j++){
                if(a[x][i]==b[y][j]){temp++;res=a[x][i];}
            }
        }
        cout<<"Case #"<<count++<<": ";
        if(temp == 0){
            cout<<"Volunteer cheated!"<<endl;
        }
        else if(temp == 1){
            cout<<res<<endl;
        }
        else {
            cout<<"Bad magician!"<<endl;
        }


    }

    return 0;
}
