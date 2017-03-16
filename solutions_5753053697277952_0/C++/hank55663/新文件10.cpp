#include<bits/stdc++.h>
#define N 3005
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		int n;
		scanf("%d",&n);
		int a[30];
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		printf("Case #%d:",T);
		priority_queue< pair<int,int>,vector<pair<int,int> >,less<pair<int,int> > > pq; 
		for(int i=0;i<n;i++)
		pq.push(make_pair(a[i],i));
		vector<char> ans;
		while(!pq.empty()){
			pair<int,int> p=pq.top();
			pq.pop();
			ans.push_back(p.second+'A');
			if(p.first-1!=0)
			pq.push(make_pair(p.first-1,p.second)); 
		}
		int print=1;
		if(ans.size()%2==1){
			vector<char>::iterator it=ans.end();
			it--;
			it--;
			ans.push_back(2);
			vector<char>::iterator it2=ans.end();it2--;
			swap(*it,*it2); 
		}
		for(vector<char> ::iterator it=ans.begin();it!=ans.end();it++)
		{
			if(print)
			printf(" ");
			if(*it!=2)
			printf("%c",*it);
			print=1-print;
		}
		printf("\n");
	}
	return 0;
}
