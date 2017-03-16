#include <iostream>
#include <cstdio>
#include <stdint.h>
//#include <boost/multiprecision/cpp_int.hpp>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
//using namespace boost::multiprecision;


int main(){
    int tests;
    string line;
    cin >> tests;
    for(int i1 = 0; i1 < tests; i1++){
        int r;
        cin >> r;
        getline(cin, line);
        r--;
        set<int> firstRound;
        for(int i2 = 0; i2 < 4; i2++){
            getline(cin, line);
            stringstream sLine(line);
            if(i2==r){
                for(int i3 = 0; i3 < 4; i3++){
                    int tmp;
                    sLine >> tmp;
                    firstRound.insert(tmp);

                }
            }
        }
        for(auto it1 = firstRound.begin(); it1 != firstRound.end(); it1++){
            cerr << *it1 << endl;
        }

        cin >> r;
        getline(cin, line);
        r--;
        set<int> secondRound;
        for(int i2 = 0; i2 < 4; i2++){
            getline(cin, line);
            stringstream sLine(line);
            if(i2==r){
                for(int i3 = 0; i3 < 4; i3++){
                    int tmp;
                    sLine >> tmp;
                    secondRound.insert(tmp);

                }
            }
        }
        for(auto it1 = secondRound.begin(); it1 != secondRound.end(); it1++){
            cerr << *it1 << endl;
        }
        vector<int> intersect(10);
        auto it1 = set_intersection(firstRound.begin(), firstRound.end(), secondRound.begin(), secondRound.end(), intersect.begin());
        int size = it1-intersect.begin();
        cout << "Case #" << i1+1 << ": ";
        switch(size){
            case 0: cout << "Volunteer cheated!" << endl;
                break;
            case 1: cout << intersect.front() << endl;
                break;
            default:
                cout << "Bad magician!" << endl;
        }
    }
}
