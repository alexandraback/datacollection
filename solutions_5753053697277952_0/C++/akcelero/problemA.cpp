#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int n, tab[30];

bool valid(){
	int sum = 0;
	for(int i=0;i<n;i++){
		if(tab[i]<0)
			return false;
		sum += tab[i];
	}
	for(int i=0;i<n;i++)
		if(tab[i]*2 > sum)
			return false;
	return true;
}

void start(){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			tab[i]--;
			tab[j]--;
			if(valid()){
				cout<<(char)('A' + i)<<(char)('A'+j)<<" ";
				start();
				break;
			}
			tab[i]++;
			tab[j]++;
		}
	}
	for(int i=0;i<n;i++){
		tab[i]--;
		if(valid()){
			cout<<(char)('A' + i)<<" ";
			start();
			break;
		}
		tab[i]++;
	}
}

int main(){
	int t;
	cin >> t;
	for(int k = 0; k < t; k++){
		cin >> n;
		for(int i=0;i<n;i++)
			cin>>tab[i];
		cout<<"Case #"<<(k+1)<<": ";
		start();
		cout<<endl;
	}
	return 0;
}