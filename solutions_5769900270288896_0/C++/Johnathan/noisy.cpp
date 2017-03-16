#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#define PI pair<int,int>

//int toDigit[15];

int deFrame(int r, int c){
	return r * c - 2 * r - 2 * c + 4;
}

int frame(int r, int c){
	return 2 * r + 2 * c  - 4;
}

int main(){
	freopen("input.in","r",stdin);
	//calcToDigit();
	freopen("output.out","w",stdout);
	int n = 0; 
	int t;
	cin >> t;
	while (n++ < t){
		int R,C,N;
		cin >> R >> C >> N;
		int answer = 0; 
		//small case
		if (R <= 2 && C <= 2){
			int total = R * C;
			if (total /2 >= N)
				answer = 0;
			else{

				if (R == 1 && C == 1)
					answer = 0;
				else if (  (R == 2 && C == 1) || ( R == 1 && C ==2 ) )
					answer = 1;
				else //r== 2 ==c
					answer = (N / 2) * 2;
			}
		}
		//even grids
		else if (R * C % 2 == 0){
			int total = R * C;
			if (total /2 >= N)
				answer = 0;
			else{
				//special case
				if (min(R,C) == 1){
					total = N - total /2;
					if (total <= 1)
						answer += total;
					else{
						answer += 1;
						answer += (total - 1) * 2;
					}
				}
				else if (min(R,C) == 2){
					total = N - total /2;
					if (total <= 2)
						answer += total * 2;
					else{
						answer += 2 * 2;
						answer += (total - 2) * 3;
					}						
				}
				//general case
				else{
					total = N - total /2;
					int onFrame = frame(R,C)/2;
					if (total <= 2){
						answer += total * 2;
					}
					else if (total <= onFrame){
						answer += 2 * 2;
						answer += (total - 2) * 3;
					}
					else{
						answer += 2 * 2;
						answer += (onFrame - 2)* 3;
						answer += (total - onFrame) * 4;
					}
				}
			}
		}
		//odd grids		
		else{
			int total = R * C;
			if (total /2 >= N - 1)
				answer = 0;
				
			else{
				int answer1 = 0;
				int answer2 = 0;
				int total1, total2;
				//special case
				if (min(R,C) == 1){
					//plan 1
					total1 = N - (total /2 );
					if (total1 <= 2)
						answer1 += total1 * 1;
					else{
						answer1 += 1 * 2;
						answer1 += (total1 - 2) * 2;
					}

					//plan 2
					total2 = N - total/2 -1;
					answer2 += (total2 * 2);
				}
				//general case
				else{
					//plan1
					total1 = N - (total /2);
					int onFrame = frame(R,C)/2;
					if (total1 <= 4){
						answer1 += total1 * 2;
					}
					else if (total1 <= onFrame){
						answer1 += 8;
						answer1 += (total1 - 4) * 3;
					}
					else{
						answer1 += 4 * 2;
						answer1 += (onFrame - 4)*3;
						answer1 += (total1 - onFrame) * 4;
					}

					//plan2
					total2 = N - total / 2 -1;
					onFrame = frame(R,C)/2;
					if (total2 <= onFrame){
						answer2 += total2 * 3;
					}
					else{
						answer2 += onFrame * 3;
						answer2 += ( ( total1 - onFrame) ) * 4;
					}
				}

				answer = min(answer1,answer2);
			}
		}
		cout << "Case " << "#" << n << ": " << answer << endl;

	}
	return 0;
}
