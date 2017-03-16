#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define FILE "A"
int main(){
	freopen(FILE ".in","r",stdin);
	freopen(FILE ".out","w",stdout);
	int Tests;
	cin>>Tests;
	for(int numTest = 1; numTest <= Tests; ++numTest){
		int r1;
		cin>>r1;
		--r1;
		int cnt[20];
		memset(cnt,0,sizeof cnt);
		int arr1[4][4], arr2[4][4];
		int r2;
		for(int i = 0; i < 4; ++i){
			for (int j = 0; j < 4; ++j)
				cin>>arr1[i][j];
		}
		cin>>r2;
		--r2;
		for(int i = 0; i < 4; ++i){
			for(int j = 0; j < 4; ++j){
				cin>>arr2[i][j];
			}
		}
		for(int i = 0; i < 4; ++i){
			cnt[arr1[r1][i]]++;
			cnt[arr2[r2][i]]++;
		}
		cout<<"Case #"<<numTest<<": ";
		int cntok = 0;
		int value;
		for(int i = 0; i < 20; ++i){
			if(cnt[i] >= 2){
				++cntok;
				value = i;
			}
		}
		if(cntok == 1){
			cout<<value<<endl;
		}
		if(cntok == 0){
			cout<<"Volunteer cheated!"<<endl;
		}
		if(cntok >= 2){
			cout<<"Bad magician!"<<endl;
		}
	}
}