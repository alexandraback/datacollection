#include <cstdio>
#include <cmath>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    freopen("/Users/bochen/Downloads/textfile.in","r", stdin);
    freopen("/Users/bochen/Downloads/textfile.out","w", stdout);

    int t;
    cin >> t;
    for(int cid = 1; cid <= t; cid++){
        int n, m[1000];
        cin >> n;
        
        int eat1 = 0, eat2 = 0, maxgap = 0;
        for(int i = 0; i < n; i++)
            cin >> m[i];
        
        for(int i = 1; i < n; i++)
            if(m[i] < m[i-1]){
                eat1 += m[i-1]-m[i];
                maxgap = max(maxgap, m[i-1]-m[i]);
            }
        
        for(int i = 0; i < n-1; i++)
            eat2 += min(maxgap, m[i]);
        printf("Case #%d: %d %d\n", cid, eat1, eat2);
    }
    return 0;
}
