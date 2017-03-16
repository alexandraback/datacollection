/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.brycealcock.codejam.y2014.qr;

import com.brycealcock.codejam.Case;
import com.brycealcock.codejam.CodeJamBase;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author bryce
 */
public class ProblemA extends CodeJamBase {

    @Override
    protected Case readAndProcessCase(int caseNumber, BufferedReader br) throws IOException, NumberFormatException {
        Scanner s = new Scanner(br.readLine());
        int[] firstRow = new int[4];
        int[] secondRow = new int[4];
        int row1 = s.nextInt();
        for(int i=1;i<5;++i){
            if(i==row1){
                s = new Scanner(br.readLine());
                firstRow[0]=s.nextInt();
                firstRow[1]=s.nextInt();
                firstRow[2]=s.nextInt();
                firstRow[3]=s.nextInt();
            }
            else{
                br.readLine();
            }
        }
        s= new Scanner(br.readLine());
        int row2 = s.nextInt();
        for(int i=1;i<5;++i){
            if(i==row2){
                s = new Scanner(br.readLine());
                secondRow[0]=s.nextInt();
                secondRow[1]=s.nextInt();
                secondRow[2]=s.nextInt();
                secondRow[3]=s.nextInt();
            }else{
                br.readLine();
            }
        }
        System.out.println(row1+":"+firstRow+":"+row2+":"+secondRow);
        return new PCase(caseNumber,firstRow,secondRow);
        
    }
    
    class PCase extends Case{
        int[] firstRow;
        int[] secondRow;
        PCase (int caseNumber, int[] f, int[] s){
            super(caseNumber);
            firstRow=f;
            secondRow=s;
        }
        String result ;
        

        @Override
        protected String caseResult() {
            return result;
        }

        @Override
        protected Case processCase() {
            List<Integer> results = new ArrayList<Integer>();
            for (int i:firstRow) {
                for(int j:secondRow){
                    if(i==j){
                        results.add(j);
                    }
                }
            }
            if(results.isEmpty()){
                result = "Volunteer cheated!";
            }else if(results.size()>1){
                result = "Bad magician!";
            }else{
                result = String.valueOf(results.get(0));
            }
            return this;
        }
    }
}
