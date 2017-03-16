#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char ** argv){

    int count;
    int rCount;
    int cCount;

    int numberOfTest;

    int firstAnswer;
    int secondAnswer;

    vector <int> answers;
    vector <int> answers2;

    int result;
    int result2;
    int temp;

    vector <int>::iterator it;

    ifstream inFile;
    ofstream outFile;

    inFile.open(argv[1]);
    outFile.open(argv[2]);

    inFile >> numberOfTest;

    for(count = 0 ; numberOfTest > count ; count++){
	answers.clear();
	answers2.clear();

	inFile >> firstAnswer;

	for(rCount = 0 ; 4 > rCount ; rCount++){
	    if(firstAnswer == (rCount+1)){
		for(cCount = 0 ; 4 > cCount ; cCount++){
		    inFile >> temp;
		    answers.push_back(temp);
		}
	    }else{
		for(cCount = 0 ; 4 > cCount ; cCount++){
		    inFile >> temp;
		}
	    }
	}
	inFile >> secondAnswer;
	for(rCount = 0 ; 4 > rCount ; rCount++){
	    if(secondAnswer == (rCount+1)){
		for(cCount = 0 ; 4 > cCount ; cCount++){
		    inFile >> temp;
		    answers2.push_back(temp);
		}
	    }else{
		for(cCount = 0 ; 4 > cCount ; cCount++){
		    inFile >> temp;
		}
	    }
	}
	result = 0;
	result2 = 0;
	for(cCount = 0 ; 4 > cCount ; cCount++){
	    it = find(answers2.begin(), answers2.end(), answers[cCount]);
	    if(it != answers2.end()){
		result++;
		result2	= answers[cCount];
	    }
	}

	outFile << "Case #" << count+1 << ": ";
	switch(result){
	    case 0 :
		outFile << "Volunteer cheated!" << endl;
		break;
	    case 1 :
		outFile << result2 << endl;
		break;
	    default :
		outFile << "Bad magician!" << endl;
	}
    }

    inFile.close();
    outFile.close();

    return EXIT_SUCCESS;
}



