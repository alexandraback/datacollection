#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int INF = 1 << 30;
const double EPS = 1e-12;

void solve(int num)
{
    set<int> srow, srow2;
    int row, row2;
    cin>>row;
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=4; j++)
        {
            int card;
            cin>>card;
            if(i==row) srow.insert(card);
        }
    }
    cin>>row2;
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=4; j++)
        {
            int card;
            cin>>card;
            if(i==row2) srow2.insert(card);
        }
    }
    vi ans(20);
    auto it=set_intersection(srow.begin(), srow.end(), srow2.begin(), srow2.end(), ans.begin());
    ans.resize(it-ans.begin());
    cout<<"Case #"<<num<<": ";
    if(ans.size()==1) cout<<*ans.begin()<<"\n";
    else if(ans.size()) cout<<"Bad magician!\n";
    else cout<<"Volunteer cheated!\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}
