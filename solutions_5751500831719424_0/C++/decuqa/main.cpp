//
//  main.cpp
//  GoogleJam
//
//  Created by Alexandre Decuq on 24/03/14.
//  Copyright (c) 2014 Alexandre Decuq. All rights reserved.
//

//#include "main.h"

#include <vector>
#include <set>
#include <map> //set_intersection()
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <cassert>
#include <iomanip> //for setprecision()
#include <cmath> //ceil() or floor()

using namespace std; //std::to_string(int)

#define DEBUG 1

int main()
{
    int T;
    scanf("%d", &T);
    
    for(int t=1; t<=T; t++)
    {
        int n;
        scanf("%d ", &n);
        string word1, word2;
        cin >>word1;
        cin >>word2;
        
        if(word1==word2) {
            printf("Case #%d: 0\n", t);
            continue;
        } else if (word1[0]!=word2[0]) {
            printf("Case #%d: Fegla Won\n", t);
            continue;
        }
        
        int i = 0, j = 0;
        long long res=0;
        int possible=true;
        while (i!=word1.size() || j!=word2.size()) {
            if(word1[i]==word2[j]) {
                ++i;
                ++j;
            } else {
                if(word1[i]==word2[j-1]) {
                    while(i<word1.size() && word1[i]==word2[j-1]) {
                        ++res;
                        ++i;
                    }
                } else if (word2[j]==word1[i-1]) {
                    while(j<word2.size() && word2[j]==word1[i-1]) {
                        ++res;
                        ++j;
                    }
                }
                else {
                    possible=false;
                    break;
                }
            }
        }
        if(!possible) {
            printf("Case #%d: Fegla Won\n", t);
        }
        else if(i!=word1.size()||j!=word2.size()) {
            printf("Case #%d: Fegla Won\n", t);
        } else {
            printf("Case #%d: %lld\n", t, res);
        }
        
        
    }
}


