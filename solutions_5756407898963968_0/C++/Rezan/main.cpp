//
//  main.cpp
//  Bad Magician
//
//  Created by Zulkarnine on 4/12/14.
//  Copyright (c) 2014 Zulkarnine Mahmud. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <deque>
#include <list>

using namespace std;

#define nl cout<<endl

const string badM="Bad magician!";
const string cheater="Volunteer cheated!";

void solvecase(int row_1,vector< vector<int> >seq1, int row_2,vector< vector<int> >seq2){
    int row1=row_1-1;
    int row2=row_2-1;
    
    int match=0;
    
    int result=-1;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (seq1[row1][i]==seq2[row2][j]) {
                result=seq1[row1][i];
                match++;
            }
        }
    }
    
    if (match==0) {
        cout<<cheater;
    }else if (match==1){
        cout<<result;
    }else{
        cout<<badM;
    }
    
    cout<<"\n";
}



int main(int argc, const char * argv[])
{
    int T,cas=0;
    //test
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small-attempt2.out", "w", stdout);
    
    
    cin>>T;
    while (T--) {
        int row1;
        cin>>row1;
        int card;
        vector< vector<int> > seq1;
        for (int i=0; i<4; i++) {
            vector<int> tempvec;
            for (int j=0; j<4; j++) {
                cin>>card;
                tempvec.push_back(card);
            }
            seq1.push_back(tempvec);
        }
        
        int row2;
        cin>>row2;
        vector< vector<int> > seq2;
        for (int i=0; i<4; i++) {
            vector<int> tempvec;
            for (int j=0; j<4; j++) {
                cin>>card;
                tempvec.push_back(card);
            }
            seq2.push_back(tempvec);
        }
        
        printf("Case #%d: ",++cas);
        solvecase(row1, seq1, row2, seq2);
        
    }
    
    
    return 0;
}
