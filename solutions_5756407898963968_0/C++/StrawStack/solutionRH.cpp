#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

//short hand for loops
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

//quick print for answer cases
int case_number;
#define gout case_number++, printf("Case #%d: ",case_number), cout
#define INF (1<<29)

//define necessary arrays here 
int a[4][4];
int b[4][4]; 

void main2(void){
	int i, j, first, sec, count, num;
	count = 0;
	
	cin >> first;
	first = first - 1;
	REP(i,4) cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
	
	cin >> sec;
	sec = sec - 1;
	REP(i,4) cin >> b[i][0] >> b[i][1] >> b[i][2] >> b[i][3];
		
	//compair them
	REP(i,4){
		REP(j,4){
			if(a[first][i] == b[sec][j]){
				count++;
				num = a[first][i];
			}
		}
	}
	
	//print result
	if(count == 1){
		int ans = num;
		gout << ans << endl;
	} else if(count > 1){
		string ans = "Bad magician!";
		gout << ans << endl;
	}else{
		string ans = "Volunteer cheated!";
		gout << ans << endl;
	}
}

int main(void){
	int number_of_test_cases, i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
