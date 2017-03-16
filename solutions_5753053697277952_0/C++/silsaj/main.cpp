//
//  main.cpp
//  codejam
//
//  Created by Silas on 2016. 5. 8..
//  Copyright © 2016년 Silas. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    
    for (int ti = 1; ti <= tc; ti++) {
        int n;
        cin >> n;
        int p[30] = {0, };
        for (int i = 0; i < n; i++)
            cin >> p[i];
        
        int n1, n2;
        n1 = 27;
        n2 = 28;
        p[27] = 0;
        p[28] = 0;
        for (int i = 0; i < n; i++) {
            if(p[i] > p[n1] && p[i] > p[n2]) {
                n2 = n1;
                n1 = i;
            }
            else if (p[i] > p[n2]) {
                n2 = i;
            }
        }
        
        printf("Case #%d: ", ti);
        while(p[n1] > p[n2]) {
            printf("%c ", 'A' + n1);
            p[n1]--;
        }
        for (int i = 0; i <= 'Z' - 'A'; i++) {
            if (i != n1 && i != n2) {
                while(p[i]) {
                    p[i]--;
                    printf("%c ", 'A' + i);
                }
            }
        }
        while(p[n1] && p[n2]) {
            p[n1]--;
            p[n2]--;
            printf("%c%c ", 'A' + n1, 'A' + n2);
        }
        printf("\n");
    }
}