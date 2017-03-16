#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
struct LessThan
{
  bool operator()(const pii & lhs, const pii & rhs) const
  {
    return lhs.first < rhs.first;
  }
};

string s;
int N, T, p, a, r;
priority_queue<pii, vector<pii>, LessThan> Q;
pii cur;
ifstream fin("in.in");
ofstream fout("out.out");

int main()
{
    fin >>T;
    for(int p = 1; p <= T; p++)
    {
        fin >>N;
        for(int i = 0; i < N; i++)
        {
            fin >>a;
            Q.push(make_pair(a, i));
        }
        r = 0;
        fout <<"Case #" <<p <<": ";
        s = "";
        while(!Q.empty())
        {
            cur = Q.top();
            //cout <<cur.first <<',' <<cur.second <<endl;
            Q.pop();
            if(cur.first != 0)
            {
                Q.push(make_pair(cur.first - 1, cur.second));
                s += (char) ('A' + cur.second);
            }
        }
        if((s.length() & 1) == 0)
            for(int j = 0; 2 * j + 1 < s.length(); j++)
                fout <<s.substr(2*j, 2) <<' ';
        else
        {
            fout <<s[0] <<' ';
            for(int j = 0; 2 * j + 2 < s.length(); j++)
                fout <<s.substr(2*j+1, 2) <<' ';
        }
        fout <<endl;
    }
    return 0;
}
