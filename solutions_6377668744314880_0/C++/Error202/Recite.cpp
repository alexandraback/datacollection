#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
#include <queue>
#include <string>
#include <time.h>
#include <math.h>
#include <cwchar>
#include <algorithm>
#include <termios.h>
#include <stdlib.h>
#define PB push_back
#define MP make_pair
using namespace std;
const int               Maxn=200,Maxm=300000;
int N,ct[Maxn];
string st[Maxn];
int check(){
	for (int i=1;i<=N;i++) if (ct[i]<5) return 0;
	return 1;
}
wchar_t a[Maxn][200];
void rand_sh(int *a , int N){
	for (int i=N;i>=1;i--){
		int p = rand() % i + 1;
		swap(a[i],a[p]);
	}
}
char G[50];
int main(){
    srand(time(NULL));
    printf("New or Load?\n"); 
	string s;
    cin >> s;
    if (s=="Load"){
    	freopen("sv.txt","r",stdin);
    	cin >> N;
    	for (int i=1;i<=N;i++) cin >> ct[i];
    }
    freopen("/Users/MAC/Desktop/My Work/1.in","r",stdin);                
    cin >> N;
    for (int i=1;i<=N;i++) {    	
    	char d = getchar();
    	st[i].PB(d);
    	while(d!='	') d = getchar() , st[i].PB(d);    	
    	wscanf(L"%ls",a[i]);
    	// wprintf(L"%ls\n",a[i]);
    	gets(G);
    }
    

    freopen("/dev/tty","r",stdin);	
    int rk[2000];
	while(!check()){
		vector<int> F;
		for (int i=1;i<=N;i++) rk[i] = i;		 
		rand_sh(rk,N);
	   	for(int i=1;i<=N;i++){	   		
	   		if (ct[rk[i]] == 5) continue;
		    cout <<"\n"<< st[rk[i]]<<"\n";
		    char c = getchar();
			while(c!='\n') c = getchar();
			wprintf(L"%s : %ls\n\n",st[rk[i]].c_str(),a[rk[i]]); 		
			cin >> c;
			getchar();
			if (c=='s'){				
				freopen("sv.txt","w",stdout);
				cout << N << endl;
				for (int i=1;i<=N;i++) printf("%d ",ct[i]);
				return 0;
			}
			if (c==';') ct[rk[i]]++;		    
			else F.PB(rk[i]);			
	   		system("clear");
	    }	
	    for (int i=0;i<F.size();i++) 	    	
	    	wprintf(L"%s %ls\n",st[F[i]].c_str(),a[F[i]]);	
    }
}