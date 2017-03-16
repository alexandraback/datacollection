#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<string>
#include<map>
using namespace std;

/*
void Vec()
{
	vector<int> A;  
	A.push_back(10);
	int n = A.size();
	A.clear();
	if(!A.empty())
	{
		int sum = 0;
		for(vector<int>::iterator it = A.begin();it != A.end();it++)
		{
			sum += *it;
		}

		vector<int>::iterator it = A.begin();
		A.erase(it);
		sort(A.begin(),A.end());
		it = max_element(A.begin(),A.end());
		it = min_element(A.begin(),A.end());
		A.insert(it,10);
		A.pop_back();
		int a = A.front();
		int b = A.back();
	}
}

void Pairs()
{
	pair<int,int> A;
	A.first = 10;
	A.second = 15;
}

void STRING()
{
	string a = "Hello";
	a = a + a;
	string b = a.substr(0,3);
	int t = a.find_first_of('a');
	cout<< a;
}

void SET()
{
	set<int> A;
	A.insert(10);
	A.erase(10);
	int t = A.count(10);
	set<int>::iterator it = A.find(10);
	it = A.upper_bound(10);//>10
	it = A.lower_bound(10);//<=10

	A.clear();
	if(!A.empty())
	{
		int sum = 0;
		for(set<int>::iterator it = A.begin();it != A.end();it++)
		{
			sum += *it;
		}
	}
}

void MAP()
{
	map<int,int> A;
	A[10]=20;
	A.erase(10);
	A.clear();
	A.size();
	map<int,int>::iterator it = A.find(10);

	if(!A.empty())
	{
		int sum = 0;
		for(map<int,int>::iterator it = A.begin();it != A.end();it++)
		{
			sum += it->second;
		}
	}
}

struct fun{
  int  xnode, weight;
  fun() {}
  fun(int t, int w) : xnode(t), weight(w) {}
  bool operator < (const fun &that) const {
    return weight > that.weight;
  }
};

void Priority_Queue()
{
	priority_queue<fun> q;
	q.top().weight;
	q.pop();
	q.push(fun(1,2));
	int i = q.size();
	if(!q.empty())
	{}
}
*/

char A[109][109], AA[109][109];
int B[109][109],C[109];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int cas;

	scanf("%d",&cas);

	for(int cas1=1;cas1<=cas;cas1++)
	{
		int n;
		
		scanf("%d",&n);

		for(int i=0;i<n;i++)
		{
			scanf("%s",A[i]);

			int t = strlen(A[i]);

			AA[i][0]=A[i][0];
			B[i][0]=1;
			C[i]=1;

			for(int j=1;j<t;j++)
			{
				if(A[i][j]!=A[i][j-1])
				{
					AA[i][C[i]]=A[i][j];
					B[i][C[i]]=1;
					C[i]++;
				}
				else
					B[i][C[i]-1]++;
			}

		}

		bool yes = 1;
		int res = 0;


		for(int i=1;i<n;i++)
			if(C[i]!=C[i-1])
			{
				yes = 0;
				break;
			}

		if(yes==1)
		{
			for(int i=0;i<C[0];i++)
			{
				for(int j=1;j<n;j++)
					if(AA[j][i]!=AA[j-1][i])
					{
						yes = 0;
						break;
					}

				if(yes == 0)
					break;

				int mini = 10000000;

				for(int j=0;j<n;j++)
				{
					int total = 0;

					for(int k=0;k<n;k++)
					{
						int t = B[j][i]-B[k][i];
						if(t<0)
							t = -t;
						total += t;
					}

					if(total <mini)
						mini = total;
				}

				res += mini;

			}
		}

		
		if(yes)
			printf("Case #%d: %d\n",cas1,res);
		else
			printf("Case #%d: Fegla Won\n",cas1);

	}

	return 0;    
}
