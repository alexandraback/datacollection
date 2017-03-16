#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

struct E {
    int r;
    char c;
};

int abs(int a)
{
    if(a<0)
        return -a;
    return a;
}

int main(int argc, char **argv)
{
    fstream input;
    int i,j,k,t, n;
    char buffer[128];
    input.open(argv[1], fstream::in);
    input >> t;
    for(i = 1; i<=t; i++)
    { 
        input >> n;
        input.getline(buffer, 128);
        vector<vector<E> > strings;
        for(j = 0; j<n; j++)
        {
            input.getline(buffer, 128);
            E e;
            strings.push_back(vector<E>());
            e.c = buffer[0];
            e.r = 1;
            strings.back().push_back(e);
            for(k = 1; buffer[k]!='\0'; k++)
            {
                if(strings.back().back().c == buffer[k])
                    strings.back().back().r++;
                else
                {
                    e.c = buffer[k];
                    e.r = 1;
                    strings.back().push_back(e);
                }
            }
        }
        for(j = 1; j<n; j++)
        {
            if(strings[j-1].size() != strings[j].size())
                break;
        }
        if(j != n)
        {
            cout << "Case #" << i << ": Fegla Won" << endl;
            continue;
        }
        int min_moves = 0;
        for(j = 0; j<strings[0].size(); j++)
        {
            for(k = 1; k<n; k++)
                if(strings[k][j].c != strings[k-1][j].c)
                {
                    break;
                }
            if(k != n)
                break;
            int min_median = 100, min_sum = 10000;
            for(int median = 0; median <= 100; median ++)
            {
                int sum = 0;
                for(k = 0; k<n; k++)
                {
                    sum += abs(strings[k][j].r-median);
                }
                if(sum < min_sum)
                {
                    min_sum = sum;
                    min_median = median;
                }
            }
            min_moves += min_sum;
        }
        if(j != strings[0].size())
            cout << "Case #" << i << ": Fegla Won" << endl;
        else
            cout << "Case #" << i << ": "  << min_moves << endl;
    }
}
