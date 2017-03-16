//
//  main.cpp
//  code_jam_qualification_round
//
//  Created by hijackyan on 4/11/15.
//  Copyright (c) 2015 hackerrank. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int T;
    cin>>T;
    int case_number = 1;
    while(T--)
    {
        int n, i, j, temp;
        vector<int> food;
        cin>>n;
        int result1 = 0;
        int result2 = 0;
        int max_diff = 0;
        for(i = 0; i < n; i++)
        {
            cin>>temp;
            food.push_back(temp);
            if(i > 0)
            {
                result1 += max(0, food[i-1] - food[i]);
                max_diff = max(max_diff, food[i-1] - food[i]);
            }
        }
        for(i = 0; i < n-1; i++)
        {
            result2 += min(food[i], max_diff);
        }
        cout<<"Case #"<<case_number++<<": "<<result1<<" "<<result2<<endl;
    }
}
