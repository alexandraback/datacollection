/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <bitset>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pip pair< int, pii >
#define pll pair < ll, ll >
#define pill pair< int, pll >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define REP(i,a,n) for(int i=a;i<(int)n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
vector<int> V;
int n;
bool zero(){
    for(int i=0;i<n;i++){
        if(V[i] > 0)
            return false;
    }
    return true;
}
int getMaxIdx(){
    int idx = 0;
    int hi = 0;
    for(int i=0;i<n;i++){
        if(V[i] > hi){
            hi = V[i];
            idx = i;
        }
    }
    return idx;
}
int satisfy(){
    int tot = 0;
    int hi = 0;
    for(int i=0;i<n;i++)
    {
        hi = max(hi, V[i]);
        tot += V[i];
    }
    if(hi > tot/2){
        return false;
    }
    return true;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("1.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++)
    {
        printf("Case #%d: ", z);
        V.clear();
        cin >> n;
        for(int i=0;i<n;i++){
            int x;
            cin >>  x;
            V.pb(x);
        }
        while(1)
        {
            if(zero()){
                cout << "\n";
                break;
            }
            int x = getMaxIdx();
            V[x]--;
            string str = "A";
            char ch = 'A'+ x;
            str[0] = ch;
            cout << str;
            if(!satisfy())
            {
                int y = getMaxIdx();
                V[y]--;
                string str2 = "A";
                char ch2 = 'A'+ y;
                str2[0] = ch2;
                cout << str2;
            }
            cout << " ";
        }

    }
    return 0;
}
