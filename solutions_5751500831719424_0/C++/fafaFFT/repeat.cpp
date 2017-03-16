#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

typedef long long LL;
typedef pair<int,int> PI;
typedef vector<int> VI;
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define FT first
#define SD second
#define Y first
#define X second

vector<string>token(string a) {
    vector<string>w;a.push_back(' ');
    while(!a.empty()){w.push_back(a.substr(0,a.find(" ")));a=a.substr(a.find(" ")+1,a.size()-1);}return w;
}

map<string,int> mapik;
vector<string> amapik;
int dodaj(string a) {if(mapik.count(a)==0) {mapik[a]=mapik.size()-1;amapik.PB(a);}return mapik[a];}

#define INF 1000000000

char tmp_str[1000];
string scanf_string() {
	scanf("%s",tmp_str);
	return tmp_str;
}

const int N = 1000;
int n;

string data[N];
int wsk[N];
vector<int>ilosci[N];

void czysc() {
	for(int i=0;i<N;i++) {ilosci[i].clear();wsk[i]=0;}
}

int main() {
	int d;scanf("%d",&d);
	for(int ind=1;ind<=d;ind++) {
		scanf("%d",&n);
		
		czysc();
		for(int i=0;i<n;i++) {
			data[i] = scanf_string();
		}
		int res = INF;
		int top = 0;
		char tchar = 0;
		while(top<data[0].size()&&res!=-1)
		{
			tchar=data[0][top];
			for(int i=0;i<n;i++) {
				if(wsk[i]>=data[i].size()||data[i][wsk[i]]!=tchar) {
					res = -1;
					break;
				}
				int ile = 1;
				wsk[i]++;
				while(wsk[i]<data[i].size() && data[i][wsk[i]]==tchar) {
					ile++;wsk[i]++;
				}
				ilosci[i].PB(ile);
			}
			top = wsk[0];
		}
		
		for(int i=0;i<n;i++) 
		
			if(wsk[i] != data[i].size())
				res = -1;
		
		/*for(int i=0;i<n;i++) 
		{
			printf("%d-", i);
			for(int i2=0;i2<ilosci[i].size();i2++) 
				printf("%d ",ilosci[i][i2]);
			printf("\n");
		}*/
		
		if(res != -1) {
			res = 0;
			for(int i=0;i<ilosci[0].size();i++) {
				int besttutaj = INF;
				for(int i2=0;i2<1000;i2++) {
					
					int wart = i2;//ilosci[i2][i];
					int suma = 0;
					for(int k=0;k<n;k++) {
						if(ilosci[k].size()!=ilosci[0].size())
							printf("DUPA");
						suma += abs(wart-ilosci[k][i]);
					}
					besttutaj = min (besttutaj,suma);
				}
				res += besttutaj;
				
			}
		
		}
		
		printf("Case #%d: ",ind);
		if(res ==-1) {
			printf("Fegla Won\n");
		}
		else printf("%d\n", res);
	}
	return 0;
}
