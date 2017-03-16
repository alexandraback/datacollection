#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<bitset>
#include<map>
#include<utility>
#include<ctime>
#include<cmath>
//TEMPLATE V1
#define nl printf("\n")
#define sp printf(" ")
#define i_ scanf
#define o_ printf
#define ini(x) scanf("%d",&x)
#define outi(x) printf("%d",x)
#define inf(x) scanf("%f",&x)
#define outf(x) printf("%f",x)
#define ind(x) scanf("%lf",&x)
#define outd(x) printf("%lf",x)
#define inll(x) scanf("%I64d",&x)
#define outll(x) printf("%I64d",x)
#define inc(x) scanf("%c",&x)
#define outc(x) printf("%c",x)
#define ins(x) scanf("%s",&x)
#define outs(x) printf("%s",x)

#define loop(var,x,y) for(int var=x;var<y;var++)
#define loopn(var,x,y) for(int var=x;var<=y;var++)
#define rloop(var,x,y) for(int var=x-1;var>=y;var--)
#define rloopn(var,x,y) for(int var=x;var>=y;var--)
#define reset(x,y) memset(x,y,sizeof(x));
#define stop fflush(stdin);getchar()
#define PB push_back
#define MP make_pair
#define st first
#define nd second
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
using namespace std;

typedef long long Int;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

//I/O
   inline void cins(string &x){
   	char temp[1000000];
   	scanf("%s",&temp);
	x=temp;
   }
   inline void couts(string x){
   	printf("%s",x.c_str());
   }
//I/O

//CONVERT
   inline string ITOS(int x){
   	char temp[1000000];
   	sprintf(temp,"%d",x);
   	return temp;
   }
   inline string ITOLL(Int x){
   	char temp[1000000];
   	sprintf(temp,"%I64d",x);
   	return temp;
   }
   inline int STOI(string x){
	char temp[1000000];
	strcpy(temp,x.c_str());
	int ret;sscanf(temp,"%d",&ret);
	return ret;
   }
   inline Int STOLL(string x){
    char temp[1000000];
	strcpy(temp,x.c_str());
	Int ret;sscanf(temp,"%I64d",&ret);
	return ret;
   }
//CONVERT

//FILE
inline void OPEN(const string &s) {
freopen((s + ".in").c_str(), "r", stdin);
freopen((s + ".out").c_str(), "w", stdout);
}
//FILE
int px[]={-1,0,1,0,-1,-1,1,1};
int py[]={0,1,0,-1,-1,1,1,-1};

int main(){
	OPEN("AB");
	int T,i,j,n,k;
	int ans,a[101],b[101][101];
	char ch;
	string temp,s[101],str[101];
	cin>>T;
	int temp1;
	for(int t=1;t<=T;t++){
		cin>>n;
		for(i=1;i<=n;i++)
		str[i] = "";

		for(i=1;i<=n;i++){
			cin>>s[i];
			k = 0;
			for(j=0;j<s[i].length();j++){
				if(j == s[i].length()-1){
					str[i] += s[i][j];
					b[i][k] = j;	
				}
				else{
					if(s[i][j] == s[i][j+1]){
						temp1 = j; 
						while(s[i][j] == s[i][j+1]){
							j++;
							if(j == s[i].length()-1)
							break;
						}
						str[i] += s[i][j];
						b[i][k] = temp1; 
						k++;
					}
					else{
						str[i] += s[i][j];
						b[i][k] = j;
						k++;
					}
				}
			}
		}
		temp = str[1];
		for(i=1;i<=n;i++){
			if(str[i] != temp)
			break;
		}
		int f = 0;
		ans = 0;
		if(i <= n){
			cout<<"Case #"<<t<<": ";
			cout<<"Fegla Won"<<endl;
			continue;
		}
		else{
			for(i=0;i<str[1].length();i++){
				ch = str[1][i];
				for(j=1;j<=n;j++)
				{
					
					f = 0;
					k = b[j][i];
					while(s[j][k] == ch){
						k++;
						f++;
						if(k == s[j].length())
						break;
					}
					a[j] = f;
				}
				sort(a+1,a+n+1);
				for(j=1;j<=n;j++){
					
					ans += abs(a[j] - a[(n/2) + 1]);
				}
			}
			cout<<"Case #"<<t<<": ";
			cout<<ans<<endl;
		}
	}
	
}

