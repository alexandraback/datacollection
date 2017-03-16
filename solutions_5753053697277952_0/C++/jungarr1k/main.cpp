#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin("A-small-attempt0.in");
    ofstream fout("out.txt");
    int t;
    fin >> t;
    for (int glob = 0; glob < t; glob++) {
        int n;
        fin >> n;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            fin >> a[i];
            sum += a[i];
        }
        fout << "Case #" << glob + 1 << ": ";

        while (sum > 0)  {
            int maxi = 0;
            for (int i = 0; i < a.size(); i++)
                maxi = max(maxi, a[i]);
            int i1 = -1, i2 = -1, counter = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == maxi) {
                    i2 = i1;
                    i1 = i;
                    counter++;
                }
            }
            if (counter == 1) {
                sum--;
                a[i1]--;
                fout << (char)('A' + i1);
            }
            else if (counter == 2) {
                sum -= 2;
                a[i1]--;
                a[i2]--;
                fout << (char)('A' + i1) << (char)('A' + i2);
            }
            else {
                sum--;
                a[i1]--;
                fout << (char)('A' + i1);
            }

            fout << " ";

        }
        fout << endl;
    }
    return 0;
}
