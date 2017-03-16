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
    int n;
    int m[100000];
    int r1,r2,mx;
    ifstream in("a-in.txt");
    ofstream out("a-out.txt");
    in>>ts;

    for (int tt=1; tt<= ts; tt++) {
        in>>n;
        mx=r1=r2=0;
        
        for (int i=0; i<n; i++) {
            in>>m[i];
            
        }
        for (int i=1; i<n; i++) {
            r1+=(m[i]<m[i-1]?m[i-1]-m[i]:0);
            mx=max(mx,m[i-1]-m[i]);
        }
        for (int i=1; i<n; i++) {
            r2+=min(m[i-1],mx);
        }
        out<<"Case #"<<tt<<": "<<r1<<' '<<r2<<endl;
    }
    
    return 0;
}
