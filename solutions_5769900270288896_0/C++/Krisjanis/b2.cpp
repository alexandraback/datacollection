#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>


using namespace std;

int t;
int r,c,n;

int ans;

int board[20][20];

void s(int x, int y, int placed) {
    if(x<r-1||y<c-1) {
        board[x][y]=0;
        if(x<r-1) {
            s(x+1, y,placed);
        } else if (y<c+1) {
            s(0, y+1, placed);
        }
        board[x][y]=1;
        if(x<r-1) {
            s(x+1, y,placed+1);
        } else if (y<c+1) {
            s(0, y+1, placed+1);
        }
    } else {
        if(placed<n-1) return;
        if(placed>n) return;
        if(placed==n-1) board[x][y]=1;
        if(placed==n) board[x][y]=0;
        int tans=0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++){
                if(board[i][j]==1) {
                    if(i<r-1) {
                        if(board[i+1][j]==1) tans++;
                    }
                    if(j<c-1) {
                        if(board[i][j+1]==1) tans++;
                    }
                }
            }
        }
        ans=min(ans,tans);
    }
}

int main() {
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);

    cin>>t;
    for(int cases=0;cases<t;cases++) {
        cin>>r>>c>>n;
        ans=r*c*2;
        s(0,0,0);
        cout<<"Case #"<<cases+1<<": "<<ans<<endl;
    }
}
