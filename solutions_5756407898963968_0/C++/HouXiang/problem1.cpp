// problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std; 

int _tmain(int argc, _TCHAR* argv[])
{
    ifstream inf (argv[1]);

    int cases; 
    inf >> cases; 

    for (int ca=1; ca<=cases; ca++){
        int row1, row2; 
        inf >> row1; 

        vector<int> line1, line2; 
        for (int i=0; i<16; i++) {
            int k; 
            inf >> k; 
            if (i >= (row1 - 1) * 4 && i < (row1 * 4)) line1.push_back(k);
        }

        inf >> row2; 

        for(int i=0; i<16; i++) {
            int k; 
            inf >> k; 
            if (i >=(row2-1)*4 && i<row2*4) line2.push_back(k);
        }

        int num, times=0; 
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (line1[i] == line2[j]) {
                    num = line1[i]; 
                    times++;
                    break;
                }
            }
        }

        if (times == 1) {
            cout << "Case #"<<ca<<": " << num << endl;
        }
        else if (times == 0) {
            cout << "Case #" << ca << ": Volunteer cheated!" << endl;
        }
        else {
            cout << "Case #" << ca << ": Bad magician!" << endl;
        }
    }

	return 0;
}

