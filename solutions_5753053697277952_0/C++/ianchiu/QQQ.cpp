#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<set>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> N;
	ofstream fout("D:/q.txt");
    ifstream fin("t.in");
bool check();
void solve();
int main()
{

int cs,ct=0;
fin>> cs;

while(cs--)
{   ct++;
    int n,tmp; 
  fin>> n;
  N.clear();
  while(n--){fin>> tmp;
  N.push_back(tmp);
  }
  
	fout <<"Case #"<<ct<<":";
solve();
	
	
}

fin.close();
fout.close();
return 0;
}

bool check()
{
int sum=0;
for(int i=0;i<N.size();i++) sum+=N[i];

for(int i=0;i<N.size();i++) if(N[i]>sum/2) return false;

return true;
	
	
}

void solve()
{
	
	int max=0,mmax=0;
	int i=0,j=0;
	for(int k=0;k<N.size();k++)
	if(N[k]>max) max=N[k],i=k;
	N[i]=-1;
	
	for(int k=0;k<N.size();k++)
	if(N[k]>mmax) mmax=N[k],j=k;
	N[i]=max;
	
	while(max>mmax) {fout <<" "<<(char)('A'+i);
	max--; N[i]--;
	}
	
	for(int k=0;k<N.size();k++)
	{
	   if(k!=i && k!=j) while(N[k]--) fout <<" "<< (char)('A'+k);	
	
	}
	
	
	while(max--) fout <<" "<<(char)( 'A'+i)<<char('A'+j);
	
	fout<<endl;
	
	
	
	
}
