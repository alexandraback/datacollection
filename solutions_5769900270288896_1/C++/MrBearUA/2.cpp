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
//B-small-attempt0
#define IN_NAME ("/Users/andriymedvid/Documents/GCM-out/B-large.in")
#define OUT_NAME ("/Users/andriymedvid/Documents/GCM-out/B-large.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

int main(int argc, const char * argv[]) {
    
    freopen(IN_NAME, "r", stdin);
    freopen(OUT_NAME, "w", stdout);
    
    int T;
    
    cin >> T;
    
    for(int tIter = 0; tIter < T; tIter++) {
        
        int r,c,n;
        
        cin >> r >> c >> n;
        
        OutCase(tIter);
        // out answer
        
        if((r*c + 1) / 2 >= n)
            cout << 0;
        else {
            if(r == 1 || c == 1) {
                cout << (r*c - 1) - (r*c - n)*2;
            } else {
            
                int flats = r*c - n;
                int totalWalls = (r - 1) * c + (c - 1) * r;
                
                int foursFlats = ((r-2)*(c-2) + 1) / 2;
                
                int fours = min(flats, foursFlats);
                totalWalls -= fours * 4;
                flats -= fours;
                
                if(flats > 0) {
                    int threesFlats = ((r-2) / 2) * 2 + ((c-2) / 2) * 2;
                    int threes = min(flats, threesFlats);
                    totalWalls -= threes * 3;
                    flats -= threes;
                    
                    if(flats > 0)
                        totalWalls -= 2*flats;
                }
                
                
                int flats2 = r*c - n;
                int totalWalls2 = (r - 1) * c + (c - 1) * r;
                
                int foursFlats2 = (r-2)*(c-2) / 2;
                
                int fours2 = min(flats2, foursFlats2);
                totalWalls2 -= fours2 * 4;
                flats2 -= fours2;
                
                if(flats2 > 0) {
                    int threesFlats2 = ((r-1) / 2) * 2 + ((c-1) / 2) * 2;
                    int threes2 = min(flats2, threesFlats2);
                    totalWalls2 -= threes2 * 3;
                    flats2 -= threes2;
                    
                    if(flats2 > 0)
                        totalWalls2 -= 2*flats2;
                }
                
                cout << min(totalWalls, totalWalls2);
            }
            
        }
        
        cout << endl;
    }
    
    return 0;
}


