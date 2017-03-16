//
//  main.cpp
//  Senate Evacuation
//
//  Created by Qiu Xin on 8/5/16.
//  Copyright © 2016 Qiu Xin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    int runNum, length;
    cin >> runNum;
    for (int i=1;i<=runNum;i++)
    {
        int sameNo=0, max, max1=-1, max2=-1, sum=0;
        cin>>length;
        vector<int> store(length,0);
        for (int j=0;j<length;j++)
        {
            cin>>store[j];
            sum+=store[j];
        }
        cout<<"Case #"<<i<<":";
        while (sum!=0)
        {
            sameNo=0;
            max=-1;
            max1=-1;
            max2=-1;
            for (int j=0;j<length;j++)
                if (store[j]>max)
                {
                    max=store[j];
                    max1=j;
                    sameNo=1;
                }
                else
                    if (store[j]==max)
                    {
                        max2=j;
                        sameNo++;
                    }
            if (sameNo==2)
            {
                cout<<' '<<char('A'+max1)<<char('A'+max2);
                store[max1]--;
                store[max2]--;
                sum-=2;
                continue;
            }
            cout<<' '<<char('A'+max1);
            store[max1]--;
            sum--;
        }
        cout<<endl;
    }
    return 0;
}
