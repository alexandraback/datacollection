#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

bool IsOnLine(pair<double,double> a, pair<double,double> b, pair<double,double> c)
{
  double r;
  r=(b.first-a.first)*(c.second-a.second) - (b.second-a.second)*(c.first-a.first);

  if(r==0)
    return true;
  else
    return false;
}

double Rot(pair<double,double> a, pair<double,double> b, pair<double,double> c)
{
  return (b.first-a.first)*(c.second-b.second)-(b.second-a.second)*(c.first-b.first);
}

void Scan(vector<pair<double,double>> T, vector<int> &r)
{
  int n = T.size();
  vector<int> idx(n);

  for(int i=0; i<n; i++)
    idx[i]=i;

  for(int i=0; i<n; i++)
    if(T[idx[i]].first < T[idx[0]].first)
    {
      int tmp = idx[i];
      idx[i] = idx[0];
      idx[0] = tmp;
    }

  for(int i=2; i<n; i++)
  {
    int j = i;
    while (j>1 && (Rot(T[idx[0]],T[idx[j-1]],T[idx[j]])<0))
    {
      int tmp = idx[j];
      idx[j] = idx[j-1];
      idx[j-1] = tmp;
      j--;
    }
  }

  r.push_back(idx[0]);
  r.push_back(idx[1]);

  for(int i=2; i<n; i++)
  {
    while(Rot(T[r[r.size()-2]],T[r[r.size()-1]],T[idx[i]])<0)
      r.erase(r.begin() + r.size()-1);

    r.push_back(idx[i]);
  }
} 

int Scan2(vector<pair<double,double>> T, pair<double,double> c)
{
  int n = T.size();
  vector<int> idx(n);

  for(int i=0; i<n; i++)
    idx[i]=i;

    for(int i=1; i<n; i++)
    {
      int j = i;
      while (j>=1 && (Rot(c,T[idx[j-1]],T[idx[j]])<0))
      {
        int tmp = idx[j];
        idx[j] = idx[j-1];
        idx[j-1] = tmp;
        j--;
      }
    }

    for(int count = n-1; count >= 2; count--)
    {
      for(int start=0; start<n; start++)
      {
        vector<pair<double,double>> T2(count+1);
        for(int i=0;i<count; i++)
        {
          T2[i]=T[idx[(i+start)%n]];
        }
        T2[count]=c;

        vector<int> idx2;
        Scan(T2, idx2);

        for(int k=0; k<idx2.size(); k++)
          if(idx2[k]==count)
          {
            return count;
          }
          else
          {
            if(IsOnLine(T2[count],T2[idx2[k]], T2[idx2[(k+1)%idx2.size()]]))
            {
              return count;
            }
          }
      }
    }
} 

int main()
{
  int T;

  //ifstream in("test.in");
  //ofstream out("test.out");

  ifstream in("C-small-attempt2.in");
  ofstream out("C-small-attempt2.out");

  //ifstream in("C-large.in");
  //ofstream out("C-large.out");
  
  in >> T;

  for(int i=0; i<T; ++i)
  {
    int solve = 0; 
    int N;

    in >> N;

    vector<pair<double,double>> T(N);

    for(int j=0; j<N; j++)
    {
      double a,b;
      in >> a >> b;
      T[j]=pair<double,double>(a,b);
    }

    out << "Case #"<<i+1<<": " << endl;

    if(N==1)
      out << "0" << endl;
    else
    {
      vector<int> idx;
      Scan(T, idx);



      for(int j=0; j<N; j++)
      {
        bool isOk = false;
        for(int k=0; k<idx.size(); k++)
          if(idx[k]==j)
          {
            solve = 0;
            isOk = true;
            break;
          }
          else
          {
            if(IsOnLine(T[j],T[idx[k]], T[idx[(k+1)%idx.size()]]))
            {
              solve = 0;
              isOk = true;
              break;
            }
          }

          if(isOk)
            out << solve << endl;
          else
          {
            vector<pair<double,double>> T2=T;
            auto c = T2[j];
            T2.erase(T2.begin()+j);
            solve = Scan2(T2,c)+1;

            out << N-solve << endl;
          }
      }
    }
  }

  return 0;
}