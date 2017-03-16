#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main () {
	
	ifstream in ("A-small-attempt0.in");
	ofstream cout("small.out");
	int T;
	in>>T;
	
	for (int t=0; t<T; t++) {
		list<int> nums;
		
		int rowN, temp;
		
		in>>rowN;
		for (int i=0; i<4; i++) {
			if (i==rowN-1) {
				for (int j=0; j<4; j++) {
					in>>temp;
					nums.push_back(temp);
				}
			}
			else in>>temp>>temp>>temp>>temp;
		}
		
		in>>rowN;
		for (int i=0; i<4; i++) {
			if (i==rowN-1) {
				for (int j=0; j<4; j++) {
					in>>temp;
					nums.push_back(temp);
				}
			}
			else in>>temp>>temp>>temp>>temp;
		}
		
		nums.sort();
		list<int> nums_copy(nums.begin(), nums.end());
		
		nums.unique();
				
		cout<<"Case #"<<t+1<<": ";
		if (nums.size() == 7) {
			for (list<int>::iterator i=nums_copy.begin(); i!=nums_copy.end(); i++) {
				if (*i == *(++i)) {
					cout<<*i;
					break;
				} else {
					--i;
				}
			}
		}
		else if (nums.size() > 7) cout<<"Volunteer cheated!";
		else cout<<"Bad magician!";
		cout<<"\n"; 
	}
	
	return 0;
}
