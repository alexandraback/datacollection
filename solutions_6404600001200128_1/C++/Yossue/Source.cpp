#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("A-large.in");
    ofstream fout("A-large.out");

    if (fin.is_open())
    {
        int T;
        fin >> T;

        for (int i = 0; i < T; ++i)
        {
            int N;
            fin >> N;

            vector<int> inputs;
            for (int j = 0; j < N; ++j)
            {
                int tmp;
                fin >> tmp;
                inputs.push_back(tmp);

            }

            long ans1 = 0;
            long ans2 = 0;
            int maxDiff = 0;

            for (int k = 1; k < N; ++k)
            {
                int diff = inputs[k - 1] - inputs[k];
                if (diff > 0)
                {
                    ans1 += diff;

                    if (maxDiff < diff)
                    {
                        maxDiff = diff;
                    }
                }
            }

            for (int k = 0; k < N - 1; ++k)
            {
                ans2 += (maxDiff > inputs[k]) ? inputs[k] : maxDiff;
            }

            cout << "Case #" << i + 1 << ": " << ans1 << " " << ans2 << endl;
            fout << "Case #" << i + 1 << ": " << ans1 << " " << ans2 << endl;
        }
    }
}