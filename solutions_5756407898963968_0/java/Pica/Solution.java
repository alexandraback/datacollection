import java.util.*;
import java.io.*;
import java.math.*;


// Author: vt12
// Google Code Jam 2010


public class Solution {
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
                        int ans = 0;
			
                        int firstR = sc.nextInt(); firstR --;
                        int[][] a = new int[4][4];
                        for (int i = 0; i < 4; i++) {
                            for (int j = 0; j < 4; j++) 
                            {
                                a[i][j] = sc.nextInt();                            
                            }
                        }
                        int secondR = sc.nextInt(); secondR --;
                        int[][] b = new int[4][4];
                        for (int i = 0; i < 4; i++) {
                            for (int j = 0; j < 4; j++) 
                            {
                                b[i][j] = sc.nextInt();                            
                            }
                        }
                        
                        int cnt = 0;
                        for (int j = 0; j < 4; j++) {
                            for (int k = 0; k < 4; k++) {
                                if (a[firstR][j] == b[secondR][k]){
                                    cnt++;
                                    ans = a[firstR][j];
                                }
                            }
                        }
    
                        
			pw.print("Case #" + caseNum + ": " );                       
                     
                        switch (cnt) {
                            case 0: pw.println("Volunteer cheated!"); break;
                            case 1: pw.println(ans); break;
                            case 2: pw.println("Bad magician!"); break;
                            case 3: pw.println("Bad magician!"); break;
                            case 4: pw.println("Bad magician!"); break;                            
                        }
			
			System.out.println("Finished testcase " + caseNum + ", time = " + (System.currentTimeMillis() - time));
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).doMain();
	}
}