#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iostream>
#include<set>
#include<cstring>

using namespace std;

const int L = 19;

int bd[L][L];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int cbit(int x) {
    int ans=0;
    for(int i=0;i<L;i++) if(x&(1<<i)) ans++;
    return ans;
}

void fbd(int s,int r,int c) {
    for(int i=0;i<L;i++) {
        if(s&(1<<i)) {
            bd[1+i/c][1+i%c]=1;
        }
    }
}

int cup(void) {
    int ans=0;
    for(int i=1;i<L-1;i++) {
        for(int j=1;j<L-1;j++) {
            if(bd[i][j]) {
                for(int k=0;k<4;k++) {
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    ans+=bd[nx][ny];
                }
            }
        }
    }
    return ans/2;
}

void output(int r,int c) {
    for(int i=0;i<=r+1;i++) {
        for(int j=0;j<=c+1;j++) cout<<bd[i][j];
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("b.out","w",stdout);

    int t,r,c,k;
    cin>>t;
    for(int cas=1;cas<=t;cas++) {
        cin>>r>>c>>k;
        int st = 1<<(r*c);
        int ans = 1000000;
        for(int i=0;i<st;i++) {
            if( cbit(i)==k ) {
                memset(bd,0,sizeof(bd));
                fbd(i,r,c);
                int temp = cup();
                if(temp<ans) {
                    ans=temp;
                    //output(r,c);
                }
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
