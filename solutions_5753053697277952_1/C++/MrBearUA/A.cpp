//
//  main.cpp
//  FHC_Pattern
//
//  Created by Andriy Medvid on 11.01.15.
//  Copyright (c) 2015 Andriy Medvid. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define MAX_NUM 1000000000


//#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/A.in")
//#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/A.out")

#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/A-large.in")
#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/A-large.out")

//#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/A-small-attempt0.in")
//#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/A-small-attemp0.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

int n;

struct Party {
    char name;
    int count;
};

vector <Party> parties;

bool comparator(Party p1, Party p2) {
    return p2.count < p1.count;
}

void iteration() {
    cin >> n;
    
    parties.clear();
    
    int help;
    
    for(int i = 0; i < n; i++) {
        cin >> help;
        
        Party p;
        p.name = 'A' + i;
        p.count = help;
        
        parties.push_back(p);
    }
    
    sort(parties.begin(), parties.end(), comparator);
    
    while(parties[0].count > 0) {
        cout << " " << parties[0].name;
        parties[0].count--;
        
        if(parties.size() >= 3 && parties[0].count == 0 && parties[2].count == 1 && (parties.size() == 3 || parties[3].count == 0)) {
            // bad situation
        } else {
        
            if(parties[0].count < parties[1].count) {
                cout << parties[1].name;
                parties[1].count--;
            } else if(parties[0].count > parties[1].count) {
                cout << parties[0].name;
                parties[0].count--;
            }
        }
        
        sort(parties.begin(), parties.end(), comparator);
    }
    
}

int main(int argc, const char * argv[]) {
    
    freopen(IN_NAME, "r", stdin);
    freopen(OUT_NAME, "w", stdout);
    
    int T;
    
    cin >> T;
    
    for(int tIter = 0; tIter < T; tIter++) {
        
        
        OutCase(tIter);
        
        iteration();
        
        cout << endl;
    }
    
    return 0;
}


