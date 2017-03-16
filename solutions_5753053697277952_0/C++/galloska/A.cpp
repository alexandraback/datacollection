#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int num[55];

bool Valid(int n){	
	int s = 0;
	for(int i=0;i<n;i++)
		s += num[i];
		
	for(int i=0;i<n;i++)
		if( num[i] > s / 2 )
			return 0;
			
	return 1;	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,t,u=1;
	
	cin>>t;
	
	while(t--){
		cin>>n;
	
		int tot = 0;
		for(int i=0;i<n;i++){
			cin>>num[i];
			tot += num[i];
		}
		
		int s = 0;
		
		cout<<"Case #"<<u++<<":";
		while(s<tot){
			cout<<" ";
		
			int k = 0;
	
			for(int i=0;i<n;i++){
		
				if(!num[i]) continue;
				num[i]--;
			
				if( Valid( n ) ){
					char aux = i+'A';
					cout<<aux;
					k = 1;
					s++;
					break;
				}
			
				num[i]++;
			
			}
			if(k) continue;
		
			for(int i=0;i<n;i++){
		
				for(int j=i;j<n;j++){
					if(!num[i] || !num[j]) continue;
					if(i==j && num[i]<=1) continue;
					num[i]--;
					num[j]--;
			
					if( Valid( n ) ){
						char aux = i+'A';
						cout<<aux;
						aux = j+'A';
						cout<<aux;
						s += 2;
						k = 1;
						break;
					}
			
					num[i]++;
					num[j]++;
				}
			}
		}
		cout<<endl;
		
	}
	return 0;
}








