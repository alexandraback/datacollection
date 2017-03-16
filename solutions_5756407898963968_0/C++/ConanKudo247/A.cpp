#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define FOR(i,a,b) for(int i = (a); i <= (b);i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;
bool dd[20];
int vote[20];
int a[20][20];
int main() 
{
    freopen("A1.in","r",stdin);
    freopen("A.out","w",stdout);
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        memset(vote,0,sizeof(vote));
        FR(iter,2) {
            int x;
            cin >> x;
            memset(dd,false,sizeof(dd));
            FOR(i,1,4) FOR(j,1,4) cin >> a[i][j];
            FOR(j,1,4) dd[a[x][j]] = true;
            FOR(j,1,16) if (dd[j]) 
            vote[j]++;
        }
        int cnt = 0;
        FOR(i,1,16) if (vote[i] == 2) cnt++;
        if (cnt > 1) cout << "Bad magician!" << endl;
        else if (cnt == 0) cout << "Volunteer cheated!" << endl;
        else {
            FOR(i,1,16)
            if (vote[i] == 2) cout << i << endl;
        }
    }
    return 0;
}
