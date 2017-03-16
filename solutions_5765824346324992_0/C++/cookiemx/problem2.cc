#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int cases;
	cin>>cases;
	for(int t =0;t<cases;t++){
		int nb,n;
		cin>>nb>>n;
		vector<int> a,b;
		a.resize(nb);
		b.resize(nb);
		for(int j =0;j< nb;j++){
			cin >> a[j];
		}
		int cycle=0;
		b = a;
		int minb;
		do{
			minb = *min_element(b.begin(),b.end());
		//	cout<<minb<<endl;
			for(int k = 0;k<nb;k++){
				b[k]-=minb;
				if(b[k]==0){
					b[k]+=a[k];
					cycle++;
				}
			}	
		}while(a!=b);
		n = n%cycle +cycle;
		/*
		cout<<cycle<<" "<<n<<endl;
		
		for( vector<int>::const_iterator i = a.begin(); i != a.end(); ++i){
			cout<<*i<<" ";
		}
		cout<<endl;
		for( vector<int>::const_iterator i = b.begin(); i != b.end(); ++i){
			cout<<*i<<" ";
		}
		cout<<endl;
		*/
		int count = 0;
		if(n<=nb){cout<<"Case #"<<t+1<<": "<<n<<endl;}
		else{
			b = a;
			count = nb;
			int index;
			while(n-count>0){
				minb = *min_element(b.begin(),b.end());
				for(int k = 0;k<nb;k++){
					b[k]-=minb;
					if(b[k]==0){
						b[k]+=a[k];
						count++;
						//cout<<count<<" ";
						if(n==count){
							index = k;
							break;
						}
					}
				}
				//cout<<endl;
			}

			cout<<"Case #"<<t+1<<": "<<index+1<<endl;
		}
	}
	return 0;
}

