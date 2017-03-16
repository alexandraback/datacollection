#include <cstdio> //Reading input, printing output
#include <iostream> //Reading input, printing output
#include <math.h> //Ceil

#define DEBUG false

using namespace std;

bool** createComplex(int rows, int cols){
    bool** out = new bool*[rows];
    for(int row = 0; row < rows; row++){
        out[row] = new bool[cols];
    }
    
    return out;
}

void destroyComplex(int rows, bool** complex){
    for(int row = 0; row < rows; row++){
        delete[] complex[row];
    }
    
    delete[] complex;
}

int calculateUnhappiness(bool** complex, int rows, int cols){
    /*
     * In order to avoid double-counting, we're going to check in a
     * checkerboard pattern.
     */
    int unhappiness = 0;
    for(int row = 0; row < rows; row++){
        for(int col = (row+1)%2; col < cols; col+=2){
            //Check above
            if(row > 0 && complex[row-1][col] && complex[row][col]){
                unhappiness++;
            }
            
            //Check below
            if(row < rows-1 && complex[row+1][col] && complex[row][col]){
                unhappiness++;
            }
            
            //Check left
            if(col > 0 && complex[row][col-1] && complex[row][col]){
                unhappiness++;
            }
            
            //Check right
            if(col < cols - 1 && complex[row][col+1] && complex[row][col]){
                unhappiness++;
            }
        }
    } //unhappiness is computed
    
    return unhappiness;
}

/*
 * Determines what the next gap configuration should be.
 * 
 * Returns true if there is a next gap config, false if all done.
 */
bool nextGap(int* gapIndices, int gaps, int rows, int cols){
    int totalSize = rows*cols;
    bool* gapArray = new bool[totalSize]; //stretch apt. complex into one row
    
    for(int i = 0; i < totalSize; i++){
        gapArray[i] = false;
    }
    for(int gap = 0; gap < gaps; gap++){
        gapArray[gapIndices[gap]] = true;
    }
    
    //Find and move the leftmost gap possible one to the right.
    //Reset all counters to its left.
    int countersToReset = 0;
    bool moved = false;
    int finalIndex;
    //can never move last piece one right
    for(finalIndex = 0; finalIndex < totalSize-1; finalIndex++){
        if(gapArray[finalIndex] && !gapArray[finalIndex+1]){
            //Move counter right.
            gapArray[finalIndex+1] = true;
            gapArray[finalIndex] = false;
            
            //We're done searching.
            moved = true;
            break;
            
        } else if(gapArray[finalIndex]){ 
            //There's a piece here but we can't move it.
            countersToReset++;
        }
    }
    
    if(DEBUG) cout << countersToReset << endl;
    
    //If we couldn't move any pieces, we're done.
    if(!moved){
        delete[] gapArray;
        return false;
    }
    
    //Reset the other pieces
    for(int i = 0; i < finalIndex; i++){
        gapArray[i] = i < countersToReset;
    }
    
    //Copy the indices.
    int gap = 0;
    if(DEBUG) cout << "Gaps: ";
    for(int i = 0; i < totalSize; i++){
        if(gapArray[i]){
            gapIndices[gap++] = i;
            if(DEBUG) cout << i << " ";
        }
    }
    if(DEBUG) cout << endl;
    
    return true;
}

void fillComplex(bool** complex, int* gapIndices, int gaps,
                 int rows, int cols)
{
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            complex[row][col] = true; //fill with people, then put in gaps.
        }
    }
    
    int row, col;
    for(int i = 0; i < gaps; i++){
        row = (int) (gapIndices[i]/cols);
        col = (gapIndices[i])%cols;
        if(DEBUG) cout << "Putting gap " << gapIndices[i] << " at " << row << ", " << col << endl;
        
        complex[row][col] = false;
    }
}

void printComplex(bool** complex, int rows, int cols){
    cout << endl;
    for(int row = 0; row < rows; row++){
        for(int col = 0; col < cols; col++){
            cout << complex[row][col]? "x " : "  ";
        }
        cout << endl;
    }
}

/*
 * Computes and returns the minimum unhappiness of a complex.
 */
int minimizeUnhappiness(int rows, int cols, int tenants){
    //Can checkerboard tenants if this condition is satisified.
    if((int) ceil(rows*cols/2) >= tenants){
        return 0;
    }
    
    //Otherwise, we actually need to figure it out. Here we're brute forcing.
    bool** complex = createComplex(rows, cols);
    
    int gapsToLeave = rows*cols - tenants;
    
    int* gapIndices = new int[gapsToLeave];
    for(int i = 0; i < gapsToLeave; i++){
        gapIndices[i] = i;
    }
    bool triedAny = false;
    
    int minUnhappiness = rows*cols*2; //overestimate.
    int unhappiness;
    //This condition changes gapIndices and returns whether it was updated
    while(!triedAny || nextGap(gapIndices, gapsToLeave, rows, cols)){
        triedAny = true;
        fillComplex(complex, gapIndices, gapsToLeave, rows, cols);
        if(DEBUG) printComplex(complex, rows, cols);
        
        unhappiness = calculateUnhappiness(complex, rows, cols);
        if(unhappiness < minUnhappiness){
            minUnhappiness = unhappiness;
        }
    }
    
    destroyComplex(rows, complex);
    
    return minUnhappiness;
}

/*
 * To run: run as apt_small < input_file > output_file
 * 
 * Brute forces the unhappiness for an apartment.
 */
int main(){
    int nCases;
    cin >> nCases;
    
    int rows, cols, tenants;
    int unhappiness;
    for(int i = 0; i < nCases; i++){
        cin >> rows;
        cin >> cols;
        cin >> tenants;
        
        unhappiness = minimizeUnhappiness(rows, cols, tenants);
        
        cout << "Case #" << (i+1) << ": " << unhappiness << endl;
    }
    
    return 0;
}