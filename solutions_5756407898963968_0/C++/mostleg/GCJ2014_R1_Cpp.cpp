// GCJ2014_R1_Cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int T;

string solve_it()
{
    int row1, row2;
    int card1[5][5], card2[5][5];

    cin >> row1;
    for (int i=1; i<=4; i++) {
        for (int j=1; j<=4; j++) {
            cin >> card1[i][j];
        }
    }
    cin >> row2;
    for (int i=1; i<=4; i++) {
        for (int j=1; j<=4; j++) {
            cin >> card2[i][j];
        }
    }

    bool once = false;
    int ans = 0;
    for (int i=1; i<=4; i++) {
        for (int j=1; j<=4; j++) {
            if (card1[row1][i] == card2[row2][j]) {
                if (once) {
                    return "Bad magician!";
                }
                once = true;
                ans = card1[row1][i];
            }
        }
    }
    if (!once) {
        return "Volunteer cheated!";
    }
    stringstream ss;
    ss << ans;
    return ss.str();
}

int _tmain(int argc, _TCHAR* argv[])
{
    freopen("D:\\workspace\\LearnComp\\GCJ2014_R1_Cpp\\A-small-attempt0.in", "rb", stdin);
    freopen("D:\\workspace\\LearnComp\\GCJ2014_R1_Cpp\\A-small-attempt0.out", "wb", stdout);
    cin >> T;
    for (int ca=1; ca<=T; ca++)
    {
        cout << "Case #" << ca << ": " << solve_it() << endl;
    }
	return 0;
}

