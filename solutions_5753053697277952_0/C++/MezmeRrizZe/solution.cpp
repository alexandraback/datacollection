#include <iostream>
#include <fstream>
using namespace std;
int main(){ 
    ofstream fout("A.out"); 
	int cases;
	cin >> cases;
	int input;
	for ( int j = 0 ; j < cases ; j ++ ){
		cin >> input;
		int senate[input];

		for ( int i = 0 ; i < input ; i ++ ){
			senate[i] = 0;
		}
		fout << "Case #" << j + 1 <<": " ;
			int tot = 0;
		for ( int i = 0 ; i < input ; i ++ ){
		
			cin >> senate[i];
			tot += senate[i];
		}
		while ( true ){
			char sen = 0, sen2 = 0;
			int max = 0;
			for ( int i = 0 ; i < input ; i  ++ ){
				if ( senate[i] > max ){
					sen = 65 + i;
					max =  senate[i];
					continue;
				}
				if ( senate[i] == max ){
					sen2 = 65 + i;
				}
			}
			if ( max == 0 ) {
				fout << endl;
				break;
			}
			if ( sen2 - 65 >= 0 && senate[sen2 - 65] == max ){
				if ( tot - 2 == 1 ){
					fout << sen << " ";
					senate[sen -65 ] -- ;
					tot -=1;
					continue;
				}
				fout << sen2 << sen << " ";
					senate[sen - 65] --;
					senate[sen2 - 65] --;
					tot -= 2;
			}
			else {
				if ( sen - 65 >= 0 ){
					fout << sen << " ";
					senate[sen - 65] --;
					tot -= 1;
				}
			}
		}
	

	}
	
	return 0;
}
