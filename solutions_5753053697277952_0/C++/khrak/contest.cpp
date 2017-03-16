#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;



int main()
{

    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");

    int t;
    fin >> t;

    for(int q = 0; q < t; q++)
    {
        int n;
        fin >> n;
        vector<pair<int,int> > v(n);

        for(int i = 0; i < n; i++)
        {
            fin >> v[i].first;
            v[i].second = i;
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        vector<string> rest;

        while(v[0].first > v[1].first)
        {
            string st = "";
			char ch = ('A' + v[0].second);
			st += ch;

            if(v[0].first - v[1].first == 1)
            {
                rest.push_back(st);
                v[0].first--;
            }
            else
            {
                v[0].first -= 2;
                rest.push_back(st + st);
            }
        }

        for(int i = 2; i < v.size(); i++)
        {
            while(v[i].first > 0)
            {
                string st = "";
				char ch = ('A' + v[i].second);
                st += ch;
				if(v[i].first == 1)
                {
                    rest.push_back(st);
                    v[i].first--;
                }
                else
                {
                    v[i].first -= 2;
                    rest.push_back(st + st);
                }
            }
        }

        for(int i = 0; i < v[0].first; i++)
        {
            char a = 'A' + v[0].second;
            char b = 'A' + v[1].second;
            string st = "";
			st += a;
            st += b;
            rest.push_back(st);
        }
        fout << "Case #" << q + 1 << ": ";

        for(int i = 0; i < rest.size(); i++)
        {
            fout << rest[i] << " ";
        }

        fout << endl;
    }



    fin.close();
    fout.close();

    return 0;
}

