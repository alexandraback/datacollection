#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <memory.h>

using namespace std;

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    cin >> T;
    for (int z = 0; z < T; z++) {
        int a1;
        cin >> a1;
        a1--;
        vector<int> res1;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                int num;
                cin >> num;
                if (a1 == i) {

                    res1.push_back(num);
                }
            }
        int a2;
        cin >> a2;
        a2--;
        vector<int> res2;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                int num;
                cin >> num;
                if (a2 == i) {
                    res2.push_back(num);
                }
            }

        int k = 0;
        int res = 0;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(res1[i] == res2[j]) {
                    k++;
                    res = res1[i];
                }


        printf("Case #%d: ", z + 1);
        if (k == 0)
            printf("Volunteer cheated!");
        else if (k == 1)
            printf("%d", res);
        else
            printf("Bad magician!");

        printf("\n");
    }
    return 0;
}

