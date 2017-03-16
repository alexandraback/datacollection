#include <iostream>
#include <fstream>

using namespace std;

int a[20];
int b[20];

int main()
{
    ifstream cin("input");
    ofstream cout("output");
    int n;
    cin >> n;
    for(int k = 0; k < n; k++)
    {
        int aa;
        cin >> aa;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                int tmp;
                cin >> tmp;
                a[tmp] = i + 1;
            }
        int bb;
        cin >> bb;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                int tmp;
                cin >> tmp;
                b[tmp] = i + 1;
            }
        int cnt = 0;
        int p;

        for(int i = 1; i < 17; i++)
        {
            if(a[i] == aa && b[i] == bb)
            {
                p = i;
                cnt++;
            }
        }

        if(cnt == 0)
        {
            cout << "Case #" << k + 1 << ": Volunteer cheated!" << endl;
        }
        if(cnt == 1)
        {
            cout << "Case #" << k + 1 << ": " << p << endl;
        }
        if(cnt > 1)
        {
            cout << "Case #" << k + 1 << ": Bad magician!" << endl;
        }
    }
}
