//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define FI first
#define SE second
#define MP make_pair
using namespace std;
const int N = 102, M = 102;

int t;
int n;
vector<pair<char,int> > V[N];
int tab[N];


int main()
{
    scanf("%d", &t);
    for(int ti = 1;ti <= t;ti++)
    {
        scanf("%d", &n);

        for(int i = 1;i <= n;i++)
        {
            V[i].clear();

            scanf(" ");
            while(true)
            {
                char c = getchar();
                if(!('a' <= c && c <= 'z')) break;
                if(V[i].empty() || V[i].back().FI != c) V[i].push_back(MP(c, 1));
                else V[i].back().SE++;
            }
        }

        /*for(int i = 1;i <= n;i++)
        {
            cerr << "I: " << i << " : ";
            for(int j = 0;j < V[i].size();j++)
                cerr << "(" << V[i][j].FI << "," << V[i][j].SE << ") ";
            cerr << endl;
        }*/

        bool dasie = true;
        for(int i = 2;i <= n;i++)
        {
            if(V[i].size() != V[1].size())
            {
                dasie = false;
                break;
            }
            for(int j = 0;j < V[1].size();j++)
                if(V[i][j].FI != V[1][j].FI)
                {
                    dasie = false;
                    break;
                }
        }

        if(!dasie)
        {
            printf("Case #%d: Fegla Won\n", ti);
            continue;
        }

        int wyn = 0;
        for(int p = 0;p < V[1].size();p++)
        {
            for(int i = 1;i <= n;i++) tab[i] = V[i][p].SE;
            sort(tab+1,tab+n+1);
            int med = tab[(n+1)/2];
            for(int i = 1;i <= n;i++) wyn += abs(med-tab[i]);
        }

        printf("Case #%d: %d\n", ti, wyn);
    }
    return 0;
}
