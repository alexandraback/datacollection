#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
using namespace std;

#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)

char* getCh[] = {"A", "B","C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

bool getH( int* P, int N, int& h, vector<int>& hIdx, int& sh, vector<int>& shIdx) {
    h = 0;
    sh = 0;
    hIdx.clear();
    shIdx.clear();
    F0(i, N) {
        if(P[i]>h) {
            if(h>0) {
                sh = h;
                shIdx = hIdx;
            }
            hIdx.clear();
            h = P[i];
            hIdx.push_back(i);
        } else if(P[i]==h) {
            hIdx.push_back(i);
        }
        else if(P[i]==sh) {
            shIdx.push_back(i);
        }
    }

    return (h>0);
}

int main() {
    int T;
    int N;
    int P[26];
    cin >> T;
    F1(c, T) {
        cin >> N;
        F0(i,N) {
            cin >> P[i];
        }
        int h;
        int sh;
        vector<int> hIdx;
        vector<int> shIdx;
        string ans("");
        while(getH(P,N, h,hIdx,sh, shIdx)) {
            if(hIdx.size()==2) {
                ans = ans + getCh[hIdx[0]] + getCh[hIdx[1]] + " ";
                P[hIdx[0]]--;
                P[hIdx[1]]--;
            } else {
                ans = ans + getCh[hIdx[0]] + " ";
                P[hIdx[0]]--;
            }
        }
        cout << "Case #" << c << ": " << ans;
        cout << endl;
    }


}
