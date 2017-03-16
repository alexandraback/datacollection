#include <algorithm>
#include <iostream>
#include <fstream>
#include <cctype>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <cstring>

#define MIN(a,b) (a < b ? (a) : (b))
#define MAX(a,b) (a > b ? (a) : (b))

using namespace std;

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int T;
    fin >> T;
    for (int t = 1; t <= T; t++) {
        fout << "Case #" << t << ": ";
        int N;
        fin >> N;
        string l[100];
        int size[100], next[100];
        for (int i = 0; i < N; i++) {
            fin >> l[i];
            next[i] = 0;
        }
        int count = 0;
        bool flag = 1;
        for (;;) {
            char c = l[0][next[0]];
            int max = 0, min = 100;
            for (int i = 0; i < N; i++) {
                if (l[i][next[i]] != c) {
                    flag = 0;
                    break;
                }
                size[i] = 0;
                while (next[i] < l[i].size() && l[i][next[i]] == c) { next[i]++; size[i]++; }
                max = MAX(size[i], max);
                min = MIN(size[i], min);
            }
            if (!flag) break;
            while (max != min) {
                int maxcount = 0, mincount = 0;
                for (int i = 0; i < N; i++) {
                    if (size[i] == min) mincount++;
                    if (size[i] == max) maxcount++;
                }
                if (mincount <= maxcount) {
                    for (int i = 0; i < N; i++) {
                        if (size[i] == min) { size[i]++; count++; }
                    }
                }
                else {
                    for (int i = 0; i < N; i++) {
                        if (size[i] == max) { size[i]--; count++; }
                    }
                }
                max = 0, min = 100;
                for (int i = 0; i < N; i++) {
                    max = MAX(size[i], max);
                    min = MIN(size[i], min);
                }
            }
            int status = l[0].size() == next[0];
            for (int i = 1; i < N && status != -1; i++) {
                if (l[i].size() == next[i]) {
                    if (status == 0) status = -1;
                }
                else {
                    if (status == 1) status = -1;
                }
            }
            if (status == -1) {
                flag = 0;
                break;
            }
            if (status == 1) break;
        }
        if (!flag)
            fout << "Fegla Won\n";
        else 
            fout << count << "\n";
    }
}