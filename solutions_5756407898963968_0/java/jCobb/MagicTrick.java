/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam2014;

import InputOutput.IOHandle;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author kando
 */
public class MagicTrick {
    
    private int numberOfCases;
    private List<int[]> grid;
    private int row1Index;
    private int row2Index;
    private int[] row1;
    private int[] row2;
    
    public MagicTrick(){
        IOHandle ioh = new IOHandle("input.in","output.out");
        
        grid = new ArrayList<int[]>();
        
        numberOfCases = Integer.parseInt(ioh.getLine());
        
        for(int i=0;i<numberOfCases;i++){
            
            row1Index = Integer.parseInt(ioh.getLine())-1;
            parseGrid(ioh);
            row1 = grid.get(row1Index);
            
            row2Index = Integer.parseInt(ioh.getLine())-1;
            parseGrid(ioh);
            row2 = grid.get(row2Index);
            
            ioh.addLine("Case #"+(i+1)+": "+result(compareRows(row1,row2)));
            
        }
        
        ioh.flush();
        
    }
    
    private String result(int i) {
        if(i > 0)
            return i+"";
        else if(i==-1)
            return "Volunteer cheated!";
        else
            return "Bad magician!";
    }
    
    private void parseGrid(IOHandle io) {
        grid.clear();
        
        for(int i=0;i<4;i++) {
            grid.add(io.getLineNumbers());
        }
        
    }
    
    /**
     * 
     * @param first
     * @param second
     * @return positive integer as result, -1 no match found, -2 more matches found 
     */
    private int compareRows(int[] first, int[] second) {
        int result = -1;
        for(int i=0;i<first.length;i++) {
            for(int k=0;k<second.length;k++) {
                if(first[i] == second[k]){
                    if(result != -1)
                        return -2;
                    else
                        result = first[i];
                }
            }
        }
        
        return (result==-1)?-1:result;
    }
}
