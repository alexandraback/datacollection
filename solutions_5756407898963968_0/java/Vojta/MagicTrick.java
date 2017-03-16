/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Bc. Vojtech Kral, student of FIT at CTU in Prague
 */
public class MagicTrick {
    
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        File f = new File(Helper.inputFolder + "A-small-attempt0.in");
        
        Scanner sc = new Scanner(f);
        
        int numberOftestcases = Integer.parseInt(sc.nextLine());
        StringBuilder sb = new StringBuilder();
        
        for (int i = 1; i <= numberOftestcases; i++) {
            int rowFirstSay = Integer.parseInt(sc.nextLine());
            List<Integer> loadRowFirst = loadRow(rowFirstSay, sc);
            
            int rowSecondSay = Integer.parseInt(sc.nextLine());
            List<Integer> loadRowSecond = loadRow(rowSecondSay, sc);
            
            int numberOfSameNumbers = numberOfSameNumbers(loadRowFirst, loadRowSecond);
            
            sb.append("Case #").append(i).append(":").append(" ");
            switch (numberOfSameNumbers){
                case 0: sb.append("Volunteer cheated!");
                    break;
                case 1: sb.append(intersection(loadRowFirst, loadRowSecond));
                    break;
                default:
                    sb.append("Bad magician!");
                    break;
                    
            }
            sb.append(System.getProperty("line.separator"));
            
            
            
            
        }
        
        Helper.write(sb, MagicTrick.class.getName() + ".txt");
        
                
    }
    
    private static Integer intersection(List<Integer> list1, List<Integer> list2){
        int sameNumbers = 0;
        
        for (Integer integer : list1) {
            for (Integer integer1 : list2) {
                if ( integer.equals(integer1) ){
                    return integer;
                }
            }
        }
        
        throw new RuntimeException("No intersection");
    }
    
    private static int numberOfSameNumbers(List<Integer> list1, List<Integer> list2){
        int sameNumbers = 0;
        
        for (Integer integer : list1) {
            for (Integer integer1 : list2) {
                if ( integer.equals(integer1) ){
                    sameNumbers++;
                }
            }
        }
        
        return sameNumbers;
    }
    
    private static List<Integer> loadRow(int rowNumber, Scanner sc){
        for (int i = 1; i < rowNumber; i++) {
            sc.nextLine();
        }
        
        
        List<Integer> list = new ArrayList<Integer>();
        String[] numbers = sc.nextLine().split(" ");
        for (String string : numbers) {
            list.add(Integer.parseInt(string));
        }
        
        //Roll the other lines
        for (int i = rowNumber; i < 4; i++) {
            sc.nextLine();
        }
        
        return list;
        
        
        
    }
}
