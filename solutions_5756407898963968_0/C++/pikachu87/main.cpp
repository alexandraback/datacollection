//
//  main.cpp
//  TaskC
//
//  Created by Quoc-Huy Tran on 12/04/2014.
//  Copyright (c) 2014 *. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    
    int r1, r2, foo;
    int A1[4], A2[4];
    vector<int> nums;
    for (int k=0; k<T; k++) {
        cin>>r1;
        for (int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                if (i+1 == r1)
                    cin>>A1[j];
                else
                    cin>>foo;
        
        cin>>r2;
        for (int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                if (i+1 == r2)
                    cin>>A2[j];
                else
                    cin>>foo;
        
        nums.clear();
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++)
                if (A1[i] == A2[j]) {
                    nums.push_back(A1[i]);
                    break;
                }
        }
        
        if (nums.empty())
            cout<<"Case #"<<k+1<<": Volunteer cheated!"<<endl;
        else if (nums.size() == 1)
            cout<<"Case #"<<k+1<<": "<<nums[0]<<endl;
        else if (nums.size() > 1)
            cout<<"Case #"<<k+1<<": Bad magician!"<<endl;
    }
        
    return 0;
}

