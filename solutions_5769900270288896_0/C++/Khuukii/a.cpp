
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

bool parz(int x) { return x%2==0; }

int max(int a, int b) {
	return (a-1)*b + (b-1)*a;
}

int main() {
	
	int T;
	cin >> T;
	for(int caseNr=1; caseNr<=T; caseNr++) {
		
		int score = 0;
		
		
		int wys, szer, lok;
		cin >> wys >> szer >> lok;
		
		if((szer*wys < 2) || (szer*wys + 1) / 2 >= lok) {
			score = 0;
		}
		else {
			if(wys==1){
				if(parz(szer)) 	score = (lok - (szer/2))*2 - 1;
				else 			score = (lok - ((szer/2)+1))*2;
			}
			else if (szer==1) {
				if(parz(wys)) 	score = (lok - (wys/2))*2 - 1;
				else 			score = (lok - ((wys/2)+1))*2;
			}
			else if(parz(wys) || parz(szer)) {
				lok -= (szer*wys)/2;
				
				score += 2;
				lok--;
				if(lok > 0) {
					score+=2;
					lok--;
					
					for(int i=0; i< wys-2; i++) {
						if(lok>0) {
							lok--;
							score+=3;
						}
						else break;
					}
					if(lok>0) {
						for(int i=0; i< szer-2; i++) {
							if(lok>0) {
								lok--;
								score+=3;
							}
							else break;
						}
						while(lok>0) {
							score+=4;
							lok--;
						}
					}
				}
			}
			else {
				score=0;
				if(lok >= (szer*wys) - ((szer/2)*(wys/2)+((szer/2)-1) * ((wys/2)-1))) {
					score = max(wys, szer);
					int maxLok = szer*wys;
					while(maxLok > lok) {
						score-=4;
						maxLok--;
					}
				}
				else {
					int score1 = 0;
					int lok1 = lok - (szer*wys)/2;
					int counter1 =0;
					while(lok1>0) {
						if(counter1++ < 4) score1 +=2;
						else score1+=3;
						lok1--;
					}
					
					int score2=0;
					int lok2 = lok - (szer*wys)/2 - 1;
					while(lok2>0) {
						score2+=3;
						lok2--;
					}
					if(score1 < score2) score = score1;
					else score = score2;
				}
			}
		}
		
		
		cout << "Case #" << caseNr << ": " << score << endl;
	}
	
	return 0;
}
