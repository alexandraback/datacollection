
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 
#include <map>  
#include <string>
#include <vector> 
#include <list> 
#include <iostream>   
#include <sstream>  
#include <queue> 
#include <algorithm>
#include <fstream>
#include <iomanip>


using namespace std; 
 
#define ll long long
#define PB 		push_back
#define FOR(a,start,end) 	for(int a=int(start); a<int(end); a++)
#define INF 		int_MAX
#define SORT(a) 	sort(a.begin(),a.end())
#define CL(a,x) 		memset(a,x,sizeof(a))
#define REP(a,x)	for(int a=0;a<x;a++)
#define REP1(a,x)	for(int a=1;a<=x;a++)
#define MP 		make_pair
#define vi vector<int>
#define vvi vector<vector<int> >
#define vii vector<pair<int,int> >
#define vvii vector<vector<pair<int,int> > >
#define pii pair<int,int>
#define vs vector<string>
int s,c,i,k,j,n,m,z,jx,z0,b,a0,b0,z1; 
int t,cas,i1,i2,i3;
vvi vvk,vvc;
vii vp,vp2;
pii p1,p2;
vector<pair<int,int> > vpk;
vs ve;
string wya,wyb;
vs vsl,vt;
vi vk,vk1,vk2,vm,vc;
int k1,k2,k3,p;
int a1,a2;
vector<int> vz,vz2;
int zx,d,d2,d1,a;
int k4;
int ta[101000],tc[1010],tb[30];
int za,zs,zb,zmax,w,q,l;
string we,wex;
char zn,zn2;
map<string,int> witches;
double bx,cx,ax,dx,kx,kx4;
int k0,b1,b2;	
vvi vv4;
vector<vvi> vvvd;


int main() {  
	//freopen( "c:\\wojtek\\uva\\uva\\debug\\t1.in", "rt", stdin); 
	
	//pi=2*acos(0.0);
	//while(1){
	//	vk.clear(); 
	//d=1000000007;
	
	cin>>t;

	
	

	for(cas=1;cas<=t;cas++){
		vk.clear();
		vk.assign(16,0);
		vc.clear();
		vvc.clear();

		cin>>n;
	
		for(i=0;i<4;i++){
			vc.clear();
			for(j=0;j<4;j++){
				cin>>a;
				vc.push_back(a);
			}
			vvc.push_back(vc);
		}

		for(i=0;i<4;i++){
			vk[vvc[n-1][i]-1]++;
		}
		cin>>n;
		vvc.clear();
		for(i=0;i<4;i++){
			vc.clear();
			for(j=0;j<4;j++){
				cin>>a;
				vc.push_back(a);
			}
			vvc.push_back(vc);
		}

		for(i=0;i<4;i++){
			vk[vvc[n-1][i]-1]++;
		}

		a=-1;
		b=0;
		for(i=0;i<16;i++){
			if(vk[i]==2){
				a=i+1;
				b++;
			}
		}
		if(b==1){
			cout<<"Case #"<<cas<<": "<<a<<endl;
		}
		else if(b>1){
			cout<<"Case #"<<cas<<": "<<"Bad magician!"<<endl;
		}
		else {
			cout<<"Case #"<<cas<<": "<<"Volunteer cheated!"<<endl;
		}
	}



	return 0;

} 
