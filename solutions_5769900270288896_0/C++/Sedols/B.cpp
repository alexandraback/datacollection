#include<iostream>
#include<fstream>
#include <iomanip>
#include <string>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int count(vector<int> V, int R, int C)
{
    int ret = 0;
    int v[20][20];
    memset(v,0,sizeof(v));

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
        {

            v[i][j] = V[i*C + j];
        }


    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(j+1 < C && v[i][j] && v[i][j+1])
                ret++;
            if(i+1 < R && v[i][j] && v[i+1][j])
                ret++;
        }
    }
    return ret;
}
int main()
{
  ifstream in;
  in.open("in.txt");
  ofstream out;
  out.open("out.txt");
  long long  T, N;
  in >> T;
  for (int k = 1; k <= T; k++)
  {
        int R, C, N;
        in >> R >> C >> N;
        vector<int> v(R*C);
        for(int i = 0; i < N; i++)
        {
            v[i] = 1;
        }
        sort(v.begin(),v.end());

        int min = 1000;
        do
        {
            min <?= count(v, R,C);            
        }while(next_permutation(v.begin(),v.end()));
        out << "Case #" << k << ": " << min<< endl;   
  }
  out.close();
  in.close();

}
