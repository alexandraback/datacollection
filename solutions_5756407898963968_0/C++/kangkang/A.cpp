#include <cstdio>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

char input[100];
int value[256], vused;

int main() {
	int T;

    string s;
    istringstream iss;
    string filename("A.in");
    ifstream in(filename, ifstream::in);      
    if(!in){				              // ensure existence of file
        //cout<<"error: file "<<filename<<" does not exist\n";
        exit(-1);
    }
    getline(in, s);
    iss.str(s);
    iss >> T;	   
    //cout << T << " cases"<< endl;
    vector<vector<int> > board(4, vector<int>(4, 0));


    int one, two;
	for (int test = 1; test <= T; test++) {
        getline(in, s);
        iss.clear();
        iss.str(s);
        iss >> one;	
        //cout << one << endl;
        for(int i = 0; i < 4; i ++) {
            getline(in, s);
            iss.clear();
            iss.str(s);
            for(int j = 0; j < 4; j++) {
                iss >> board[i][j];
                //cout << board[i][j] << "  ";
            }
            //cout << endl;
        }

        //cout << "possible 1 : "; 
        vector<int> poss1( board[one-1]);
        for(int j = 0; j < 4; j++) {
                //cout << poss1[j] << "  ";
        }
        //cout << endl; 

        getline(in, s);
        iss.clear();
        iss.str(s);
        iss >> two;	
        //cout << two << endl;
        for(int i = 0; i < 4; i ++) {
            getline(in, s);
            iss.clear();
            iss.str(s);
            for(int j = 0; j < 4; j++) {
                iss >> board[i][j];
                //cout << board[i][j] << "  ";
            }
            //cout << endl;
        }
        //cout << "possible 2 : "; 
        vector<int> poss2( board[two-1]);
        for(int j = 0; j < 4; j++) {
                //cout << poss2[j] << "  ";
        }
        //cout << endl; 

        int ans = -1, found = 0;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(poss1[i] == poss2[j]) {
                    ans = poss1[i];
                    found ++;
                }
            }
        }


        if(found == 0)
            printf("Case #%d: Volunteer cheated!\n", test);
        if(found == 1)
            printf("Case #%d: %d\n", test, ans);
        if(found >= 2)
            printf("Case #%d: Bad magician!\n", test);


    }
}
