#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
//#include<cmath>
//#include<gmpxx.h>

struct case_data{
	int grid[2][4][4];
	int row[2];
};

std::vector<case_data> cases;

void parse_input(std::istream& input){
	int cases_n; input>>cases_n; cases.resize(cases_n);
	for(auto& c:cases){
		input>>c.row[0];c.row[0]--;
		for(int i=0;i<4;i++)for(int j=0;j<4;j++)input>>c.grid[0][i][j];
		input>>c.row[1];c.row[1]--;
		for(int i=0;i<4;i++)for(int j=0;j<4;j++)input>>c.grid[1][i][j];
	}
}

std::string solve_case(const case_data& c){
	int n=0; char r[3];
	for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(c.grid[0][c.row[0]][i]==c.grid[1][c.row[1]][j]){n++;sprintf(r,"%d",c.grid[1][c.row[1]][j]);}
	if(n>1) return "Bad magician!";
	if(n<1) return "Volunteer cheated!";
	return r;
}

int main(){
	parse_input(std::cin);
	for(int i=0;i<cases.size();i++){
		std::cout<<"Case #"<<i+1<<": "<<solve_case(cases[i])<<std::endl;
	}

	return 0;
}
