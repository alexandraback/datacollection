//
//  main.cpp
//  a
//
//  Created by Zhou Sun on 15/4/17.
//  Copyright (c) 2015年 Zhou Sun. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int ts;
    int b,n;
    int m[100000];
    int r1,r2,mx;
    ifstream in("b-in.txt");
    ofstream out("b-out.txt");
    in>>ts;
    
    for (int tt=1; tt<= ts; tt++) {
        in>>b>>n;
        for (int i=0; i<b; i++) {
            in>>m[i];
        }
        if (n<=b) {
            out<<"Case #"<<tt<<": "<<n<<endl;
            continue;
        }
        long long l=0;
        long long r=100000LL*1e9;
        while (l+1<r) {
            long long mid=(l+r)/2;
            long long s=0;
            for (int i=0; i<b; i++) {
                s+= mid/m[i]+1;
            }
            if(s>=n){
                r=mid;
            }
            else{
                l=mid;
            }
        }
        long long s=0;
        for (int i=0; i<b; i++) {
            s+= (r-1)/m[i]+1;
        }
        int k=n-s;
        for (int i=0; i<b; i++) {
            if (r%m[i]==0) {
                k--;
                if (k==0) {
                    r1=i;
                    break;
                }
            }
        }
        
        out<<"Case #"<<tt<<": "<<r1+1<<endl;
    }
    
    return 0;
}
