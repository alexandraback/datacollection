#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ifstream fin("A.in");
    ofstream fout("A.out");
    int T, N;
    fin >> T;
    for (int testnum = 1; testnum <= T; testnum++)
    {
        bool win = true;
        fin >> N;
        vector<char> lets;
        vector<int> numlets[N];
        vector<int> maxlets;
        string s;
        fin >> s; //cout << s << endl;
        char curr = '0';
        int numcurr = 0, index = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != curr)
            {
                if (i != 0)
                {
                    numlets[0].push_back(numcurr);
                    maxlets.push_back(numcurr);
                }
                numcurr = 1;
                lets.push_back(s[i]);
                curr = s[i];
            }
            else
                numcurr++;
        }
        numlets[0].push_back(numcurr);
        maxlets.push_back(numcurr);
        
        for (int j = 1; j < N; j++)
        {
            fin >> s; //cout << s << endl;
            //if (testnum <= 10)
                //cout << s << endl;
            curr = '0';
            numcurr = 0;
            index = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] != curr)
                {
                    if ((index < lets.size()) && (s[i] == lets[index]))
                    {
                        if (i != 0)
                        {
                            numlets[j].push_back(numcurr);
                            if (numcurr > maxlets[index-1])
                                maxlets[index-1] = numcurr;
                        }
                        numcurr = 1;
                        curr = s[i];
                        index++;
                    }
                    else
                    {
                        win = false;
                        break;
                    }
                }
                else
                    numcurr++;
            }
            numlets[j].push_back(numcurr);
            if (numcurr > maxlets[index-1])
                maxlets[index-1] = numcurr;
            if (numlets[j].size() != numlets[0].size())
            {
                win = false;
            }
        }
        
        fout << "Case #" << testnum << ": ";
        if (!win)
            fout << "Fegla Won" << endl;
        else
        {
            /*for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < lets.size(); k++)
                    cout << numlets[j][k] << ' ';
                cout << endl;
            }*/
            int minways = 0, best, currbest;
            for (int k = 0; k < lets.size(); k++)
            {
                //cout << maxlets[k] << endl;
                best = 1e6, currbest;
                for (int h = 1; h <= maxlets[k]; h++)
                {
                    currbest = 0;
                    for (int j = 0; j < N; j++)
                    {
                        if (numlets[j][k] < h)
                            currbest += (h - numlets[j][k]);
                        else
                            currbest += (numlets[j][k] - h);
                    }
                    if (currbest < best)
                        best = currbest;
                }
                //cout << "best " << best << endl;
                minways += best;
            }
            fout << minways << endl;
        }
    }
}