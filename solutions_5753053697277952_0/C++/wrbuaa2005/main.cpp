//
//  main.cpp
//  try
//
//  Created by Ran Wang on 4/18/15.
//  Copyright (c) 2015 Ran Wang. All rights reserved.
//

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <queue>
#include <iomanip>
#include <cmath>
#include <limits>

#define REP(i,N) for(int (i)=0;(i)<(N);(i)++)

using namespace std;

int main()
{
    int T;
    cin >> T;
    REP(caset, T)
    {
        int N;
        cin >> N;
        vector<int> num;
        int sum = 0;
        while(N--)
        {
            int tmp;
            cin >> tmp;
            num.push_back(tmp);
            sum+= tmp;
        }
        
        cout << "Case #" << caset + 1 << ":";
        
        while(sum)
        {
            cout << ' ';
            char c;
            int acc = 0;
            REP(i, num.size())
            {
                if(num[i] * 2 == sum) {
                    c = i +'A';
                    cout << c;
                    acc++;
                    num[i]--;
                }
            }
            
            sum-=acc;
            if(acc)
                continue;
            
            REP(i, num.size())
            {
                if(num[i])
                {
                    c = i + 'A';
                    cout << c;
                    sum--;
                    num[i]--;
                    break;
                }
            }
        }
        
        cout << endl;
    }
}