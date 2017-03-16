package main;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
    
    public static final String changeLine = System.getProperty("line.separator");
    
    public static void main(String[] args) throws FileNotFoundException, IOException{
        Main main = new Main();
    }

    public int n,l;
    public String [] ori;
    public char [] check;
    public int [][] data;
    
    public Main() throws FileNotFoundException, IOException{
        BufferedReader br = new BufferedReader(new FileReader("D:/A-large.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
        int cases = Integer.parseInt(br.readLine());
        for (int caseNum = 0; caseNum < cases; caseNum++) {
            System.out.println("Case #"+(caseNum+1)+":");
            n = Integer.parseInt(br.readLine());
            ori = new String[n];
            check = new char[105];
            for (int i = 0; i < n; i++) {
                ori[i] = br.readLine();
            }
            l = 0;
            check[0] = ori[0].charAt(0);
            for (int i = 1; i < ori[0].length(); i++) {
                if (ori[0].charAt(i) != check[l]) {
                    check[++l] = ori[0].charAt(i);
                }
            }
            l++;
            boolean possible = true;
            data = new int [n][l];
            for (int i = 0; i < n; i++) {
                int flag = 0;
                int count = 0;
                for (int j = 0; j < ori[i].length(); j++) {
                    if (ori[i].charAt(j) != check[flag]) {
                        if (flag+1 >= l || ori[i].charAt(j) != check[flag+1]) {
                            possible = false;
                            break;
                        } else {
                            if (count == 0) {
                                possible = false;
                                break;
                            }
                            data[i][flag++] = count;
                            count = 1;
                        }
                    } else {
                        count ++;
                    }
                }
                data[i][flag] = count;
                if (flag != l-1) {
                    possible = false;
                }
                if (!possible) {
                    break;
                }
            }
            // output
            bw.write("Case #"+(caseNum+1)+": ");
            if (possible) {
                int result = 0;
                for (int i = 0; i < l; i++) {
                    int [] temp = new int [n];
                    for (int j = 0; j < n; j++) {
                        temp [j] = data[j][i];
                    }
                    Arrays.sort(temp);
                    int target = temp[n/2];
                    for (int j = 0; j < n; j++) {
                        result += Math.abs(data[j][i]-target);
                    }
                }
                bw.write(Integer.toString(result));
//                for (int i = 0; i < n; i++) {
//                    for (int j = 0; j < l; j++) {
//                        System.out.print(data[i][j]+" ");
//                    }
//                    System.out.print("\n");
//                }
            } else {
                bw.write("Fegla Won");
            }
            bw.write(changeLine);
        }
        br.close();
        bw.close();
    }
}