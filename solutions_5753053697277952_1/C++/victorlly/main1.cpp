//
//  main1.cpp
//  CodeJam
//
//  Created by Victor Young on 5/8/16.
//  Copyright © 2016 Victor Young. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <deque>
using namespace std;
int a[27];

int main(){

    if(freopen("/Users/Victor/Desktop/output.txt", "w", stdout) == NULL)
        fprintf(stderr,"error redirecting stdout\n");
    if(freopen("/Users/Victor/Desktop/A-large.in", "r", stdin) == NULL)
        fprintf(stderr,"error redirecting stdin\n");
    
    int n;
    cin >>n;
    for (int i = 0; i<n; i++) {
        int test;
        cin >> test;
        memset(a, 0, sizeof(int)*27);
        for (int j = 0; j<test; j++) {
            cin >> a[j];
        }
        
        cout << "Case #"<<i+1<<":";
        while (1) {
            int max = 0;
            int sum = 0;
            int maxindex = 0;
            for (int j = 0; j<test; j++) {
                sum += a[j];
                if (max<a[j]) {
                    max = a[j];
                    maxindex = j;
                }
            }
            if (sum==0) {
                break;
            }
            a[maxindex]--;
//            cout << maxindex<<endl;
            cout << " "<<(char)('A'+maxindex);
            if (sum!=3) {
                int max2 = 0;
                int maxindex2 = 0;
                for (int j = 0; j<test; j++) {
                    if (max2<a[j]) {
                        max2 = a[j];
                        maxindex2 = j;
                    }
                }
                cout <<(char)('A'+maxindex2);
                a[maxindex2]--;
            }

        }
        cout << endl;

        
    }
    return 0;

}