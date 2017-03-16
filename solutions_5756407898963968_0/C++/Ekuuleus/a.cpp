#include <iostream>
using namespace std;



void solve (int ci){


	int row ;
	int row2 ;
	int cards[4] ;
	int junk ;
	int match;
	int card ;

 	cin >> row ; 

	for (int irow = 1 ; irow <=  4 ; irow++){
		if (row == irow){
			cin >> cards[0] >> cards[1] >> cards[2] >> cards[3] ;
		} else {
			cin  >> junk  >> junk >> junk >> junk ;
		}
	}
	match = 0;
	card = 0 ;

	cin >> row ;

	
        for (int irow = 1 ; irow <= 4 ; irow++){
                if (row == irow){
			for ( int icol2 = 0 ; icol2<4 ; icol2 ++){
				cin >> junk ;

				for ( int icol = 0 ; icol < 4 ; icol++ ){
					if (cards[icol] == junk	) {
						match++;
						card = junk ;
					}
				}
			}
		} else {
                        cin  >> junk  >> junk >> junk >> junk ;
                }
        }

	cout << "Case #" << ci << ": " ;
	switch (match) {
		case 0 : cout << "Volunteer cheated!" << endl ; break ;
		case 1 : cout << card << endl ; break  ;
		default : cout << "Bad magician!" << endl ;
	}

}



int main(){
	int c;
	cin >> c;
	
	for (unsigned int ci = 1 ; ci <= c ; ++ci ){
		solve (ci);
	}
}



