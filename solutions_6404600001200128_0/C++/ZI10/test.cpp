#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w",stdout);
    int T;
    cin >> T;
    for (int z = 0; z < T; ++z)
    {
        int N;
        cin >> N;
        vector <int> A(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }
        int Ans1 = 0;
        for (int i = 1; i < N; ++i)
        {
            if (A[i] < A[i - 1])
            {
                Ans1 += A[i - 1] - A[i];
            }
        }
        int Ans2 = 1e9;
        for (int j = 0; j < 10005; ++j)
        {
            int Ans = 0;
            for (int i = 0; i < N - 1; ++i)
            {
                if (j >= A[i])
                {
                    Ans += A[i];
                }
                else
                {
                    Ans += j;
                }
                if (A[i] - j > A[i + 1])
                {
                    Ans = 1e9;
                    break;
                }
            }
            //cout << j << " " << Ans << endl;
            Ans2 = min(Ans,Ans2);
        }
        cout << "Case #" << z + 1 << ": " << Ans1 << " " << Ans2 << endl;
    }
    return 0;
}
