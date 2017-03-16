//#include <cstdio>
//#include <cmath>
//#include <string>
//#include <iomanip>
//#include <iostream>
//#include <fstream>
//#include <set>
//#include <map>
//#include <list>
//#include <queue>
//#include <stack>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//typedef long long ll;
//int r, c, n, ngrid;
//
//int unhappy(int conf){
//    bool tenant[17][17] = {false};
//    
//    for(int i = 0; i < ngrid; i++)
//        if((conf >> i) & 1){
//            int rid = i/c;
//            int cid = i-rid*c;
//            tenant[rid][cid] = true;
//        }
//    
//    int cnt = 0;
//    for(int i = 0; i < r; i++)
//        for(int j = 0; j < c; j++){
//            if(tenant[i][j] && tenant[i+1][j])
//                cnt++;
//            if(tenant[i][j] && tenant[i][j+1])
//                cnt++;
//        }
//    return cnt;
//}
//
//int main()
//{
//    freopen("/Users/bochen/Downloads/textfile.in","r", stdin);
//    freopen("/Users/bochen/Downloads/textfile.out","w", stdout);
//
//    int t;
//    cin >> t;
//    for(int cid = 1; cid <= t; cid++){
//        cin >> r >> c >> n;
//        ngrid = r*c;
//        
//        int min_val = 10000000;
//        for(int i = 0; i < (1<<ngrid); i++){
//            int cnt = 0;
//            for(int j = 0; j < ngrid; j++)
//                if((i >> j) & 1)
//                    cnt++;
//            if(cnt == n)
//                min_val = min(min_val, unhappy(i));
//        }
//        printf("Case #%d: %d\n", cid, min_val);
//    }
//    return 0;
//}
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
int r, c, n;


int ans(int c1, int rest){
    int e1 = r+c-2-c1;
    int ret = 0;
    if(rest <= c1)
        ret += rest*2;
    else if(rest <= c1+e1){
        ret = c1*2;
        ret += (rest-c1)*3;
    }
    else{
        ret = c1*2+ e1*3;
        ret += (rest-c1-e1)*4;
    }
    return ret;
}

int solve(){
    if(n <= (r*c+1)/2)
        return 0;
    
    int ret = 0;
    int half = r*c/2;
    if(min(r, c) == 1){
        int r0 = min(r,c), c0 = max(r,c);
        if(c0 % 2 == 0){
            int rest = n-half;
            if(rest <= 1)
                ret = rest*1;
            else
                ret = 1+(rest-1)*2;
        }else{
            int rest1 = n-half;
            if(rest1 <= 2)
                ret = rest1*1;
            else
                ret = 2+(rest1-2)*2;
            
            int rest2 = n-half-1;
            ret = min(ret, rest2*2);
        }
    }
    else if(r % 2 == 0 || c % 2 == 0)
        ret = ans(2, n-half);
    else
        ret = min(ans(4, n-half), ans(0, n-1-half));
    return ret;
}

int main()
{
    freopen("/Users/bochen/Downloads/textfile.in","r", stdin);
    freopen("/Users/bochen/Downloads/textfile.out","w", stdout);
    
    int t;
    cin >> t;
    for(int cid = 1; cid <= t; cid++){
        cin >> r >> c >> n;
        printf("Case #%d: %d\n", cid, solve());
    }
    return 0;
}

