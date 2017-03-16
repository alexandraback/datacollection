#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void solve (int test);

bool ok (vector <string> &v);

bool same (string & str1, string & str2, int s1, int s2);

int calculate (vector <string> & v);

vector <string> v;

int mas[2000];

int main()
{
	freopen("small3.in","r", stdin);
	freopen("output.txt","w", stdout);
	int t;
	cin>>t;

	for (int test = 1;test<=t;test++)
	{
		solve(test);
	}
	return 0;
}
void solve (int test)
{
	int n;
	cin>>n;
	v.clear();

	for (int i=1;i<=n;i++)
	{
		string str;
		cin>>str;
		v.push_back(str);
	}

	cout<<"Case #"<<test<<": ";

	if(ok(v))
	{
		int ans = calculate(v);
		cout<<ans<<endl;
	}
	else
	{
		cout<<"Fegla Won"<<endl;

	}
}
bool ok (vector <string> &v)
{
	for(int i=1;i<v.size();i++)
	{
		if(same(v[0],v[i],0,0))
		{

		}
		else
		{
			return false;
		}
	}
	return true;
}
bool same (string & str1, string & str2,int s1,int s2)
{
	if(str1[s1] != str2[s2])
		return false;
	if(s1== str1.size()-1 && s2 == str2.size()-1)
	{
		return true;
	}

	if(s1<str1.size()-1 && str1[s1]== str1[s1+1])
	{
		return same (str1, str2, s1+1, s2);
	}

	if(s2<str2.size()-1 && str2[s2]== str2[s2+1])
	{
		return same (str1, str2, s1, s2+1);
	}

	if(s1== str1.size()-1 || s2 == str2.size()-1)
	{
		return false;
	}

	if(str1[s1+1] == str2[s2+1])
	{
		return same (str1, str2, s1+1, s2+1);
	}
	return false;
}
int calculate (vector <string> & v)
{
	int ans=0;
	while(1)
	{
		bool flag  = false;
		for(int i=0;i<v.size();i++)
		{
			mas[i]=0;
		}
		for(int i=0 ;i<v.size();i++)
		{
			while(1)
			{
				
				if(v[i].size()==1 || v[i][v[i].size()-1] != v[i][v[i].size()-2])
				{
					v[i].pop_back();
					mas[i]++;
					if(v[i].size()==0)
					{
						flag = true;
					}
					break;
				}
				else
				{
					v[i].pop_back();
					mas[i]++;
					continue;
				}
			}

		}

		sort(mas, mas+v.size());

		int x = mas[v.size()/2];

		for(int i=0;i<v.size();i++)
		{
			ans+= abs(mas[i]-x);
		}

		if(flag)
			break;

	}
	return ans;
}