#include<bits/stdc++.h>

// Author : Archit Jain :) Delhi Technological University
//#pragma comment (linker, "/STACK:256000000")

#define mp(x,y) make_pair(x,y)
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define pi   3.14159265358979323846264338327950288

using namespace std;
typedef long long lld;
typedef pair<int,int> p;
//snippets
template<class T>  T gcd(T a,T b){if(b==0)return a;else return gcd(b,a%b);}
template<class T>T power(T a,T b){T result=1;while(b>0){if(b&1)	result = result * a;a = a*a;b>>=1;}return result;}
template<class T>T powerMod(T a,T b,T c){T result =1%c;while(b>0){if(b&1)result = (result * a)%c;a = (a*a)%c;b>>=1;}return result;}
template<class T>bool prime(T a){if(a==2)return true;else if(a%2==0)return false;for(int i=3;i*i<=a;i+=2){if(a%i==0)return false;}return true;}

#define MAX 27
int a[MAX];

int main()
{
	
	freopen("input.in","r",stdin);
	//freopen("output.txt","w",stdout);
	
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);

	int t,n;
	cin>>t;
	
	
	for(int tst=1;tst<=t;tst++)
	{
		cin>>n;
		
		
		int sum = 0;
		for(int i = 0;i<n;i++)
		{
			cin>>a[i];
			sum  =sum + a[i];
		}
		
		
		cout<<"Case #"<<tst<<": ";

	
		while(sum>0){
			
		    int done = 0;
			for(int i = 0;i<n;i++)
			{				
				if(a[i]==0)continue;
				
				a[i]-=1;
				
				int total = 0;
				for(int j = 0;j<n;j++)
					total = total + a[j];	
				
			
				int flag = 0;	
				for(int j = 0;j<n;j++){
					
					if(a[j]>(total/2))
					{
						flag = 1;
						break;
					}
				}
		
				if(flag)
					a[i]+=1;
				else{
					sum = sum - 1;
					cout<<char(i+'A')<<" ";
					done = 1;
					break;
				}
			}
			
		
			if(done==0 && sum>=2){
				
				for(int i = 0;i<n;i++){
					
					for(int j = 0;j<n;j++){
						
						if(a[i]==0 || a[j]==0) continue;
						
						if(i==j && a[i]<2)continue;
						
						a[i]--;
						a[j]--;
						
						int total = 0;
						for(int k= 0;k<n;k++)
							total = total + a[k];
						
						bool flag = 0;
						for(int k = 0;k<n;k++){
							
							if(a[k]>(total/2)){
								flag = 1;
								break;
							}
						}
						
						if(flag==1){
							a[i]++;
							a[j]++;
						}
						else{
							sum-=2;
							cout<<char(i+'A')<<char(j+'A')<<" ";
							break;
						}
					}
				}
			}
			
		}
		cout<<endl;
	
	}
	
	return 0;
}

