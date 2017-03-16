#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

int main(int argc, const char * argv[])
{
    std::ifstream infile("/Users/evan/Git/GoogleCodeJam/Qualification/Problem A/QualProblemA/QualProblemA/A-small-attempt0.in");
    std::ofstream outfile;
    outfile.open("/Users/evan/Git/GoogleCodeJam/Qualification/Problem A/QualProblemA/QualProblemA/small.out");
    
    
    int T; //number of test cases
    infile >> T;
    
    for (int tcase = 1; tcase<=T; tcase++) {
        int firstRow;
        int secondRow;
        int firstGrid[4][4];
        int secondGrid[4][4];
        
        infile >> firstRow;
        for (int row = 0; row < 4; row++) {
            infile >> firstGrid[row][0] >> firstGrid[row][1] >> firstGrid[row][2]
            >> firstGrid[row][3];
        }
        infile >> secondRow;
        for (int row = 0; row < 4; row++) {
            infile >> secondGrid[row][0] >> secondGrid[row][1] >> secondGrid[row][2]
            >> secondGrid[row][3];
        }
        
        firstRow--;
        secondRow--;
        
        std::vector<int> v(8);
        std::vector<int>::iterator it;
        
        std::sort (firstGrid[firstRow],firstGrid[firstRow]+4);
        std::sort (secondGrid[secondRow],secondGrid[secondRow]+4);
        
        it=std::set_intersection (firstGrid[firstRow], firstGrid[firstRow]+4, secondGrid[secondRow], secondGrid[secondRow]+4, v.begin());
        v.resize(it-v.begin());
        
        size_t matches = v.size();
        
        outfile << "Case #" << tcase << ": ";
        if (matches == 1) {
            outfile << v[0];
        } else if (matches > 1) {
            outfile << "Bad magician!";
        } else {
            outfile << "Volunteer cheated!";
        }
        outfile << '\n';
    }
    outfile.close();
    return 0;
}

