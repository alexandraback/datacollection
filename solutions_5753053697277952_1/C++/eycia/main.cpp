//
//  main.cpp
//  gcj1ca
//
//  Created by eycia on 16/5/8.
//  Copyright © 2016年 eycia. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, char> > q;

int v[30];

void work() {
    while (!q.empty()) q.pop();
    
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        q.push(make_pair(v[i], 'A' + i));
    }
    
    char c1 = q.top().second;
    q.pop();
    char c2 = q.top().second;
    q.pop();
    
    for (int i = v[c2-'A']; i <= v[c1-'A']-1; i++) {
        printf("%c ", c1);
    }
    
    for (char i = 'A'; i <= 'A'+n-1; i++) {
        if (i != c1 && i != c2) {
            for (int j = 0; j < v[i-'A']; j++) {
                printf("%c ", i);
            }
        }
    }
    
    for (int i = 0; i < v[c2-'A']; i++) {
        printf("%c%c ", c1, c2);
    }
}

int main(int argc, const char * argv[]) {
    freopen("/Users/eycia/Downloads/A-small-attempt0 (1).in", "r", stdin);
    freopen("/Users/eycia/Desktop/oo", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        work();
        puts("");
    }
}
