#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int solve(vector<int> line1, vector<int> line2) {
    int cnt = 0;
    int answer = 0;


    for (const auto n1 : line1) {
        for (const auto n2 : line2) {
            if (n1 == n2) {
                cnt++;
                answer = n1;
                break;
            }
        }
    }

    if (cnt > 1)
        return 17;
    else if (cnt == 0)
        return 0;
    return answer;
}

int main() {
    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test) {
        vector<int> line1, line2;

        int lineNum;
        cin >> lineNum;

        int buf;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> buf;
                if (i+1 == lineNum)
                    line1.push_back(buf);
            }
        }

        cin >> lineNum;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> buf;
                if (i+1 == lineNum)
                    line2.push_back(buf);
            }
        }

        int answer = solve(line1, line2);
        if (answer == 0) 
            printf("Case #%d: Volunteer cheated!\n", test);
        else if (answer == 17)
            printf("Case #%d: Bad magician!\n", test);
        else
            printf("Case #%d: %d\n", test, answer);
    }

    return 0;
}
