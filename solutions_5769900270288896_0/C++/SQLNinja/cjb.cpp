#include <bits/stdc++.h>
using namespace std;

int arr[16][16],p[16][16];
void init(int n,int m){
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++) p[i][j]=1;
    }
void fill(int n,int m){
    n--,m--;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            if(i==0&&j==0||i==0&&j==m||i==n&&j==0||i==n&&j==m)arr[i][j]=2;
        else if(i==0||i==n||j==0||j==m)arr[i][j]=3;
        else arr[i][j]=4;
    }
}
int sum(int n,int m){
    int ans=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++) ans+=arr[i][j];
    return ans;
}
void findmax(int *x,int *y,int n,int m){
    *x=0;*y=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(arr[i][j]>arr[*x][*y])
    {
        *x=i;*y=j;
    }
}
int  bound(int n,int m){
    int ans=0;;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
    if(p[i][j])
    if(i<n-1){
        if(j<m-1){ans += p[i][j+1]+p[i+1][j];}
        else     {ans += p[i+1][j];}
    }
    else{
        if(j<m-1){ans += p[i][j+1];}
    }
    }
    return ans;
}
int main()
{
    freopen("b.in","r",stdin);
    freopen("out.txt","w",stdout);

	int tc;cin>>tc;
	for(int t=1;t<=tc;t++){
        int R,C,N;
        cin>>R>>C>>N;
        int ans;
        cout<<"Case #"<<t<<": ";
        if(R*C==N){
            cout<<N+1<<endl;
            continue;
        }
       fill(R,C);
       int im,jm;
       int cap=R*C;
       init(R,C);
       while(N<cap){
        findmax(&im,&jm,R,C);
        cap--;
        arr[im][jm]=-1;
        p[im][jm]=0;
       }

                   cout<<bound(R,C)<<endl;


	}
}
