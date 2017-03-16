#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int file = 1;
    ifstream fin;
    fin.open("F:/B-small-attempt0 (1).in");
    ofstream fout;
    fout.open("F:/output1.txt");

    int T;
    if (file)fin >> T;
    else
        cin >> T;
    for (int i = 0; i < T; ++i){
        long long B,N;
        if (file)fin >>B>> N;
        else cin >>B>> N;

        vector<long long> mk(B, 0);

        long long mul = 1;
        for (int j = 0; j < B; ++j){
            if (file) fin >> mk[j];
            else cin >> mk[j];
            if (mul%mk[j])
                mul *= mk[j];
        }
        long long basenum = 0;
        for (int j = 0; j < B; ++j){
            basenum += mul / mk[j];
        }

        N = N%basenum;
        int ans = 0;
        if (N == 0)
            N=basenum;
        
        for (int t = 0;N!=0 ; ++t){
            for (int k = 0; k < B; ++k){
                if (t%mk[k] == 0){
                    N--;
                    if (N == 0){
                        ans = k + 1;
                        break;
                    }
                }
            }
            if (ans)
                break;
        }


        if (file)
            fout << "Case #" << i + 1 << ": " << ans << endl;
        else
            cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    fin.close();
    fout.close();

    return 0;
}