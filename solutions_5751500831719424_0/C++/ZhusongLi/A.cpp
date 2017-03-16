#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;


long long solve(vector<int> &tem) {
    long long big = -1;
    long long small = -1;
    int n1,n2;
    for (n1 = 0;n1 < tem.size();n1++) {
        if (big == -1 || tem[n1] > big) big = tem[n1];
        if (small == -1 || tem[n1] < small) small = tem[n1];
    }
    long long result = -1;
    for (n2 = small;n2 <= big;n2++) {
        long long Q = 0;
        for (n1 = 0;n1 < tem.size();n1++) {
            Q = Q + abs(tem[n1] - n2);
        }
        if (result == -1 || Q < result) result = Q;
    }
    return result;
}

int main() {
    ifstream filein;
    ofstream fileout;
    //filein.open("A.in",ios::in);
    filein.open("A-small-attempt1.in",ios::in);
    //filein.open("A-large.in",ios::in);
    fileout.open("output",ios::out);
    int T;
    filein >> T;
    for (int i = 0;i < T;i++) {
        fileout << "Case #" << i+1 << ": ";
        int N;
        int n1,n2,n3;
        char K;
        filein >> N;
        vector<string> data(N);
        vector<int> temps;
        vector<vector<int> > store(N,temps);
        vector<char> pos;
        for (n1 = 0;n1 < N;n1++) filein >> data[n1];
        int count = 1;
        pos.push_back(data[0][0]);
        for (n1 = 1;n1 < data[0].size();n1++) {
            if (data[0][n1] != data[0][n1-1]) {
                store[0].push_back(count);
                pos.push_back(data[0][n1]);
                count = 1;
            }
            else count++;
        }
        store[0].push_back(count);
        int sign = 0;
        for (n1 = 1;n1 < data.size();n1++) {
            if (sign == 1) break;
            string s = data[n1];
            n3 = 0;
            for (n2 = 0;n2 < pos.size();n2++) {
                K = pos[n2];
                if (n3 >= s.size() || s[n3] != K) {
                    sign = 1;
                    break;
                }
                count = 0;
                while (n3 < s.size() && s[n3] == K) {
                    count++;
                    n3++;
                }
                store[n1].push_back(count);
            }
            if (n3 != s.size()) sign = 1;
        }
        if (sign == 1) fileout << "Fegla Won" << endl;
        else {
            long long result = 0;
            for (n1 = 0;n1 < store[0].size();n1++) {
                vector<int> tem;
                for (n2 = 0;n2 < store.size();n2++) {
                    tem.push_back(store[n2][n1]);
                }
                result = result + solve(tem);
            }
            fileout << result << endl;
        }
    }
    fileout.close();
}