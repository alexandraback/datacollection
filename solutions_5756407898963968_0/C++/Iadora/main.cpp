#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char** argv){

	if(argc<2){

		return -1;
	}
	
	ifstream fichier_input(argv[1], ios::in);
	ofstream fichier_output("output", ios::out);

	if(!fichier_input){

		cout << "ERROR : incorrect input"<<endl;
		return -1;
	}

	int n_test;

	fichier_input >> n_test;

	for(int round=1; round<=n_test; round++){

		int n_row;

		fichier_input >> n_row;
		for(int p=1; p<n_row; p++){

			int trash;
			fichier_input >> trash >> trash >> trash >> trash;
		}
		
		vector<int> row_1;
		cout << n_row <<endl;;
		int element;
	
		for(int p=0; p<4; p++){

			fichier_input >> element;
			row_1.push_back(element);
			cout << element << " ";
		}
		cout <<endl;
		for(int p=n_row; p<4; p++){

			int trash;
			fichier_input >> trash >> trash >> trash >> trash;
		}

		fichier_input >> n_row;
		for(int p=1; p<n_row; p++){

			int trash;
			fichier_input >> trash >> trash >> trash >> trash;
		}

		vector<int> result;
		cout <<n_row <<endl;
		for(int p=0; p<4; p++){

			fichier_input >> element;
			cout << element <<" ";
			for(int i=0; i<4;i++){

				if(row_1[i] == element){

					result.push_back(element);
				}
			}
		}
		for(int p=n_row; p<4; p++){

			int trash;
			fichier_input >> trash >> trash >> trash >> trash;
		}
		cout <<endl <<endl;

		fichier_output << "Case #" << round << ": ";
		if(result.size()==0){

			fichier_output << "Volunteer cheated!" <<endl;
		}
		else if(result.size() ==1){

			fichier_output << result[0] <<endl;
		}
		else{
			fichier_output << "Bad magician!" <<endl;
		}

	}

	fichier_output.close();
	fichier_input.close();
	
	return 0;		
}
