#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cstring>
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int n,r,c;
vector<vector<bool> > board;
int best;
void rec(int x, int y, int tenants) {
    if(x==r-1&&y==c) {
        if(tenants != n) return;
        int happ=0;
        
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                int orig=happ;
                if(board[i][j]) {
                    for(int move=0;move<4;move++) {
                        int nx = i + dx[move];
                        int ny = j + dy[move];
                        if(nx >= 0 && nx < r && ny >= 0 && ny < c && board[nx][ny]) {
                            happ++;
                        }
                    }
                }
            }
        }
        best=min(best,happ);
        return;
    } else if(y==c) {
        y=0;
        x+=1;


    }
    if(tenants < n) {
        board[x][y]=true;
        rec(x,y+1,tenants+1);
    }
    board[x][y]=false;
    rec(x,y+1,tenants);

}

void f() {
    cin>>r>>c>>n;
    board.resize(r);
    for(int i=0;i<r;i++) board[i].resize(c,false);
    best = 10000000;

    rec(0,0,0);
    cout<<best/2<<endl;


}

int main() {
    int T;
    cin>>T;
    for(int i=1;i<=T;i++) {
        cout<<"Case #"<<i<<": ";
        f();
        cout<<endl;
    }
}
