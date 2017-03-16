#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
  ifstream in;
  in.open("in.txt");
  ofstream out;
  out.open("out.txt");
  int T, n;
  in >> T;

  for (int k = 1; k <= T; k++)
  {
        in >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
        {
            in >> v[i];
        }          
        int sum1 = 0;
        int maxD = 0;
        for(int i = 1; i < n; i++)
        {
            if(v[i] < v[i-1])
            {
                sum1 += v[i-1] - v[i];
                maxD >?= v[i-1] - v[i];
            }
        }
        int sum2 = 0;
        for(int i = 0; i < n-1; i++)
        {
            sum2 += maxD <? v[i];
        }
        out << "Case #" << k << ": " << sum1 <<" "<<sum2 << endl;
        
  }
  out.close();
  in.close();

  }
