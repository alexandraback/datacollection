#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> pii;
int B,N;
int M[1010];

long long gcd(long long a,long long b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
	return (a/gcd(a,b))*b;
}
long long alllcm;
long long calclcm()
{
	int clcm=M[0];
	for(int i=1;i<B;i++)
		clcm=lcm(clcm,M[i]);
	return alllcm=clcm;
}

class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2)
    {
	  if(n1.first>n2.first)return true;
	  if(n1.first<n2.first)return false;;
      return (n1.second>n2.second);
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,CompareDist> processors;
//priority_queue<pii> processors;
int calc()
{
	cin>>B>>N;
	for(int i=0;i<B;i++)
		cin>>M[i];
	calclcm();
	
	int batch=0;
	for(int i=0;i<B;i++)
		batch+=alllcm/M[i];
	if(N>batch)N=(N-1)%batch+1;
	//cerr<<"batch:"<<batch<<" new N:"<<N;
	
	while(!processors.empty())processors.pop();
	for(int i=0;i<B;i++)
	{
		int tb=alllcm/M[i];
		for(int j=0;j<tb;j++)
			 processors.push(pii(j*M[i],i+1));
	}
	
	for(int i=0;i<N-1;i++)
	{
		pii a=processors.top();
		//cout<<"skipping:"<<a.first<<","<<a.second<<endl;
		processors.pop(); 
	}
	pii a=processors.top();
	return a.second;
}

int main()
{
	//cout<<calc();return 0;
	int N;cin>>N;
	for(int i=0;i<N;i++)
		cout<<"Case #"<<(i+1)<<": "<<calc()<<endl;
	return 0;
}