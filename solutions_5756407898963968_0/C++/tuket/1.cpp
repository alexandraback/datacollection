#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	
	int nn;
	cin>>nn;
	
	for(int kk=0; kk<nn; kk++){
		
		int a1;
		cin>>a1;
		set<int> s1;
		for(int i=0; i<4; i++){
			int aux;
			if(i+1 == a1)
			for(int j=0; j<4; j++){
				cin>>aux;
				s1.insert(aux);
			}
			else
			for(int j=0; j<4; j++)
				cin>>aux;
		}
		
		//for(set<int>::iterator it=s1.begin(); it != s1.end(); ++it)
		//	cout << *it << endl;
		
		int a2;
		cin>>a2;
		set<int> s2;
		for(int i=0; i<4; i++){
			
			int aux;
			if(i+1 == a2)
			for(int j=0; j<4; j++){
				cin>>aux;
				s2.insert(aux);
			}
			else
			for(int j=0; j<4; j++)
				cin>>aux;
			
		}
		
		set<int> tot;
		set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(tot, tot.begin()));
		
		cout << "Case #" << kk+1 << ": ";
		if( tot.size() == 0 ){
			cout << "Volunteer cheated!" << endl;;
		}
		else if( tot.size() == 1 ){
			set<int>::iterator it=tot.begin();
			cout << *it << endl;
		}
		else{
			cout << "Bad magician!" << endl;
		}
		
	}
	
}
