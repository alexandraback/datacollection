//
//  main.cpp
//  GCJ2015RoundA
//
//  Created by 冥途雨中旅 on 15/4/18.
//  Copyright (c) 2015年 Gensokyou. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int a[20000];

int main(int argc, const char * argv[]) {
    freopen("../../../../GCJ2015RoundA/in","r",stdin);
    freopen("../../../../GCJ2015RoundA/out","w",stdout);
    int T;
    cin >> T;
    for(int hana = 1;hana <= T;hana++){
        int n, ans1 = 0, ans2 = 0, max2 = 0;
        cin >> n >> a[0];
        ans2 = 0;
        for(int i = 1;i < n;++i){
            cin >> a[i];
            if(a[i] - a[i - 1] < 0){
                ans1 -= a[i] - a[i - 1];
                if(a[i - 1] - a[i] > max2)
                    max2 = a[i - 1] - a[i];
            }
        }
        

        for(int i = 0;i < n - 1; ++i)
            ans2 += min(a[i],max2);
        
        cout << "Case #" <<hana << ": " << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}
