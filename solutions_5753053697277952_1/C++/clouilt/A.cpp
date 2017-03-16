#include <iostream>
#include <algorithm>
using namespace std;
int T, N;
int arr[29];

int main(){
	cin>>T;
	for(int cs = 1; cs<=T; ++cs){
		cin>>N;
		for(int i=0; i<N; ++i){
			cin>>arr[i];
		}
		cout<<"Case #"<<cs<<":";

		int last = N;
		while( last ){
			int m = -1;
			int na = -1;
			int nb = -1;
			int c = 0;
			for(int i=0; i<N; ++i){
				if(arr[i] > m){
					m = arr[i];
					na = i;
					c = 1;
				}else if ( c == 1 && arr[i] == m){
					++c;
					nb = i;
				}
			}
			if(c == 1){
				cout<<" "<<(char)('A' + na);
				if(!--arr[na])
					--last;
			}
			if(c == 2){
				for(int i = 0; i<N; ++i){
					if(i == na || i == nb){
						continue;
					}

					for(int j=0; j < arr[i]; ++j){
						cout<<" "<<(char)('A'+i);
					}
					if(arr[i])
						--last;
					arr[i] = 0;
				}

				for(int i = 0; i<arr[na]; ++i){
					cout<<" "<<(char)('A'+na)<<(char)('A'+nb);
				}
				arr[na]=arr[nb]=0;
				last -= 2;
			}
			// cout<<last<<endl;
		}
		cout<<endl;
	}
	return 0;
}
