#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

long long solve1(const vector<long long>& vec)
{
  long long ans=0;
  for(int i = 1; i < vec.size(); ++i)
    {
      if(vec[i]<vec[i-1])
	{ans+=(vec[i-1]-vec[i]);}
    }
  return ans;
}

long long okay(long long v, const vector<long long>& vec)
{
  long long ans=0;
  for(int i = 1;i < vec.size(); ++i)
    {
      if(vec[i-1]-vec[i]>v){return -1;}
      ans+=v<vec[i-1]?v:vec[i-1];
    }
  return ans;
}

long long solve2(const vector<long long>& vec)
{
  long long m=0,M=10000000;
  long long ans=999*M;
  while(m<M)
    {
      int mid=(m+M)/2;
      //cerr << m << " " << M << " " << mid << endl;
      int val=okay(mid,vec);
      if(val!=-1)
	{
	  ans=val<ans?val:ans;
	  M=mid;
	}
      else
	{m=mid+1;}
    }
  return ans;
}

int main()
{
  int cnt;
  cin >> cnt;
  for(int i = 0; i < cnt; ++i)
    {
      int N;
      vector<long long> vec;
      cin >> N;
      for(int j = 0; j < N; ++j)
	{
	  long long temp;
	  cin >> temp;
	  vec.push_back(temp);
	}
      cout << "Case #" << i+1 << ": " << solve1(vec) << " "  << solve2(vec) << endl;
    }
}
