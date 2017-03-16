#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<stdint.h>
#include<map>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

/*
int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	in.open("test.txt");
	out.open("out.txt");
	in>>CaseNum;
	for(int Case=0;Case<CaseNum;Case++){



	out<<"Case #"<<Case+1<<":";
	}
	return 0;
}
*/
int NOTPOSSIBLE=0;


int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	//in.open("test.txt");
	//in.open("A-small-attempt0.in");
	in.open("A-large.in");
	out.open("out.txt");
	in>>CaseNum;
	int N;
	char s[200];
	char ch[200];
	int num[104][200];
	int a[200];
	int l,n,nl,t,ans;
	for(int Case=0;Case<CaseNum;Case++){
		in>>N;
		NOTPOSSIBLE=0;
		for(int i=0;i<N;i++){
			in>>s;
			fill(num[i],num[i]+101,0);
			if(i==0){
				l=strlen(s);
				n=0;

				for(int j=0;j<l;j++){
					if(j>0&&s[j]==s[j-1]){
						num[i][n-1]++;
					}
					else{
						ch[n]=s[j];
						n++;
					}

				}
				nl=n;
				continue;
			}
			l=strlen(s);
			n=0;
			for(int j=0;j<l;j++){
					if(j>0&&s[j]==s[j-1]){
						num[i][n-1]++;
					}
					else{
						if(s[j]!=ch[n]){
							NOTPOSSIBLE=1;
							break;
						}
						n++;
					}

			}
			if(n!=nl){
							NOTPOSSIBLE=1;
							continue;
			}

		}
		if(NOTPOSSIBLE){
			out<<"Case #"<<Case+1<<": Fegla Won"<<endl;
			continue;
		}

		ans=0;
		for(int i=0;i<nl;i++){
			for(int j=0;j<N;j++){
				a[j]=num[j][i];
			}
			sort(a,a+N);
			t=a[N/2];
			for(int j=0;j<N;j++){
				ans+=abs(a[j]-t);
			}
		}

		
	out<<"Case #"<<Case+1<<": "<<ans<<endl;
	}
	return 0;
}