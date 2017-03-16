#include<cstdio> 
#include<cstring> 
#include<cctype> 
#include<cmath> 
#include<cstdlib> 
#include<ctime> 
#include<iostream> 
#include<iomanip> 
#include<sstream> 
#include<vector> 
#include<string> 
#include<queue> 
#include<stack> 
#include<utility> 
#include<algorithm> 
#include<map> 
#include<set> 
#include<bitset> 
#include<sstream>
#include<limits>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

string base(string s){
	string resp="";
	resp+=s[0];
	int tam=s.size();	
	for(int i=1;i<tam;i++){
		if(s[i]!=s[i-1]){
			resp+=s[i];
		}
	}
	return resp;
}

vi base2(string s){
	vi resp;
	int qnt=1;
	int tam=s.size();	
	for(int i=1;i<tam;i++){
		if(s[i]!=s[i-1]){
			resp.push_back(qnt);
			qnt=1;
		}
		else{
			qnt++;
		}
	}
	resp.push_back(qnt);
	return resp;
}

vi v[105];

int main(){
	int T,N;
	char s[200][200];
	scanf("%d\n",&T);
	for(int caso=1;caso<=T;caso++){
			scanf("%d\n",&N);
			gets(s[0]);
			string b=base(string(s[0]));
			v[0]=base2(string(s[0]));
			bool pode=true;
			for(int i=1;i<N;i++){
				gets(s[i]);
				string b2=base(string(s[i]));	
				//printf("%s %s*\n",b2.c_str(),b.c_str());			
				if(b2!=b){pode =false;}
				v[i]=base2(string(s[i]));
			}
			ll soma=0;
			if(!pode){printf("Case #%d: Fegla Won\n",caso);}
			else{
				int M=v[0].size();
				for(int col=0;col<M;col++){
					vi par(N);					
					for(int lin=0;lin<N;lin++){
						par[lin]=v[lin][col];
					}
					sort(par.begin(),par.end());
					for(int i=0;i<N;i++){
						soma+=(ll)abs(par[i]-par[N/2]);
					}
				}
				printf("Case #%d: %lld\n",caso,soma);
			}
	}
	return 0;
}
