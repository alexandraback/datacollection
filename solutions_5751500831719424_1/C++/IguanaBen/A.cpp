#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define type long long

using namespace std;

string tab[133];
string stab[133];
int tabs[100][100];
vector<int> vv[133];

string shorten(string s)
{
	for(int i=0; i<s.length()-1; i++)
		if(s[i] == s[i+1])
		{
			return s.substr(0, i) + shorten( s.substr(i+1, s.length()-i-1)  );
		}

	return s;
}

vector<int> toV(string s)
{
	vector<int> rr;
	int c = 1;
	for(int i=0; i<s.length()-1; i++)
		if(s[i] == s[i+1])
			c++;
		else
		{
			rr.push_back(c); c=1;
		}

	// if(c !=0 )
	rr.push_back(c);
	return rr;
}

int main()
{

  cin.tie(NULL);
  std::ios::sync_with_stdio(false);

  // cout<<shorten("aabcccc")<<"\n";
  // cout<<shorten("aaabc")<<"\n";
  // cout<<shorten("aaabbbc")<<"\n";

  // vector<int> vv = toV("ab");
  // for(int i=0; i<vv.size(); i++) cout<<vv[i]<<" ";
  	// cout<<"\n";



  int T;
  cin>>T;
  int t=0;
  while(t<T)
  {
  	int n;
  	cin>>n;
  	for(int i=0; i<n; i++)
  	{
  		cin>>tab[i];
  		stab[i] = shorten(tab[i]);
  		vv[i] = toV(tab[i]);
  	}

  	string s1 = stab[0];
  	bool b=true;
  	for(int i=0 ;i<n; i++)
  		if( s1.compare(stab[i]))
  			b = false;

  	if(b)
  	{
  		int total = 0;
  		for(int i=0; i<vv[0].size(); i++)
  		{
  			vector<int> tt;

  			for(int j=0; j<n; j++)
  				tt.push_back(vv[j][i]);

  			sort(tt.begin(), tt.end());

  			int median = tt[(n-1)/2];

  			for(int j=0; j<n; j++)
  				total += abs(median - vv[j][i]);

  		}
		cout <<"Case #"<<t+1<<": "<<total<<"\n";


  	}
  	else
	{
		cout <<"Case #"<<t+1<<": Fegla Won\n";
	}

	t++;

  }

  return 0;
 
}