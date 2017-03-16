#include <iostream>
#include <climits>
#include <cassert>
#include <string>

using namespace std;

int R, C, N;
bool occupied[16];

int optimal;

void check(int i, int total)
{
    if (total > N) return;
    if (i == R*C)
    {
        if (total != N) return;

        int score = 0;
        for (int j = 0; j < i; j++)
        {
            if (occupied[j] == false) continue;
            // check walls of j
            // j % R
            int row = j % R;
            int col = j / R;
            if (row > 0)   if (occupied[ col*R + (row-1)]) score++;
            if (row < R-1) if (occupied[ col*R + (row+1)]) score++;
            if (col > 0)   if (occupied[ (col-1)*R + row]) score++;
            if (col < C-1) if (occupied[ (col+1)*R + row]) score++;
        }

        score /= 2;

        //cout << endl << "--------------------------------" << endl;
        //for (int r = 0; r < R; ++r)
        //{
        //    for(int c = 0; c < C; ++c)
        //        cout << (occupied[c*R + r] ? 'x' : '.');
        //    cout << endl;
        //}
        //cout << " ^^ score = " << score << endl;
        //cout << "--------------------------------" << endl;

        if (score < optimal) optimal = score;
        return;
    }

    occupied[i] = true;
    check(i+1, total+1);
    occupied[i] = false;
    check(i+1, total);
}

int main()
{
    int T;
    cin >> T;
    for (int run = 1; run <= T; ++run)
    {
        cin >> R >> C >> N;
        optimal = INT_MAX;
        check(0, 0);
        cout << "Case #" << run << ": " << optimal << endl;
    }
}
