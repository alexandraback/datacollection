#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define bug puts("here");

using namespace std;

typedef long long ll;

const int maxn = 10 * 100086;
const ll mod = 1e9+7;

int a[6][6];
int b[6][6];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.txt","w+",stdout);
    int kase = 0;
    int T;
    cin >> T;
    while(T--)
    {
        kase ++;
        int x,y;
        cin >> x;
        int i,j;
        for(i=1;i<=4;i++)
            for(j=1;j<=4;j++)
                cin >> a[i][j];
        cin >> y;
        for(i=1;i<=4;i++)
            for(j=1;j<=4;j++)
                cin >> b[i][j];
        int num = 0;
        int ans = 0;
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                if(a[x][i] == b[y][j])
                {
                    ans = a[x][i];
                    num ++;
                }
            }
        }
        cout << "Case #" << kase << ": ";
        if(num == 1)
        {
            cout << ans <<endl;
        }
        else if(num > 1) cout << "Bad magician!" << endl;
        else cout << "Volunteer cheated!" << endl;
    }
    fclose(stdin);
    fclose(stdout);
}
