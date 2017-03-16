//
//  main.cpp
//  1C_A
//
//  Created by Estelle :) on 08/05/2016.
//  Copyright © 2016 Estelle :). All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int k=1; k<=T; k++) {
        int n;
        scanf("%d", &n);
        printf("Case #%d:", k);
        set<pair<int, int> > s;
        int tot=0;
        for (int i=0; i<n; i++) {
            int a;
            scanf("%d", &a);
            s.insert(make_pair(-a,i));
            tot+=a;
        }
        bool odd = tot&1;
        while (!s.empty()) {
            set<pair<int, int> >::iterator it=s.begin(), it2=it;
            it2++;
            //printf("%d %d %d %d\n", it->first, it->second, it2->first, it2->second);
            if (odd && (-it2->first)*2<tot) {
                odd=false;
                pair<int, int> ins=*it;
                ins.first++;
                printf(" %c", 'A'+ins.second);
                s.erase(it);
                if (ins.first!=0) s.insert(ins);
                tot--;
            }
            else {
                pair<int, int> ins1=*it, ins2=*it2;
                ins1.first++, ins2.first++;
                printf(" %c%c", 'A'+ins1.second, 'A'+ins2.second);
                s.erase(it);
                s.erase(it2);
                if (ins1.first!=0) s.insert(ins1);
                if (ins2.first!=0) s.insert(ins2);
                tot-=2;
            }
        }
        printf("\n");
    }
}
