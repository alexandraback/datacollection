#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    
    int grid1[4][4], grid2[4][4];
    int answer1, answer2;
    int n;
    fstream input;
    input.open(argv[1], fstream::in);
    input >> n;
    for(int i  = 1; i<=n; i++)
    {
        input >> answer1;
        for(int j = 0; j<4; j++)
           for(int k = 0; k<4; k++)
               input >> grid1[j][k];
        input >> answer2;
        for(int j = 0; j<4; j++)
           for(int k = 0; k<4; k++)
               input >> grid2[j][k];
        int c = 0;
        int match = 0;
        for(int j = 0; j<4; j++)
            for(int k = 0; k<4; k++)
                if(grid1[answer1-1][j] == grid2[answer2-1][k])
                {
                    c++;
                    match = grid1[answer1-1][j];
                }
        cout << "Case #" << i << ": ";
        if(c == 0)
            cout << "Volunteer cheated!";
        else if (c == 1)
            cout << match;
        else
            cout << "Bad magician!";
        cout << endl;
    }
}
