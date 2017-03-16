#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main() {
    string filename ("input_b");
    string line;
    ifstream file (filename);
    int k;

    //
    getline (file, line);
    k = stoi(line);

    for (int t = 0; t < k; t++) {   //for each test case
        int r, c, n;

        // parsing
        getline (file, line);

        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                r = stoi(line.substr(0, i));
                line = line.substr(i + 1, line.size() - i - 1);
            }
        }

        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                c = stoi(line.substr(0, i));
                n = stoi(line.substr(i + 1, line.size() - i - 1));
            }
        }

        // main
        if (n <= ceil(r*c/2)) {
            cout << "Case #" << t+1 << ": 0\r\n";
            continue;
        }

        int res = 0;
        int corner;
        if (r*c%2 == 0)
            corner = 2;
        else
            corner = 4;
        int edge = (r + c - 1) * 2 - corner;
        int left = floor(r*c/2);

        res = res + min(left, corner) * 2;
        left = left - min(left, corner);

        res = res + min(left, edge) * 3;
        left = left - min(left, edge);

        res = res + left * 4;

        cout << "Case #" << t+1 << ": " << res << "\r\n";
    }

    return 0;
}