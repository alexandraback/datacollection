#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{
    int T;
    ifstream in("in.txt");
    ofstream out("out.txt");
    in >> T; 
    for (int t = 1; t <= T; t++)
    {
        int N;
        string a,b;
        in >> N;
        in >> a >> b;
        string retA = "", retB = "";
        retA += a[0];
        retB += b[0];
        for(int i = 1; i < a.size(); i++)
        {
            if(retA[retA.size()-1] != a[i])
                retA += a[i];
        }
        for(int i = 1; i < b.size(); i++)
        {
            if(retB[retB.size()-1] != b[i])
                retB += b[i];
        }
        if(retA != retB)
            out << "Case #" << t << ": Fegla Won" <<  endl;   
        else
        {
            int countA[256], countB[256];
            memset(countA, 0, sizeof(countA));
            memset(countB, 0, sizeof(countB));
            int k = 0;
            for(int i = 0 ; i < a.size() - 1; i++)
            {
                cout << a[i+1] <<endl;
                if(a[i] == a[i+1])
                {
                    countA[k]++;
                }
                else
                {
                    k++;    
                }
            }
            k = 0;
            int ret = 0;
            for(int i = 0 ; i < b.size() - 1; i++)
            {        
                if(b[i] == b[i+1])
                {
                    countB[k]++;
                }
                else
                {
                    k++;    
                }
            }
            for(int i = 0 ; i < max(a.size(),b.size()); i++)
            {
                ret += abs(countA[i] - countB[i]);
            }
            out << "Case #" << t << ": " <<ret<< endl;
          
        }

    }    
    return 0;
    
}
