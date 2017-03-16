//
//  main.cpp
//  GCJ
//
//  Created by Keno on 2015/04/11.
//  Copyright (c) 2015年 Keno. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

struct tree {
    double x;
    double y;
};

double outerProduct(tree vec1, tree vec2) {
    return vec1.x * vec2.y - vec1.y * vec2.x;
}


int main(int argc, const char * argv[]) {
    
    ifstream fin;
//    fin.open("example.txt", ios::in);
    fin.open("C-small-attempt2.in.txt", ios::in);
    
    ofstream fout;
    fout.open("output-C-s2.txt", ios::out);
    
    string out;
    
    // read parameters and calculate
    
    int T;
    fin >> T;
    
    for (int i = 0; i < T; i++) {
        int N;
        fin >> N;
        
        vector <tree>a;
        
        for(int j = 0; j < N; j++) {
            double x;
            double y;
            fin >> x;
            fin >> y;
            a.push_back(tree{x, y});
        }
        
        vector <int>result;
        
        for(int j = 0; j < N; j++) {
            int minLeft = 3000;
            int minRight = 3000;
            for (int k = 0; k < N; k++) {
                if (k == j) {
                    continue;
                }
                tree t1 = a[j];
                tree t2 = a[k];
                tree v1 = tree{t2.x - t1.x, t2.y - t1.y};
//                cout << "base vector (" << j << " to " << k << ")" << v1.x << ", " << v1.y << endl;
                int left = 0;
                int right = 0;
                for (int l = 0; l < N; l++) {
                    tree t3 = a[l];
                    if (l == j || l == k) {
                        continue;
                    }
                    tree v2 = tree{t3.x - t1.x, t3.y - t1.y};
                    double o = outerProduct(v1, v2);
//                    cout << "calc (" << j << " to " << l << ")" << v2.x << ", " << v2.y << "is " << (o > 0 ? "1" : (o == 0 ? "0" : "-1" )) << endl;
                    if (o < 0.0) {
                        left++;
                    } else if (o > 0.0) {
                        right++;
                    }
                }
                minLeft = min(minLeft, left);
                minRight = min(minRight, right);
                if (minLeft == 0 || minRight == 0) {
                    break;
                }
            }
            result.push_back(min(minLeft, minRight));
        }
        
        fout << "Case #" << (i+1) << ":" << endl;
        if (N == 1) {
            fout << 0 << endl;
        } else {
            for (int j = 0; j < N; j++) {
                fout << result[j] << endl;
            }
        }
    }
    
    fin.close();
    fout.close();
    
    return 0;
}
