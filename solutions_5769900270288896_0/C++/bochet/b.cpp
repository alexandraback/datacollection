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
int r, c, n, ngrid;

int unhappy(int conf){
    bool tenant[17][17] = {false};
    
    for(int i = 0; i < ngrid; i++)
        if((conf >> i) & 1){
            int rid = i/c;
            int cid = i-rid*c;
            tenant[rid][cid] = true;
        }
    
    int cnt = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            if(tenant[i][j] && tenant[i+1][j])
                cnt++;
            if(tenant[i][j] && tenant[i][j+1])
                cnt++;
        }
    return cnt;
}

int main()
{
    freopen("/Users/bochen/Downloads/textfile.in","r", stdin);
    freopen("/Users/bochen/Downloads/textfile.out","w", stdout);

    int t;
    cin >> t;
    for(int cid = 1; cid <= t; cid++){
        cin >> r >> c >> n;
        ngrid = r*c;
        
        int min_val = 10000000;
        for(int i = 0; i < (1<<ngrid); i++){
            int cnt = 0;
            for(int j = 0; j < ngrid; j++)
                if((i >> j) & 1)
                    cnt++;
            if(cnt == n)
                min_val = min(min_val, unhappy(i));
        }
        printf("Case #%d: %d\n", cid, min_val);
    }
    return 0;
}
