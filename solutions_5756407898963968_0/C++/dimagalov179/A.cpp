#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q)
    {
        int n, temp;
        vector<int> A, B, C;
        cin >> n;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                cin >> temp;
                if (i == n - 1)
                    A.push_back(temp);
            }
        }
        cin >> n;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                cin >> temp;
                if (i == n - 1)
                    B.push_back(temp);
            }
        }
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (A[i] == B[j])
                    C.push_back(A[i]);
        cout << "Case #" << q + 1 << ": ";
        if (C.size() == 0)
            cout << "Volunteer cheated!" << endl;
        else if (C.size() > 1)
            cout << "Bad magician!" << endl;
        else
            cout << C[0] << endl;
    }
}