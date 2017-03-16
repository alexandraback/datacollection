//
//  main.cpp
//  code_jam_q1
//
//  Created by Nolan Miller on 4/12/14.
//  Copyright (c) 2014 Nolan Miller. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

set<int> intersection(const set<int>& s1, const set<int> &s2){
    set<int> ret;
    set<int>::iterator it;
    for (it = s1.begin(); it!=s1.end(); it++) {
        if (s2.find(*it)!=s2.end()) {
            ret.insert(*it);
        }
    }
    return ret;
}

int main(int argc, const char * argv[])
{
    int c;
    cin>>c;
    for (int i = 0; i<c; i++) {
        set<int> first;
        set<int> second;
        int card;
        int row;
        cin>>row;
        for (int ii = 0;ii<16 ; ii++) {
            cin>>card;
            if (ii/4+1==row) {
                first.insert(card);
            }
        }
        cin>>row;
        for (int ii = 0;ii<16 ; ii++) {
            cin>>card;
            if (ii/4+1==row) {
                second.insert(card);
            }
        }
        set<int> ans = intersection(first, second);
        cout<<"Case #"<<i+1<<": ";
        if (ans.size() == 0) {
            cout<<"Volunteer cheated!";
        }
        else if (ans.size()>1){
            cout<<"Bad magician!";
        }
        else{
            cout<<*ans.begin();
        }
        if(i!=c-1)
            cout<<endl;
    }
    return 0;
}


