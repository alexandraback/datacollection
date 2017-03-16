#include <iostream>
using namespace std;




void readAnswerGrid(int &card, int (&grid) [16]){
	cin >> card;
	for(int i=0;i<16;i++)
		cin >> grid[i];
}

void printAnswerGrid(int card, int grid []){
	cout << card << endl;
	for(int i=0;i<16;i++)
	{
		cout << grid[i] << " " ;
		if(i%4==0 && i!=0)
		cout << endl;		
	}
	cout << endl;
}

void solveCase(int caseNum){

	int cardA,cardB;
	int gridA[16], gridB[16];

	readAnswerGrid(cardA,gridA);
	readAnswerGrid(cardB,gridB);

	int occurences = 0;
	int magic = -1;

	for(int a=0; a<4;a++){
		for(int b=0; b<4;b++){

			if(gridA[(cardA-1)*4+a] == gridB[(cardB-1)*4+b]){
				occurences++;
				magic = gridA[(cardA-1)*4+a];
			}
		}
	}

	if(occurences == 1)
	{
		cout << "Case #"<<caseNum << ": " << magic << endl;
	}
	else if(occurences == 0){
		cout << "Case #"<<caseNum << ": Volunteer cheated!" << endl;
	}
	else
	{
		cout << "Case #"<<caseNum << ": Bad magician!" << endl;
	}
}

int main(){
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		solveCase(i+1);
	}	
	return 0;
}