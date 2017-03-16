//
//  main.cpp
//  2B
//
//  Created by Xiaowei Ma on 20/02/2014.
//  Copyright (c) 2014 Xiaowei Ma. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;



int main()
{
    ifstream inFile;
    inFile.open("/Users/xiaoweima/Desktop/2B/2B/in.in");
    
    ofstream outFile;
    outFile.open("/Users/xiaoweima/Desktop/2B/2B/out.out");
    
    
    int T;
    inFile>>T;
    
    for (int ca = 1; ca <= T; ca++)
    {
        int ans1, ans2;
        int a[5][5];
        int b[5][5];
        
        inFile>>ans1;
        
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                inFile>>a[i][j];
            }
        }
        
        inFile>>ans2;
        
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                inFile>>b[i][j];
            }
        }
        
        vector<int> ans;
        
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                if (a[ans1][i] == b[ans2][j])
                {
                    ans.push_back(a[ans1][i]);
                }
            }
        }
        
        if (ans.size() == 0)
            outFile<<"Case #"<<ca<<": "<<"Volunteer cheated!"<<endl;
        else if (ans.size() == 1)
            outFile<<"Case #"<<ca<<": "<<ans[0]<<endl;
        else
            outFile<<"Case #"<<ca<<": "<<"Bad magician!"<<endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}

