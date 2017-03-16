#include <iostream>
#include <vector>
using namespace std;

vector<int> Mb(1000);
vector<int> Wt(1000);

int main() {
	

	freopen("debug\\B-small-attempt3.in","r",stdin);
//	freopen("debug\\in.txt","r",stdin);
	freopen("debug\\out.txt","w",stdout);
	int testcases = 0;

	long long B=0, N=0;
	int sm = 0,st = 0;
	int mp = 0,mt = 0;
	int cycle = 0;
	int flag = 0;
	int N2;
	int jj;
	cin>>testcases;

	for (int i=0; i<testcases; i++) {
		cin>>B;
		cin>>N;
		mp = 0;
		for (int j=0; j<B; j++) {
			cin>>Mb[j];
			if(mp<Mb[j])
				mp = Mb[j];
		}
		flag = 0;

		for (jj=1; jj<20000; jj++){
			flag = 0;
			mt = mp*jj;
			if (mt ==23976)
				mt = mt;
			for (int k=0; k<B; k++){
				if (mt%Mb[k]!=0){
					flag = 1;
					break;
				}
			}
			if (flag ==0)
				break;
		}
		if (jj==20000)
			cout<<"error!"<<endl;

		cycle = 0;
		for (int j=0; j<B; j++ )
			cycle+=(mt/Mb[j]);

		

		N2 = (N-1)%cycle+1;

		if (i==60){
//			for (int j=0; j<B; j++)
//				cout<<Mb[j]<<endl;
//			cout<<N<<endl;
//			cout<<mt<<" "<<cycle<<" "<<N2<<endl;
		}
		for (int j=0; j<B; j++)
			Wt[j] = 0;
		
		sm = 0;
		for (int j=0; j<N2-1; j++){
			Wt[sm]+=Mb[sm];
			st = Wt[sm];
			for (int k = B-1; k>=0;k--){
				if(st>=Wt[k]){
					sm = k;
					st = Wt[k];
					
				}
			}
//			cout<<sm<<endl;
			for (int k = 0; k<B;k++){
				Wt[k]-=st;
			}

		}

		cout<<"Case #"<<i+1<<": "<<sm+1<<endl;

		


	}//end i testcases




	return 0;
}