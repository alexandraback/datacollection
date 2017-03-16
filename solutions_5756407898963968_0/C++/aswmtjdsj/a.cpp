#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)

#define MULTIPLE "Bad magician!"
#define NOANS "Volunteer cheated!"

typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int inf = INT_MAX;

int main(){
    int T;
    cin >> T;
    for(int c = 1; c <= T; c++) {
        int r1, r2;
        cin >> r1;
        int mat1[4][4], mat2[4][4];
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cin >> mat1[i][j];
            }
        }
        cin >> r2;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cin >> mat2[i][j];
            }
        }
        int count = 0, ans = -1;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(mat1[r1-1][i] == mat2[r2-1][j]) {
                    count++;
                    ans = i;
                }
            }
        }
        printf("Case #%d: ", c);
        if(count == 1) {
            printf("%d\n", mat1[r1-1][ans]);
        }
        else if(count > 1) {
            puts(MULTIPLE);
        }
        else {
            puts(NOANS);
        }
    }
}
