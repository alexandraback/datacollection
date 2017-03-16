#include <iostream>
#include <vector>


using namespace std;
vector<int> mush(1000);

int main() {
	freopen("debug\\A-large.in","r",stdin);
	freopen("debug\\out.txt","w",stdout);

	int testcases = 0;
	int nint = 0;
	int temp,temp2;

	long long sum1 = 0,sum2 = 0;

	int ldif = 0;
	cin>>testcases;

	for (int i=0; i<testcases; i++) {
		cin>>nint;
		for (int j=0; j<nint; j++) {
			cin>>mush[j];
		}//end for j

		cout<<"Case #"<<i+1<<": ";
		//first method
		sum1 = 0;
		temp = mush[0];
		for (int j=1; j<nint;j++){
			if (temp>mush[j]){
				sum1+=(temp-mush[j]);
			}
			temp = mush[j];
		}
		cout<<sum1<<" ";
		
		//second method
		sum2 = 0;
		ldif = 0;
		temp = mush[0];
		for (int j=1;j<nint; j++) {
			temp2 = temp-mush[j];
			if(ldif<temp2)
				ldif = temp2;
			temp = mush[j];
		}

//		cout<<ldif<<endl;
		temp = mush[0];
		for (int j=1;j<nint; j++){
			if(temp>ldif){
				sum2+=ldif;
			}
			else{
				sum2+=temp;
			}
			temp = mush[j];
		}
		cout<<sum2<<endl;
		
	}//end for testcases
	
	
	return 0;
}