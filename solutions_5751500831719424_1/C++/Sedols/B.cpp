#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<fstream>
#include<cmath>
using namespace std;

bool allGood(vector<string> s)
{
    string S = s[0];
    for(int i = 0; i < s.size(); i++)
    {
        if(S != s[i]) return 1;
    }
    return 0;
    
}
int main()
{
    int T;
    ifstream in("in.txt");
    ofstream out("out.txt");
    in >> T; 
    for (int t = 1; t <= T; t++)
    {
        int N;
        vector<string> S;
        S.clear();
        in >> N;
        for(int i = 0 ; i < N; i++)
        {
            string c;
            in >> c;
            S.push_back(c);
        }
        vector<string> rS;
        rS.clear();
        for(int i = 0 ; i < N; i++)
        { 
            string a = S[i];
            string rC = "";
            rC += a[0];
            for(int i = 1; i < a.size(); i++)
            {
                if(rC[rC.size()-1] != a[i])
                   rC += a[i];
            }
            rS.push_back(rC);
        }
        if(allGood(rS))
            out << "Case #" << t << ": Fegla Won" <<  endl;   
        else
        {
            int count[256][256];
            memset(count, 0, sizeof(count));
            for(int j = 0; j < N; j++)
            {
                string a = S[j];
                int k = 0;
                for(int i = 0 ; i < a.size() - 1; i++)
                {
                    if(a[i] == a[i+1])
                    {
                        count[j][k]++;
                    }
                    else
                    {
                        k++;    
                    }
                }
              
            }
            int ret = 0;
       
            for(int i = 0 ; i < 111; i++)
            {
                int retMi = 123123123;
                for(int j = 0; j < N; j++)
                {
                    int cur = count[j][i];
                    int retC = 0;
                    for(int k = 0; k < N; k++)
                        retC += abs(count[k][i] - cur);
                    if(retMi  > retC)
                        retMi = retC;
                }
                ret += retMi;
            }
            out << "Case #" << t << ": " <<ret<< endl;
           
        }

    }    
    return 0;
    
}
