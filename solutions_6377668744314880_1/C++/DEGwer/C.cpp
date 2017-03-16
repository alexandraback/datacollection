#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
double eps=1e-13;
double pi=3.1415926535897932384626433832;
double inf=1e+100;
double add(double a,double b)
{
	if(fabs(a+b)/(fabs(a)+fabs(b))<eps)return 0;
	else return a+b;
}
class P
{
public:
	double x,y;
	P(){}
	P(double x,double y):x(x),y(y){}//‚¨‚Ü‚¶‚È‚¢
	P operator + (P p)
	{
		return P(add(x,p.x),add(y,p.y));
	}
	P operator - (P p)
	{
		return P(add(x,-p.x),add(y,-p.y));
	}
	P operator * (P p)
	{
		return P(add(x*p.x,-y*p.y),add(x*p.y,y*p.x));
	}
	P operator / (P p)
	{
		return P(add(x*p.x,y*p.y)/add(p.x*p.x,p.y*p.y),add(-x*p.y,y*p.x)/add(p.x*p.x,p.y*p.y));
	}
	bool operator < (P p)const
	{
		if(p.x-x>eps)return true;
		if(p.x-x<-eps)return false;
		return y<p.y;
	}
	double arg()
	{
		return atan2(y,x);
	}
};
double dot(P p,P q)
{
	return add(p.x*q.x,p.y*q.y);
}
double det(P p,P q)
{
	return add(p.x*q.y,-p.y*q.x);
}
double abs(P p)
{
	return sqrt(p.x*p.x+p.y*p.y);
}
int main()
{
	FILE *fr=fopen("c-large.in","r");
	FILE *fw=fopen("outl.txt","w");
	int data;
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		int num;
		fscanf(fr,"%d",&num);
		vector<P>vec;
		for(int i=0;i<num;i++)
		{
			int za,zb;
			fscanf(fr,"%d%d",&za,&zb);
			vec.push_back(P(za,zb)*P(cos(1.0),sin(1.0)));
		}
		fprintf(fw,"Case #%d:\n",p+1);
		for(int i=0;i<num;i++)
		{
			vector<pair<double,int> >d;
			int now=0;
			for(int j=0;j<num;j++)
			{
				if(i!=j)
				{
					double z=(vec[i]-vec[j]).arg();
					if(z<0)
					{
						now++;
						d.push_back(make_pair(z+pi-eps,-1));
						d.push_back(make_pair(z+pi+pi+eps,1));
					}
					else
					{
						d.push_back(make_pair(z+eps,1));
						d.push_back(make_pair(z+pi-eps,-1));
					}
				}
			}
			int mini=now;
			sort(d.begin(),d.end());
			for(int j=0;j<d.size();j++)
			{
				now+=d[j].second;
				mini=min(mini,now);
			}
			fprintf(fw,"%d\n",mini);
		}
	}
}