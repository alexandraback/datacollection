//
//  main.cpp
//  Codeforces
//
//  Created by Taygrim on 20.03.13.
//  Copyright (c) 2013 Taygrim. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;


int main()
{
    ifstream cin("A-small-attempt0.in.txt");
    ofstream cout("A-small-attempt0.out.txt");
    int T;
    cin >> T;
    for(int q = 0; q < T; q++)
    {
        bool flag = true;
        int n;
        cin >> n;
        string s;
        vector<vector<int> > numbers(n);
        
        
        string ss;
        cin >> ss;
        ss.push_back('\n');
        int prev = -1;
        for(int j = 0; j < ss.size(); j++) {
            if(j == 0 || ss[j] != ss[j-1])
            {
                s.push_back(ss[j]);
                numbers[0].push_back(j - prev);
                prev = j;
            }
        }
        
        for(int i = 1; i < n; i++)
        {
            cin >> ss;
            ss.push_back('\n');
            prev = -1;
            for(int j = 0; j < ss.size(); j++) {
                if(j == 0 || ss[j] != ss[j-1])
                {
                    if(s[numbers[i].size()] == ss[j])
                    {
                        numbers[i].push_back(j - prev);
                        prev = j;
                    } else
                        flag = false;
                        
                }
                
            }
                
        }
        
        cout<<"Case #" << q+1 << ": ";
        
        if(flag == true) {
            int res = 0;
            
            for(int i = 0; i < numbers[0].size(); i++) {
                int num = 0;
                for(int j = 0; j < numbers.size(); j++)
                    num += numbers[j][i];
                
                num /= numbers.size();
                int res1 = 0, res2 = 0;
                for(int j = 0; j < numbers.size(); j++) {
                    res1 += abs(numbers[j][i] - num);
                    res2 += abs(numbers[j][i] - (num + 1));
                }
                res+=min(res1, res2);
            }
            cout<<res;
        } else {
            cout<<"Fegla Won";
        }
        
        cout<<"\n";
        
    }
}