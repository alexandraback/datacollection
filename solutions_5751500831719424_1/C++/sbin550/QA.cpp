#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char ** argv){

    int numberOfTest;
    int numberOfString;

    vector <char> characters;
    vector <string> strings;

    int array[100][100];

    string temp;
    int iTemp;

    ifstream inFile;
    ofstream outFile;

    inFile.open(argv[1]);
    outFile.open(argv[2]);

    inFile >> numberOfTest;

    for(int count = 0 ; numberOfTest > count ; count++){
	outFile << "Case #" << count+1 << ": ";
	inFile >> numberOfString;

	strings.clear();
	for(int sCount = 0 ; numberOfString > sCount ; sCount++){
	    inFile >> temp;
	    strings.push_back(temp);
	}

	characters.clear();
	characters.push_back(strings[0][0]);
	for(int cCount = 0 ; strings[0].size() > cCount ; cCount++){
	    if(characters.back() != strings[0][cCount]){
		characters.push_back(strings[0][cCount]);
	    }
	}

	bool flag = true;
	
	for(int sCount = 0 ; (numberOfString > sCount) && flag ; sCount++){
	    int idx	= 0;
	    for(int cCount = 0 ; (characters.size() > cCount) && flag ; cCount++){
		array[sCount][cCount]	= 0;
		
		while((strings[sCount][idx] == characters[cCount]) && (strings[sCount].length() > idx)){
		    idx++;
		    array[sCount][cCount]++;
		}
		if(0 == array[sCount][cCount]){
		    flag    = false;
		}
	    }
	    if(idx != strings[sCount].length()){
		cout << "here" << count<<endl;
		flag    = false;
	    }
	}

	int result = 0;

	if(flag){
	    for(int cCount = 0 ; (characters.size() > cCount); cCount++){
		int minValue	= 10000000;
		for(int target = 1 ; (101 > target); target++){
		    iTemp = 0;
		    for(int sCount = 0 ; (numberOfString > sCount); sCount++){
			iTemp	+= abs(target - array[sCount][cCount]);
		    }
		    minValue    = min(minValue, iTemp);
		}
		result	+= minValue;
	    }
	    outFile << result << endl;
	}else{
	    outFile << "Fegla Won" << endl;
	}

    }

    inFile.close();
    outFile.close();

    return EXIT_SUCCESS;
}



