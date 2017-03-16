//B
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <sstream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> li;
vector<ll> v;
#define MAX 10000
int m[MAX][MAX];	
int main(){
	int t;
	cin>>t;
	int t1=t;
	
	while(t--){		
		int r,c,n;
		cin>>r>>c>>n;
		memset(m,0,sizeof m);
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				int v = 4;
				if(i==0)v--;
				if(j==0)v--;
				if(j+1==c)v--;
				if(i+1==r)v--;
				m[i][j]=v;
			}
		}
		
		int qtd = r*c-n;
		while(qtd--){
			int mx;
			mx=0;
			int pi,pj;
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					if(m[i][j]>mx){
						pi=i;
						pj=j;
						mx=m[i][j];						
						if(m[i][j]==4){
							i=r;
							j=c;
						}
					}
				}
			}			
			m[pi][pj]=0;
			int ba,ci,di,es;
			ba = pi+1;
			ci = pi-1;
			di = pj+1;
			es = pj-1;
			if(ci>=0)m[ci][pj]--;
			if(ba<r)m[ba][pj]--;
			if(di<c)m[pi][di]--;
			if(es>=0)m[pi][es]--;
		}
		int q=0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(m[i][j]){
					//cout<<m[i][j]<<" ";
					if(i+1<r && m[i+1][j]){
						q++;
					}
					if(j+1<c && m[i][j+1])q++;
				}
			}
			//cout<<endl;
		}
		cout<<"Case #"<<t1-t<<": "<<q<<endl;
	}
	return 0;
}
