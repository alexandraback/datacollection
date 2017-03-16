#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

int check(const vector<LL>& vec, LL t, LL N)
{
  int okay=0;
  LL totClient=0;
  vector<int> av;
  for(int i = 0; i < vec.size(); ++i)
    {
      totClient+=t/vec[i];
      if(t%vec[i]==0){okay+=1;av.push_back(i+1);}
      //cerr << t << " " << vec[i] << " "  << totClient << endl;
      if(totClient+vec.size()-okay>=N){return -1;}
    }
  if(totClient+vec.size()>=N)
    {
      return av[N-totClient-vec.size()+okay-1];
    }
  return -2;
}

int main()
{
  int cnt;
  cin >> cnt;
  for(int i = 0; i < cnt; ++i)
    {
      //cerr << i << endl;
      LL B, N;
      cin >> B >> N;
      vector<LL> vec;
      for(int j = 0; j < B; ++j)
	{
	  LL temp;
	  cin >> temp;
	  vec.push_back(temp);
	}
      if(B>=N){cout << "Case #" << i+1 << ": " << N << endl;continue;}
      LL m=0, M=1e18;
      int ans=-1;
      while (1)
	{
	  //cerr << i << " " << m << endl;
	  LL mid=(m+M)/2;
	  int val=check(vec,mid,N);
	  //cerr << m << " " << M << endl;
	  //cerr << val << endl;
	  if(val==-1)
	    {M=mid;}
	  else if(val==-2)
	    {m=mid+1;}
	  else{ans=val;break;}
	}
      cout << "Case #" << i+1 << ": " << ans << endl;
    }
}
