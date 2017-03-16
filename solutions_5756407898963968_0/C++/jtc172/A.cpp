#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define N 4

int mat1[N][N],mat2[N][N];
int s[N*N+1];
int T;
int a,b;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int i = 1 ; i <= T ; i ++ ) {
        cin>>a;a--;
        for (int j = 0 ; j < N ; j ++ ) 
            for (int k = 0 ; k < N ; k++ ) cin>>mat1[j][k];
        cin>>b;b--;
        for (int j = 0 ; j < N ; j ++ )
            for (int k = 0 ; k < N ; k++ ) cin>>mat2[j][k];
        for (int j = 1 ; j<=N*N ; j ++ ) s[j]=0;
        for (int j = 0 ; j < N ; j ++ ) s[mat1[a][j]]=1;
        for (int j = 0 ; j < N ; j ++ ) 
            s[mat2[b][j]]=s[mat2[b][j]]+1;
        int sum = 0;
        for (int j = 1 ; j<=N*N ; j++ ) if (s[j]==2) sum++;
        cout<<"Case #"<<i<<": ";
        if (sum == 0 ) {cout<<"Volunteer cheated!"<<endl;};
        if (sum == 1 ) {for (int j = 1 ; j <=N*N ; j ++ ) if (s[j]==2) cout<<j<<endl;};
        if (sum > 1 ) {cout<<"Bad magician!"<<endl;};
    }
    return 0;
}
        
            
        
