#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <climits>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <functional>
#include <iterator>
#include <complex>
#include <queue>
#include <cassert>
#include <sstream>
#include <cstdlib>

using namespace std;

double pi = acos((double) -1);

int main() {
    clock_t tStart = clock();
    int tests = 1;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int n;
        scanf("%d", &n);
        string str1, str2;
        vector<char> character1, character2;
        vector<int> counter1, counter2;

        cin >> str1 >> str2;
        for (int j = 0; j < str1.length(); j++) {
            if (character1.size() == 0 || character1.back() != str1[j]) {
                character1.push_back(str1[j]);
                counter1.push_back(1);
            }
            else {
                counter1[counter1.size() - 1]++;
            }
        }
        for (int j = 0; j < str2.length(); j++) {
            if (character2.size() == 0 || character2.back() != str2[j]) {
                character2.push_back(str2[j]);
                counter2.push_back(1);
            }
            else {
                counter2[counter2.size() - 1]++;
            }
        }

        bool similar = true;
        int diff = 0;
        if (character1.size() != character2.size()) {
            similar = false;
        }
        else {
            for (int i = 0; i < character1.size(); i++) {
                if (character1[i] != character2[i]) {
                    similar = false;
                    break;
                }
                diff += abs(counter1[i] - counter2[i]);
            }
        }

        if (!similar) {
            cout << "Case #" << test << ": Fegla Won\n";
        }
        else {
            cout << "Case #" << test << ": " << diff << endl;
        }
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
