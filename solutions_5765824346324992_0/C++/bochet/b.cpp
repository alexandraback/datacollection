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
        ll b, n, m[1000];
        cin >> b >> n;
        for(int i = 0; i < b; i++)
            cin >> m[i];
        if(cid == 15)
            cout << "" ;
        ll ans = 0;
        if(n <= b)
            ans = n;
        else{
            ll right = (n/b)*ll(1e5), left = 0, middle;
            
            while(left <= right){
                middle = (left+right)/2;
                ll user0 = 0, user1 = 0;
                for(int i = 0; i < b; i++){
                    user0 += middle/m[i]+1;
                    user1 += (middle-1)/m[i]+1;
                }
                
                if(user0 < n)
                    left = middle + 1;
                else{
                    if(user1 < n)
                        break;
                    else
                        right = middle-1;
                }
            }
            
            ll user1 = 0;
            for(int i = 0; i < b; i++)
                user1 += (middle-1)/m[i]+1;
            
            for(int i = 0; i < b; i++)
                if(middle/m[i]> (middle-1)/m[i]){
                    user1++;
                    if(user1 == n){
                        ans = i+1;
                        break;
                    }
                }
        }
        printf("Case #%d: %lld\n", cid, ans);
    }
    return 0;
}
