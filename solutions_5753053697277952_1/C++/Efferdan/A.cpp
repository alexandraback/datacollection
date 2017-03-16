#include <deque>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <eigen3/Eigen/Core>

int main(int argc, char**argv){


    if(argc != 2){
        std::cout << "Pass the filename" << std::endl;
        return 0;
    }

    std::string line;
    std::ifstream infile(argv[1]);

    std::getline(infile,line); // discard number of cases
    int case_ = 0;

    int N =0;

    while (std::getline(infile, line))  // this does the checking!
    {
        std::istringstream iss(line);
        iss >> N;
        Eigen::VectorXi senators(N);

        std::getline(infile,line);
        std::istringstream iss2(line);
        for(int i=0; i < N; ++i){
            int aux;
            iss2 >> aux;
            senators(i) = aux;
        }

        std::cout << "Case #" << ++case_ << ": ";

        int idx = 0;
        if(senators.sum() % 2 == 1){
            senators.maxCoeff(&idx);
            std::cout << char('A' + idx);
            senators(idx) -= 1;
        }

        while(senators.sum() != 0){
            senators.maxCoeff(&idx);
            std::cout << ' ' << char('A'+ idx);
            senators(idx) -=1;
            senators.maxCoeff(&idx);
            std::cout << char('A' + idx);
            senators(idx) -=1;
        }
        std::cout << std::endl;
    }



    return 0;
}
