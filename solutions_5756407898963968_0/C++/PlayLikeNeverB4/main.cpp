#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
#include <utility>

using namespace std;

#define MAXN 5

int T, F, S;
int A[MAXN][MAXN];
int P[MAXN * MAXN];

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);
	
	cin >> T;
	for(int t = 1; t <= T; t++) {
        cin >> F; F--;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin >> A[i][j];
        memset(P, 0, sizeof(P));
        for(int j = 0; j < 4; j++)
            P[ A[F][j] ]++;
        
        cin >> S; S--;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin >> A[i][j];
        int ways = 0;
        int last = -1;
        for(int j = 0; j < 4; j++)
            if(P[ A[S][j] ] > 0) {
                ways++;
                last = A[S][j];
            }
        
        cout << "Case #" << t << ": ";
        
        if(ways == 1) {
            cout << last;
        }
        else if(ways == 0) {
            cout << "Volunteer cheated!";
        }
        else {
            cout << "Bad magician!";
        }
        
        cout << '\n';
	}
	
	return 0;
}
