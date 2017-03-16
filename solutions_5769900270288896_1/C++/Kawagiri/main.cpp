//
//  main.cpp
//  GCJ2015RoundB-2
//
//  Created by 冥途雨中旅 on 15/5/3.
//  Copyright (c) 2015年 Gensokyou. All rights reserved.
//

#include <iostream>
using namespace std;
int T;

int main(int argc, const char * argv[]) {
    // insert code here...
    freopen("../../../../GCJ2015RoundB-2/in","r",stdin);
    freopen("../../../../GCJ2015RoundB-2/out","w",stdout);
    cin >> T;
    
    for(int l = 0;l < T; ++l){
        int r,c,n;
        cin >> r >> c >> n;
        if(r < c) swap(r,c);
        
        cout << "Case #" << l + 1 << ": ";
        
        if(c == 1 && r == 1){
            cout << 0 << endl;
            continue;
        }
        
        if(c == 1){
            if(r % 2){
                if(n <= r / 2 + 1){
                    cout << 0 << endl;
                    continue;
                }
                n -= r / 2;
                if(n <= 2){
                    cout << n  << endl;
                    continue;
                }
                cout << (n - 2) * 2 + 2 << endl;
                continue;
            }
            if(n <= r/2){
                cout << 0 << endl;
                continue;
            }
            
            cout << (n - r/2 - 1) * 2  + 1 << endl;
            continue;
        }
        
        if( r % 2 && c % 2){
            if(n <= (r * c  + 1) / 2){
                cout << 0 << endl;
                continue;
            }
            n -= (r * c) / 2;
            if(n == 2){
                cout << 3 << endl;
                continue;
            }
            if(n <= 4){
                cout << n * 2 << endl;
                continue;
            }
            
            
            int sange = (r/2 - 1 + c/2 - 1) * 2;
            if(n <= 4 + sange){
                cout << (n - 4) * 3 + 8 << endl;
                continue;
            }
            
            cout << (n - sange - 4) * 4 + sange * 3 + 8 << endl;
            continue;
            
        }
        
        if(r % 2 && c % 2 == 0)
            swap(r,c);
        
        if(r % 2 == 0 && c % 2){
            if(n <= r * c / 2){
                cout << 0 << endl;
                continue;
            }
            n -= r * c / 2;
            if(n <= 2){
                cout << n * 2 << endl;
                continue;
            }
            
            int sange = (r / 2 - 1 ) * 2 +  c / 2 - 1 + c / 2;
            if(n <= 2 +sange){
                cout << (n - 2)* 3 + 4 << endl;
                continue;
            }
            
            cout << (n - 2 - sange) * 4 + sange * 3 + 4 << endl;
            continue;
        }
        
        if (r % 2 == 0 && c % 2 == 0) {
            if(n <= r * c / 2){
                cout << 0 << endl;
                continue;
            }
            n -= r * c / 2;
            if(n <= 2){
                cout << n * 2 << endl;
                continue;
            }
            int sange = (r/2 - 1 + c / 2 - 1) * 2;
            if(n -2 <= sange){
                cout << (n - 2) * 3 + 4 << endl;
                continue;
            }
            cout << (n - 2 - sange) * 4 + sange * 3 + 4 << endl;
            continue;
                
        }
    }
    return 0;
}
