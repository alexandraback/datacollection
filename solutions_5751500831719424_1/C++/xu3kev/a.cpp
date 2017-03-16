#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
	string s[200];
	int n;
	char ch[200];
	int chs;
	int a[200][200];
	int b[200];
	
int main(){
	int TT;
	cin>>TT;


	for(int T=1;T<=TT;++T){
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>s[i];
		chs=1;
		ch[0]=s[0][0];
		for(int i=1;i<s[0].size();++i){
			if(s[0][i]!=s[0][i-1]){
				ch[chs]=s[0][i];
				++chs;
			}
		}
		int p;
		bool g=false;
		for(int i=0;i<n;++i){
			p=0;
			for(int j=0;j<chs;++j){
				a[i][j]=0;
				while(p<s[i].size()&&s[i][p]==ch[j]){
					++p;
					++a[i][j];
				}
				if(a[i][j]==0){
					g=true;
					break;
				}
			}
			if(p!=s[i].size())
				g=true;
			if(g)
				break;
		}
		if(g){
			cout<<"Case #"<<T<<": "<<"Fegla Won"<<"\n";
			continue;
		}
		int tmp=0;
		for(int i=0;i<chs;++i){
			for(int j=0;j<n;++j){
				b[j]=a[j][i];
			}
			sort(b,b+n);
			
			
			for(int j=0;j<n/2;++j){
				tmp+=b[n/2]-b[j];
			}
			for(int j=n/2;j<n;++j){
				tmp+=b[j]-b[n/2];
			}
		}
		
		
		
		
		cout<<"Case #"<<T<<": "<<tmp<<"\n";



	}
	return 0;
}
