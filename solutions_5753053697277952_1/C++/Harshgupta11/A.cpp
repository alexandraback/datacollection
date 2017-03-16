#include "bits/stdc++.h"

using namespace std;

#define mp make_pair
typedef long long int ll;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

struct party{
	char ch;
	int n;
};

int func(party A, party B){
	if(A.n > B.n) return 1;
	return 0;
}
void solve()
{
    int i,j,N,temp,k;
    cin >> N;
    party A[N];
    char ch = 'A';
    for(i = 0;i<N;++i){
    	cin >> temp;
        A[i].ch = ch;
        A[i].n = temp;
        ++ch; 
    }
    sort(A,A+N,func);
    for(j = 1;j<N;++j){
        while(A[j].n == A[j-1].n && j < N) ++j;
        while(A[j].n != A[j-1].n && j < N){
        	if(j % 2 == 1){
               cout << A[0].ch << ' ';
               --A[0].n;
               k = 1;  
        	}
        	else k = 0;
	        for(i = k;i<j;){
	        	if(i+1 < j){
	        		cout << A[i].ch << A[i+1].ch << ' ';
	        		--A[i].n;
	        		--A[i+1].n;
	        		i+=2;
	        	}
	        	else{
	        		cout << A[i].ch << ' ';
	        		--A[i].n;
	        		++i;
	        	}
	        }
        }
    }
    while(A[N-1].n != 0){
       	if(N % 2 == 1){
               cout << A[0].ch << ' ';
               --A[0].n;
               k = 1;  
        	}
        	else k = 0;
    	for(i = k;i<N;){
	        	if(i+1 < N){
	        		cout << A[i].ch << A[i+1].ch << ' ';
	        		--A[i].n;
	        		--A[i+1].n;
	        		i+=2;
	        	}
	        	else{
	        		cout << A[i].ch << ' ';
	        		--A[i].n;
	        		++i;
	        	}    		
    	}
    }
    cout << '\n';
}

int main()
{
	int T;
	cin >> T;
	for(int i = 1;i<=T;++i){
		cout << "Case #" << i << ": ";
		solve();
	}
    return 0;
}
