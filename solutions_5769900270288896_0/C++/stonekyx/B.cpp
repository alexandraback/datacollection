#include <iostream>
#include <climits>

using namespace std;

const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};

int encode(int x, int y, int C)
{
    return x*C + y;
}

bool check(int x, int y, int r, int c) {
    return x>=0 && y>=0 && x<r && y<c;
}

int getbit(int x, int pos)
{
    return x&(1<<pos);
}

int countbit(int x)
{
    int ans = 0;
    while(x) {
        ans += (x&1);
        x>>=1;
    }
    return ans;
}

int conflict(int R, int C, int x)
{
    int res = 0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            int code = encode(i,j,C);
            if(!getbit(x, code)) continue;
            for(int k=0; k<4; k++) {
                int nx = i+dx[k], ny = j+dy[k];
                if(!check(nx, ny, R, C)) continue;
                if(getbit(x, encode(nx,ny,C))) res++;
            }
        }
    }
    return res/2;
}

int calc(int R, int C, int N)
{
    int ans = INT_MAX;
    for(int i=0; i<(1<<(R*C)); i++) {
        if(countbit(i) != N) continue;
        int tans = conflict(R, C, i);
        if(ans > tans) {
            ans = tans;
        }
    }
    return ans;
}

int main()
{
    int T, Tcnt=1;
    cin>>T;
    for(; T; T--,Tcnt++) {
        int R, C, N;
        cin>>R>>C>>N;
        cout<<"Case #"<<Tcnt<<": "<<calc(R, C, N)<<endl;
    }
    return 0;
}

