#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <set>
#include <utility>
#include <stack>
#include <cmath>
#include <climits>
#include <cassert>
#define sort(v) sort(v.begin(),v.end())
#define null NULL
#define len(x) (sizeof(x)/sizeof(x[0]))
using namespace std;
typedef long long int ll;


struct Party
{
	int num;
	char name;
	Party(int num,char name)
	{
		this->num = num;
		this->name = name;
	}
};

class Compare
{
public:
    bool operator() (Party a, Party b)
    {
        return (a.num < b.num);
    }
};


int t,n,sum,a;
priority_queue<Party,vector<Party>,Compare> pq;

int main()
{
	cin>>t;
	for (int tt = 0; tt < t; tt++)
	{
		sum = 0;
		cin>>n;
		for (int i = 0; i < n; i++)
		{
			cin>>a;
			pq.push(Party(a,'A'+i));
			sum = sum+a;
		}
		cout<<"Case #"<<tt+1<<": ";
		while(!pq.empty())
		{
			Party top1 = pq.top();pq.pop();
			Party top2 = pq.top();pq.pop();
			if(top1.num >= 2)
			{
				if(sum-2>=top2.num*2)
				{
					cout<<top1.name<<top1.name<<" ";
					top1.num -= 2;
					sum = sum-2;
				}
				else if(pq.empty() || sum-2>pq.top().num*2)
				{
					cout<<top1.name<<top2.name<<" ";
					top1.num -= 1;
					top2.num -= 1;
					sum = sum-2;
				}
				else
				{
					cout<<top1.name<<" ";
					top1.num -= 1;
					sum = sum-1;
				}
			}
			else
			{
				if(pq.empty() || sum-2>pq.top().num*2)
				{
					cout<<top1.name<<top2.name<<" ";
					top1.num -= 1;
					top2.num -= 1;
					sum = sum-2;
				}
				else
				{
					cout<<top1.name<<" ";
					top1.num -= 1;
					sum = sum-1;
				}
			}
			if(top1.num!=0)
			{
				pq.push(top1);
			}
			if(top2.num!=0)
			{
				pq.push(top2);
			}
		}
		cout<<"\n";

	}
}
