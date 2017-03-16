#include <iostream> 
#include <fstream> 
#include <vector>

using namespace std;

double roundup(double n){
	return n / 10 ;
}

double calculateA(vector<double> plates, int m){
	double qty = 0;
	
	for(int i = 0; i < m - 1; i++)
		if(plates[i] > plates[i + 1])
			qty += plates[i] - plates[i + 1];
	
	return qty;
}

double calculateB(vector<double> plates, int m){
	double qty = 0;
	double rate = 0;
	
	for(int i = 0; i < m - 1; i++){
		//cout << rate << " ";
		if(plates[i] > plates[i + 1] && rate < roundup(plates[i] - plates[i + 1]))
			rate = roundup(plates[i] - plates[i + 1]);
	}
	//cout << rate << "\n";
	
	for(int i = 0; i < m - 1; i++)
		if(rate * 10 < plates[i])
			qty += rate * 10;
		else
			qty += plates[i];
	
	return qty;
}

int main() {	
	ifstream input("A-large.in");
	ofstream output("output.ou");

	int sets, n;
	
	if(input.is_open()){
		input >> sets;
		n = 1;
		
		while(sets > 0){
		
			int temp;
			int m;
			vector<double> plates;
		
			input >> m;
			for(int i = 0; i < m; i++){
				input >> temp;
				plates.push_back(temp);
			}
			
			output << "Case #" << n << ": " << calculateA(plates, m) << " " << calculateB(plates, m) << "\n";
			
		
		
			sets--;
			n++;
		}
		
		input.close();
		output.close();
	}
	
	return 0; 
}
