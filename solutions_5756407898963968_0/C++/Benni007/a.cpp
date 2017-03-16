/* BA 2014 */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <limits>
#include <limits.h>
#include <iomanip>


using namespace std;
#define pb push_back
#define EPS 0.00001
#define For(x,y) for ( int (x) = 0; (x) < (y); (x)++ )
#define MAX 1
#define dim 4

int main(){
	int numCases;
	cin >> numCases;
	for(int caseN=1; caseN <= numCases; caseN++){
		int first;
		cin >> first;
		vector<vector<int> > a = vector< vector<int> >(4, vector<int>(4,0));
		For(i,dim){
			For(j,dim){
				cin >> a[i][j];
			}
		}
		vector<vector<int> > b = vector< vector<int> >(4, vector<int>(4,0));
		int second;
		cin >> second;
		For(i,dim){
			For(j,dim){
				cin >> b[i][j];
			}
		}
		string outBadMagic = "Bad magician!";
		string outCheated = "Volunteer cheated!";
		/*********************************/

		//cout << "First answer is" << first << endl;
		//cout << "Second answer is" << second << endl;


		int count = 0;
		int rowB = second-1;
		int rowA = first-1;
		int theNumber = -1;

		For(col,dim){
			int current = b[rowB][col];
			//cout << "current is " << current << endl;
			For(colA,dim){
				//cout << "a[rowA][colA] is" << a[rowA][colA] << endl;
				if(a[rowA][colA] == current){
					count++;
					theNumber = current;
				}
			}
		}


		cout << "Case #" << caseN << ": ";
		if(count == 0){
			cout << outCheated << endl;
		} else if(count == 1){
			cout << theNumber << endl;
		} else {
			// count > 1
			cout << outBadMagic << endl;
		}
	}

	return 0;
}
