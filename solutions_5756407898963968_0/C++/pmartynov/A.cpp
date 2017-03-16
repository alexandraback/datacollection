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
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int x, y;
        scanf("%d", &x);
        x--;
        int **first = new int*[4];
        for (int i = 0; i < 4; i++) {
            first[i] = new int[4];
            for (int j = 0; j < 4; j++) {
                scanf("%d", &first[i][j]);
            }
        }

        scanf("%d", &y);
        y--;
        int **second = new int*[4];
        for (int i = 0; i < 4; i++) {
            second[i] = new int[4];
            for (int j = 0; j < 4; j++) {
                scanf("%d", &second[i][j]);
            }
        }

        vector<int> first_row;
        for (int i = 0; i < 4; i++) {
            first_row.push_back(first[x][i]);
        }

        int counter = 0, num = -1;
        for (int i = 0; i < 4; i++) {
            if (find(first_row.begin(), first_row.end(), second[y][i]) != first_row.end()) {
                counter++;
                num = second[y][i];
            }
        }

        if (counter == 1) {
            printf("Case #%d: %d\n", test, num);
        }
        else if (counter == 0) {
            printf("Case #%d: Volunteer cheated!\n", test);
        }
        else {
            printf("Case #%d: Bad magician!\n", test);
        }
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
