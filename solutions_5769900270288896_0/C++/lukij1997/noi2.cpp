#include <iostream>
#include <vector>
#include <string>
using namespace std;

void initialisation(int i, int j, vector < vector <int> > &Possibles, vector <int> &Two_to_k)
{
    for(int p=i; p<=j; p++)
        for(int k=1; k<=20 && Two_to_k[k-1]<=p; k++)
            {
                if(p%Two_to_k[k]>=Two_to_k[k-1])
                    {
                        Possibles[p].push_back(k-1);
                        //cout << p << " " << k <<endl;
                    }
            }
}

void testcase_noisy(int t, vector <int> &Two_to_k, vector < vector <int> > &Possibles)
{
    int r; int c; int n; int answer=2100000000;
    cin >> r;
    cin >> c;
    cin >> n;
    if(n==0)
        cout << "Case #" << t << ": " << 0 <<endl;
    else
        {
            for(int k=1; k<Two_to_k[r*c]; k++)
                if(Possibles[k].size()==n)
                    {
                        vector < vector <bool> > V(r+2, vector <bool> (c+2,false)); int current=0;
                        for(int g=0; g<Possibles[k].size(); g++)
                            V[Possibles[k][g]/c][Possibles[k][g]-c*(Possibles[k][g]/c)]=true;
                        for(int i=0; i<=r; i++)
                            for(int j=0; j<=c; j++)
                                {
                                    if(V[i][j] && V[i+1][j])
                                        current++;
                                    if(V[i][j] && V[i][j+1])
                                        current++;
                                }
                        //cout << k << " " << current << "  " << answer <<endl;
                        answer=min(answer,current);
                    }
                if(answer==2100000000)
                    answer=0;
            cout << "Case #" << t << ": " << answer <<endl;
        }
}
int main()
{
    ios_base::sync_with_stdio(false);

    vector <int> Two_to_k(21,1);

    for(int e=1; e<=20; e++)
        Two_to_k[e]=2*Two_to_k[e-1];

    vector < vector <int> > Possibles(1400000);

    initialisation(1,131074,Possibles,Two_to_k);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
        testcase_noisy(t,Two_to_k,Possibles);
    return 0;
}
