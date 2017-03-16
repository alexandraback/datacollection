#include <stdio.h>
#include <math.h>
#include <algorithm>
struct str{
	int x0;
	int y0;
}x[30010];
struct str2{
	double dire;
	int number;
}y[30010];
int number[30010];
bool cmp(str2 a, str2 b)
{
	if(a.dire==b.dire) return a.number<b.number;
	return a.dire<b.dire;
}
void solve(int);
int main()
{
	//freopen("C-small-attempt1.in","r",stdin);
	freopen("C-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) solve(i);
}
int a;
int cw(int a, int b, int c)
{
	long long int s1,s2;
	// a_x b_x c_x a_x
	// a_y b_y c_y a_y
	s1=(long long int)x[a].x0*x[b].y0+(long long int)x[b].x0*x[c].y0+(long long int)x[c].x0*x[a].y0;
	s2=(long long int)x[a].y0*x[b].x0+(long long int)x[b].y0*x[c].x0+(long long int)x[c].y0*x[a].x0;
	if(s1-s2>0) return 1;
	if(s1==s2) return 2;
	else return 0;
}
int func(int k)
{
	int i,s=1,t=2,min=a;
	for(i=1;i<=a;i++)
	{
		if(i==k) continue;
		y[s++]={atan2(x[i].y0-x[k].y0,x[i].x0-x[k].x0),i};
	}
	std::sort(y+1,y+s,cmp);
	for(i=1;i<s;i++) number[i]=y[i].number;
	for(i=s;i<2*s-1;i++) number[i]=number[i-s+1];
	for(i=1;i<s;i++)
	{
		while(t==i||cw(k,number[i],number[t])==1) t++;
		if(cw(k,number[i],number[t])==2)
		{
			if(t-i==s-1) return 0;
			else
			{
				//i+1 ~ t-1 , t+1 ~ s+i-2±îÁö
				min=min<t-i-1?min:t-i-1;
				min=min<s+i-t-2?min:s+i-t-2;
			}
		}
		else
		{
			// i+1 ~ t-1 , t ~ s+i-2
			min=min<t-i-1?min:t-i-1;
			min=min<s+i-t-1?min:s+i-t-1;
		}
	}
	return min;
}
void solve(int T)
{
	int b,c,i;
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		scanf("%d%d",&b,&c);
		x[i]={b,c};
	}
	printf("Case #%d:\n",T);
	if(a==1)
	{
		printf("0\n");
		return;
	}
	for(i=1;i<=a;i++) printf("%d\n",func(i));
}
