#include "main.h"

//Apologies for the poor code structure quality

int main(int argc, char* argv[]){
	if (argc < 2)
		cout << "Don't forget to pass the name of the input file (with extension) as a parameter!" << endl;

	string filename = argv[1];
	vector<input> inputs;

	readInputs(filename, inputs);
	writeSolution(inputs);
	return 0;
}

string solve(input &inElem){
	stringstream ss;

	vector<int> firstRow = inElem.firstMatrix[inElem.firstAnswer-1];
	vector<int> secondRow = inElem.secondMatrix[inElem.secondAnswer - 1];

	vector<int> commonElems;
	bool common;
	for (unsigned int i = 0; i < firstRow.size(); i++){
		common = false;
		for (unsigned int j = 0; j < secondRow.size() && !common; j++)
			if (firstRow[i] == secondRow[j])
				common = true;

		if (common)
			commonElems.push_back(firstRow[i]);
	}

	if (commonElems.size() == 1)
		ss << commonElems[0];
	else if (commonElems.size() > 1)
		ss << "Bad magician!";
	else
		ss << "Volunteer cheated!";
	return ss.str();
}

void writeSolution(vector<input> &inputs){
	fstream ofile("test.ou", fstream::out);

	for (unsigned int i = 0; i < inputs.size(); i++){
		ofile << "Case #" << i+1 << ": " << solve(inputs[i]) << endl;
	}

	ofile.close();
}

void readInputs(string inputfile, vector<input> &inputs){
	fstream ifile(inputfile, fstream::in);
	if (!ifile.is_open()){
		cout << "Could not open file " << inputfile << "." << endl;
		exit(-1);
	}

	string line = "";
	do{
		getline(ifile, line);
	} while (line.length() <= 0);

	int numInputs = atoi(line.c_str());

	while (numInputs > 0){
		numInputs--;
		input curIn;
		curIn.firstMatrix.resize(4);
		curIn.secondMatrix.resize(4);
		for (int i = 0; i < 4; i++){
			curIn.firstMatrix[i].resize(4);
			curIn.secondMatrix[i].resize(4);
		}

		getline(ifile, line);
		curIn.firstAnswer = atoi(line.c_str());

		getline(ifile, line);
		stringstream m1_ss(line);
		m1_ss >> curIn.firstMatrix[0][0]; m1_ss >> curIn.firstMatrix[0][1]; m1_ss >> curIn.firstMatrix[0][2]; m1_ss >> curIn.firstMatrix[0][3];
		getline(ifile, line); m1_ss.clear();  m1_ss.str(line);
		m1_ss >> curIn.firstMatrix[1][0]; m1_ss >> curIn.firstMatrix[1][1]; m1_ss >> curIn.firstMatrix[1][2]; m1_ss >> curIn.firstMatrix[1][3];
		getline(ifile, line); m1_ss.clear(); m1_ss.str(line);
		m1_ss >> curIn.firstMatrix[2][0]; m1_ss >> curIn.firstMatrix[2][1]; m1_ss >> curIn.firstMatrix[2][2]; m1_ss >> curIn.firstMatrix[2][3];
		getline(ifile, line); m1_ss.clear(); m1_ss.str(line);
		m1_ss >> curIn.firstMatrix[3][0]; m1_ss >> curIn.firstMatrix[3][1]; m1_ss >> curIn.firstMatrix[3][2]; m1_ss >> curIn.firstMatrix[3][3];

		getline(ifile, line);
		curIn.secondAnswer = atoi(line.c_str());

		getline(ifile, line); m1_ss.clear(); m1_ss.str(line);
		m1_ss >> curIn.secondMatrix[0][0]; m1_ss >> curIn.secondMatrix[0][1]; m1_ss >> curIn.secondMatrix[0][2]; m1_ss >> curIn.secondMatrix[0][3];
		getline(ifile, line); m1_ss.clear(); m1_ss.str(line);
		m1_ss >> curIn.secondMatrix[1][0]; m1_ss >> curIn.secondMatrix[1][1]; m1_ss >> curIn.secondMatrix[1][2]; m1_ss >> curIn.secondMatrix[1][3];
		getline(ifile, line); m1_ss.clear(); m1_ss.str(line);
		m1_ss >> curIn.secondMatrix[2][0]; m1_ss >> curIn.secondMatrix[2][1]; m1_ss >> curIn.secondMatrix[2][2]; m1_ss >> curIn.secondMatrix[2][3];
		getline(ifile, line); m1_ss.clear(); m1_ss.str(line);
		m1_ss >> curIn.secondMatrix[3][0]; m1_ss >> curIn.secondMatrix[3][1]; m1_ss >> curIn.secondMatrix[3][2]; m1_ss >> curIn.secondMatrix[3][3];

		inputs.push_back(curIn);
	}

	ifile.close();
}