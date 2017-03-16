#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void work(ifstream & fin, int caseno)
{
    int n;
    int m[1000];

    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> m[i];
    }

    // method 1
    int ans1 = 0;
    for (int i = 1; i < n; ++i) {
        if (m[i] < m[i - 1])
            ans1 += m[i - 1] - m[i];
    }

    // method 2
    int ans2 = 0;
    int maxi = 0;
    for (int i = 1; i < n; ++i) {
        maxi = max(maxi, m[i - 1] - m[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        ans2 += min(maxi, m[i]);
    }

    cout << "Case #" << caseno << ": "
        << ans1 << " " << ans2 << endl;
}

int main()
{
    ifstream fin;
    fin.open("input");
    int n;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        work(fin, i + 1);
    }
    fin.close();
    return 0;
}
