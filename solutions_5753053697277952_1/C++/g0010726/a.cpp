#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void exe();
int main(void)
{	
	int T;	cin >> T;
	for(int caseNum=1; caseNum<=T ; ++caseNum){
		cout << "Case #" << caseNum << ":";
		exe();
		cout << endl;	
	}
	return 0;
}

struct d{
	int c;
	int p;
};

void exe()
{
	int n; cin >> n;
	vector<d> arr(n);
	for(int i=0;i<n;++i){
		arr[i].c=i;
		cin >> arr[i].p;
	}
	sort(arr.begin(), arr.end(), [](auto &a,auto &b){return a.p>b.p;});
	for(int i=1;i<n;++i){
		for(int j=arr[i-1].p-arr[i].p;j>0;--j){
			for(int k=0;k<i;++k){
				cout << ' ' << (char)(arr[k].c + 'A');
			}
		}
	}
	for(int i=arr[n-1].p ; i>0 ; --i){
		if(n%2){
			cout << ' ' << 'A';
			for(int j=1 ; j<n ; j+=2) cout << ' ' << (char)('A'+j) << (char)('A'+j+1);
		}
		else{
			for(int j=0 ; j<n ; j+=2) cout << ' ' << (char)('A'+j) << (char)('A'+j+1);
		}
	}
}
