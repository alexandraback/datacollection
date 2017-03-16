#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ifstream in("small-practice.in");
    //ifstream in("large-practice.in");
    ofstream out("output.out");

    int T;
    in >> T;

    for( int t = 1; t <= T; t++ )
    {
        out << "Case #" << t << ": ";

        int N;
        in >> N;

        string evac = "";
        vector<pair<string,int>> P;

        for(int i = 0; i < N; i++)
        {
            int n;
            string s; s = (char) (65+i);
            in >> n;
            P.push_back( pair<string,int>( s, n) );
        }

        sort(P.begin(), P.end(), [=](pair<string, int>& a, pair<string, int>& b)
        {
            return a.second > b.second;
        }
        );

        /*for(auto& iter: P)
        {
            out << iter.first << " " << iter.second << endl;
        }*/

        while( P[0].second > P[1].second )
        {
            P[0].second -= 1;
            evac += P[0].first + " ";
        }

        for( int i = 2; i<P.size(); i++ )
        {
            while( P[i].second > 0 )
            {
                P[i].second -= 1;
                evac += P[i].first + " ";
            }
        }

        while( P[0].second > 0 )
        {
            P[0].second -= 1;
            evac += P[0].first + P[1].first + " ";
        }

        out << evac;

        out << endl;
    }

    return 0;
}
