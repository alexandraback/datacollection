#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int findPer(vector<int> cur)
{
    for(int per = 1; ; per++)
    {
        int good = 1;
        for(int i = 0; i <= 900; i++)
        {
            if(cur[2000+i] != cur[2000+per+i])
            {
                good = 0;
                break;   
            }
        }
        if(good)
            return per;
    }
}
int main()
{
  ifstream in;
  in.open("in.txt");
  ofstream out;
  out.open("out.txt");
  int T, n, b;
  in >> T;

  for (int k = 1; k <= T; k++)
  {
        in >> b >> n;
        vector<int> v(b);
        for(int i = 0; i < b; i++)
        {
            in >> v[i];
        }
        int numb = 0;
        vector<int> cur;
        for(int t = 0; t < 50000; t++)
        {
            for (int j = 0; j < b; j++)
            {
                if(t % v[j] == 0)
                {
                    numb++;
                    cur.push_back(j);
                    if(numb == n)
                    {
                        out << "Case #" << k << ": " << j + 1<< endl; 
                        goto hell;   
                    }
                }
            }
        }

        int per = findPer(cur);

        out << "Case #" << k << ": " << cur[(n-2001)%per]+1<< endl;   
        hell:;
        cur.clear();
  }
  out.close();
  in.close();

  }
