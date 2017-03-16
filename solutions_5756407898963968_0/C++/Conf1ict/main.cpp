#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <unordered_map>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream input ("input.txt",  ios_base::in);
ofstream output("output.txt", ios_base::out);

void solveCase()
{
    int ans;
    int table[16];

    input >> ans;
    for(int &i : table)
        input >> i;

    int possible[4];
    for(int i = 0; i < 4; ++i)
        possible[i] = table[4*(ans-1)+i];

    input >> ans;
    for(int &i : table)
        input >> i;

    int res_n = 0;
    int results[4];

    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            if(table[4*(ans-1)+i] == possible[j])
                results[res_n++] = possible[j];

    if(res_n == 1)
        output << results[0];
    else if(res_n == 0)
        output << "Volunteer cheated!";
    else
        output << "Bad magician!";
}

int main()
{
    int n;
    input >> n;

    for(int i = 1; i <= n; ++i)
    {
        output << "Case #" << i << ": ";
        solveCase();
        output << endl;
    }
}
