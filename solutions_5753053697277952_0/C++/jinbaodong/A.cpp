#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[30];
bool check(){
	int flag=0;
	for (int i=0;i<26;i++){
		if (a[i]==0) flag++;
	}
	if (flag==26) return true;
	return false;
}
bool check2(){
	int flag=0,flag2=0;
	for (int i=0;i<26;i++){
		if (a[i]!=0){
			flag++;
			if (a[i]==1) flag2++;
		}
	}
	if (flag==3 && flag2==flag) return true;
	return false;
}
int main(){
	int t,n;
	cin>>t;
	for (int cas=1;cas<=t;cas++)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		for (int i=0;i<n;i++)
			cin>>a[i];
		cout<<"Case #"<<cas<<": ";
		while (true){
			if (check()==true) break;
			if (check2()==true){
				for (int i=0;i<26;i++){
					if (a[i]){
						cout<<char(i+'A')<<" ";
						a[i]--;
						break;
					}
				}
				continue;
			}
			int Max=0,index=-1;
			for (int i=0;i<26;i++){
				if (a[i]>Max){
					Max=a[i];
					index=i;
				}
			}
			a[index]--;
			Max=0;
			int index2=-1;
			for (int i=0;i<26;i++){
				if (a[i]>Max){
					Max=a[i];
					index2=i;
				}
			}
			a[index2]--;
			cout<<char(index+'A')<<char(index2+'A')<<" ";
		}
		cout<<endl;
	}
	return 0;
}