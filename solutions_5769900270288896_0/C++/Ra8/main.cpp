#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
typedef long long ll;
using namespace std;
int G[20][20];
int R,C,N,T;
int cnt(){
    int tot=0;
    for(int i=0;i<C;i++){
        for(int j=1;j<R;j++){
            if(G[i][j-1]==1 && G[i][j]==1)tot++;
        }
    }
    for(int j=0;j<R;j++){
        for(int i=1;i<C;i++){
            if(G[i-1][j]==1 && G[i][j]==1)tot++;
        }
    }
    return tot;
}

int compute(){
    int m=R*C;
    int mn=m*m*m;
    for(int i=0;i<(1<<m);i++){
        int n=i;
        int cn=0;
        for(int j=0;j<m;j++){
            //cout << j/R << " " << j%R << endl;
            G[j/R][j%R]=n%2;
            cn=cn+n%2;
            n/=2;
        }
        //cout << endl;
        if(cn==N)
        mn=min(mn,cnt());
    }
    return mn;
}
int main()
{
    freopen("txt.in","r",stdin);
    freopen("out","w",stdout);
    cin >> T;

    for(int t=0;t<T;t++){
        cin >> R >> C >> N;
        cout << "Case #" << t+1 << ": " << compute() << endl;
    }
    return 0;
}
