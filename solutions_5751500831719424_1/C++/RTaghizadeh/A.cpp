#include<iostream>
#include<fstream>

using namespace std;
int f(int a[100],int n)
{
	int min=1000000;
	for(int i=1;i<=100;i++){
		int m=0;
		for(int j=0;j<n;j++){
			m+=(i>a[j]?i-a[j]:a[j]-i);

		}
		if(m<min)
			min=m;
	}
	return min;
}
int main(){
	ofstream fout;
	fout.open("d:\\ans.txt");
	cout.rdbuf(fout.rdbuf());

	ifstream fin;
	fin.open("d:\\1.in");
	cin.rdbuf(fin.rdbuf());
	int t,te,n,a[100];
	int i,j,k,ans;
	cin>>t;
	char s[101][101];
	for(te=1;te<=t;te++){
		cin>>n;
		ans=0;
		for(i=0;i<n;i++)
			cin>>s[i];
		bool b=true;
		while(strlen(s[0])>0 && b){
			char x=s[0][0];
			for(i=0;i<n && b;i++){
				a[i]=0;
				while(s[i][a[i]]==x)
					a[i]++;
				if(a[i]==0)
					b=false;
				strcpy(s[i],s[i]+a[i]);
			}
			ans+=f(a,n);
		}
		for(i=0;i<n && b;i++)
			if(strlen(s[i])>0)
				b=false;

		cout<<"Case #"<<te<<": ";
		if(b)
			cout<<ans<<endl;
		else
			cout<<"Fegla Won"<<endl;

	}
	return 0;
}