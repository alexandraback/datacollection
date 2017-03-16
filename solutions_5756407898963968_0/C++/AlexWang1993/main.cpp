//
//  main.cpp
//  MagicTrick
//
//  Created by Alex Wang on 4/11/2014.
//  Copyright (c) 2014 Alex Wang. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;
int a[4][4];
int main(int argc, const char * argv[])
{
    int n,t;
    cin>>t;
    for (int i=0;i<t;i++){
        cin>>n;
        n--;
        set<int> s;
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                cin>>a[i][j];
            }
        }
        for (int i=0;i<4;i++){
            s.insert(a[n][i]);
        }
        cin>>n;
        n--;
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                cin>>a[i][j];
            }
        }
        set<int> s1;
        for (int i=0;i<4;i++){
            s1.insert(a[n][i]);
        }
        cout<<"Case #"<<i+1<<": ";
        set<int> ss;
        set_intersection(s1.begin(),s1.end(),s.begin(),s.end(),
                         std::inserter(ss,ss.begin()));
        if (ss.size()==1){
            cout<<*ss.begin();
        } else if (ss.size()==0){
            cout<<"Volunteer cheated!";
        } else if (ss.size()>1){
            cout<<"Bad magician!";
        }
        cout<<endl;
    }
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}

