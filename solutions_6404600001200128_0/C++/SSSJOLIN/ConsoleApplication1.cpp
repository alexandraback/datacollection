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
    fin.open("F:/A-small-attempt1.in");
    ofstream fout;
    fout.open("F:/output1.txt");

    int T;
    if (file)fin >> T;
    else
        cin >> T;
    for (int i = 0; i < T; ++i){
        int N;
        if (file)fin >> N;
        else cin >> N;

        vector<int> cake(N, 0);

        int sum1 = 0, sum2 = 0;
        int maxdif = 0;
        for (int j = 0; j < N; ++j){
            if (file) fin >> cake[j];
            else cin >> cake[j];
            
            if (j){
                if ((cake[j - 1] - cake[j])>0)
                    sum1 += cake[j - 1] - cake[j];

                maxdif = max(maxdif, cake[j - 1] - cake[j]);
            }
        }

        for (int j = 0; j < N-1; ++j){
            sum2 += min(maxdif,cake[j]);
                   
        }



        if (file)
            fout << "Case #" << i + 1 << ": " << sum1<<' '<<sum2 << endl;
        else
            cout << "Case #" << i + 1 << ": " << sum1 << ' ' << sum2 << endl;
    }
    fin.close();
    fout.close();

    return 0;
}