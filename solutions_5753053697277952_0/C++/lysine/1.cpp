#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int nn,n,s;
int p[30],t[30];

bool cmp(int a, int b){
	return p[a] > p[b];
}


int main(){
	
	cin >> nn;
	rep(ii,nn){
		cin >> n;
		rep(i,n){cin>>p[i];s+=p[i];t[i]=i;}
		cout << "Case #"<<ii+1<<": ";

		while(s > 0){
			rep(i,n)t[i]=i;
			sort(t, t+n,cmp);
			if(p[t[1]]*2 > (s-1)){
				cout << char('A'+t[0]) << char('A'+t[1])<<" ";
				s-=2;
				p[t[0]]--;
				p[t[1]]--;
			}
			else {
				cout << char('A'+t[0])<<" ";
				s--;
				p[t[0]]--;
			}
		}
		cout << endl;
	}

}