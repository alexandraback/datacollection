/* 
 * File:   main.cpp
 * Author: mehmetfatihuslu
 *
 * Created on April 12, 2014, 4:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int kartlar1[4][4];
int kartlar2[4][4];

int temp1[4];
int temp2[4];

int main(int argc, char** argv) {

    fstream inputFile, outputFile, logFile;
    int T = 3;
    int sec1,sec2;
    
    inputFile.open("input",ios::in);
    outputFile.open("output",ios::out);
    logFile.open("log",ios::out);
    
    inputFile >> T;    
    
    for(int dongu=1; dongu<=T; dongu++) {
        
        inputFile >> sec1;                    	

        for(int i=0; i<4; i++){
            
            for(int j=0; j<4; j++){
            
                inputFile >> kartlar1[i][j];
            }
        }
            
                         

        inputFile >> sec2;
        
        for(int i=0; i<4; i++){
        
            for(int j=0; j<4; j++){
            
                inputFile >> kartlar2[i][j];
            }                
        }
        
        //outputFile<<sec1<<" "<<sec2<<" "<<kartlar1[1][2]<<" "<<kartlar2[2][1]<<endl;
        
        for(int i=0;i<4;i++){
            
            temp1[i] = kartlar1[sec1-1][i];
            temp2[i] = kartlar2[sec2-1][i];
        }
        
        int cakis = 0;
        int sira = 0;
        
        for(int i=0; i<4; i++){
        
            for(int j=0; j<4; j++){
         
                if(temp1[i]==temp2[j]){
                    
                    cakis++;
                    sira = temp1[i];
                }
            }
        }
        
        if(cakis==0){
        
            outputFile << "Case #" <<dongu <<": Volunteer cheated!";
        }
        else if(cakis>1){
        
            outputFile << "Case #" <<dongu <<": Bad magician!";
        }
        else{
            
            outputFile << "Case #" <<dongu <<": "<<sira;
        }        
        
        outputFile << endl;
    }
    
    return 0;
}

