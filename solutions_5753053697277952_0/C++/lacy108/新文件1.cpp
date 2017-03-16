#include<iostream>
#include<cstdio>
#include<queue>
#include<fstream>
using namespace std;
typedef pair<int,int> P;
priority_queue<P> pri;
int main()
{
	fstream file1,file2;
	file1.open("k.in",ios::in);
	file2.open("b.txt",ios::out);
    int a,n,t,x,y;
    char k,i;
    file1>>a;//scanf("%d",&a);
    for(int b=1;b<=a;++b)
    {
    	while(!pri.empty())
    		pri.pop();
    	file1>>n;//scanf("%d",&n);
    	for(int q=0;q<n;++q)
    	{
    		file1>>t;//scanf("%d",&t);
    		pri.push(P(t,q));
    	}
    	file2<<"Case #"<<b<<":";//printf("Case #%d",b);
    	while(pri.size()!=2&&pri.size()!=0)
    	{
    		file2<<" "<<char(pri.top().second+'A');//printf(" %c",pri.top().second+'A');
    		x=pri.top().first;
    		y=pri.top().second;
    		pri.pop();
    		x--;
    		if(x!=0)
	    		pri.push(P(x,y));
    	}
    	if(pri.size()==2)
    	{
    		x=pri.top().first;
    		k=pri.top().second+'A';
    		pri.pop();
    		i=pri.top().second+'A';
    		for(int q=0;q<x;++q)
    			file2<<" "<<k<<i;//printf(" %c%c",k,i);
    	}
    	file2<<endl;//printf("\n");
    }
    return 0;
}

