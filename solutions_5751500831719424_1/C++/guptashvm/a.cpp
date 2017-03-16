#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int t;
int n;
string str[105];
int arr[105];
int ind[105];
int main()
{
    ifstream in("in.in");
    ofstream out("out.out");
    in >> t;
    int cur = 0;
    while(cur < t)
    {
        for(int i= 0; i < 105; i++)
            ind[i] = 0;
        int cost = 0;
        in >> n;
        for(int i= 0; i < n; i++)
        {
            in >> str[i];
        }
        char c;
        bool poss = true;
        while(true)
        {
            for(int i= 0; i < n; i++)
                arr[i] = 0;
            bool done = false;
            c = str[0][ind[0]];
            for(int i = 0; i < n; i++)
            {
                if(str[i][ind[i]] != c)
                {
                    poss = false;
                    break;
                }
                arr[i] = 0;
                while(ind[i] < str[i].length() &&
                      str[i][ind[i]] == c)
                {
                    arr[i]++;
                    ind[i]++;
                }
                if(ind[i] == str[i].length())
                {
                    done = true;
                }
            }
            sort(arr, arr + n);
            int medi = arr[n / 2];
            for(int i= 0; i < n; i++)
            {
                cost += abs(medi - arr[i]);
            }
            if(done)
            {
                for(int i= 0; i < n; i++)
                {
                    if(ind[i] != str[i].length())
                    {
                        poss = false;
                        break;
                    }
                }
                break;
            }
            if(!poss)
                break;
            if(done)
                break;
        }
        if(!poss)
        {
            out << "Case #" << cur + 1 << ": Fegla Won" << endl;
        }
        else
            out << "Case #" << cur + 1 << ": " << cost << endl;
        cur++;
    }
}
