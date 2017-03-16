//
//  main.cpp
//  senate
//
//  Created by MichelleShieh on 5/8/16.
//  Copyright (c) 2016 MichelleShieh. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n;
    int p[1100];
    int max1,max2;
    char m1,m2;
    for (int i=1;i<=t;i++) {
        cin>>n;
        cin>>p[0]>>p[1];
        if (p[0]>p[1]) {
            max1=p[0];
            max2=p[1];
            m1 = 'A';
            m2 = 'B';
        }
        else {
            max1=p[1];
            max2=p[0];
            m1 = 'B';
            m2 = 'A';
        }
        for (int k=2;k<n;k++) {
            cin>>p[k];
            if (p[k]>max1) {
                max2=max1;
                m2 = m1;
                max1=p[k];
                m1 = char(k+'A');
            }
            else if (p[k]>max2) {
                max2=p[k];
                m2 = char(k+'A');
            }
        }
        //cout<<m1<<":"<<max1<<" "<<m2<<":"<<max2;
        cout<<"Case #"<<i<<": ";

        while (max1!=max2) {
            cout<<m1<<" ";
            max1--;
        }
        
        for (int j=0;j<n;j++) {
            while (j!=m1-'A' && j!=m2-'A' && p[j]>0) {
                cout<<char(j+'A')<<" ";
                p[j]--;
            }
        }
        
        for (int j=0;j<max1;j++) {
            cout<<m1<<m2<<" ";
        }
        cout<<endl;
    }
    return 0;
}


