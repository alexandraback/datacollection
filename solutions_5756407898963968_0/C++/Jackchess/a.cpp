#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    int T, a, b[20][20], c[20], d;
    cin >> T;

    for(int caseCnt = 1; caseCnt <= T; ++caseCnt)
    {
        memset(c, 0, sizeof(c));
        cin >> a; --a;
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                cin >> b[i][j];

        for(int i = 0; i < 4; ++i)
            ++c[b[a][i]];
        
        cin >> a; --a;
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                cin >> b[i][j];

        for(int i = 0; i < 4; ++i)
            ++c[b[a][i]];

        int cnt = 0;
        for(int i = 0; i < 20; ++i)
            if(c[i] == 2) { ++cnt; d = i; }

        cout << "Case #" << caseCnt << ": ";
        if(cnt == 0) cout << "Volunteer cheated!" << endl;
        else if(cnt == 1) cout << d << endl;
        else cout << "Bad magician!" << endl;
    }
}
