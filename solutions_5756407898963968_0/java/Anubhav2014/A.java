package qualification2014;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int A1,A2;
		int[][] grid1 = new int[4][4];
		int[][] grid2 = new int[4][4];
		for (int i = 1; i <=T ; i++) {
			A1 = sc.nextInt();
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					grid1[j][k] = sc.nextInt();
				}
			}
			A2 = sc.nextInt();
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					grid2[j][k] = sc.nextInt();
				}
			}
			
			ArrayList<Integer> row1 = new ArrayList<Integer>();
			ArrayList<Integer> row2 = new ArrayList<Integer>();
			for (int j = 0; j < 4; j++) {
				row1.add(grid1[A1-1][j]);
				row2.add(grid2[A2-1][j]);
			}
			int chosenNo=0;
			int foundCount = 0;
			for (int j = 0; j < 4; j++) {
				if(row2.contains(row1.get(j))){
					chosenNo = row1.get(j);
					foundCount++;
			}
			
		}
			System.out.print("Case #"+i+": ");
			if(foundCount>1)
				System.out.println("Bad magician!");
			else
				if(chosenNo==0)
					System.out.println("Volunteer cheated!");
				else
					System.out.println(chosenNo);
		}

	}

	public static String getPos(int A1,int A2){
		String no = null;
		if(A1==1&&A2==1)
			no = "00";
		if(A1==1&&A2==2)
			no = "01";
		if(A1==1&&A2==3)
			no = "02";
		if(A1==1&&A2==4)
			no = "03";
		
		if(A1==2&&A2==1)
			no = "13";
		if(A1==2&&A2==2)
			no = "10";
		if(A1==2&&A2==3)
			no = "11";
		if(A1==2&&A2==4)
			no = "12";
		
		if(A1==3&&A2==1)
			no = "22";
		if(A1==3&&A2==2)
			no = "23";
		if(A1==3&&A2==3)
			no = "20";
		if(A1==3&&A2==4)
			no = "21";
		
		if(A1==4&&A2==1)
			no = "31";
		if(A1==4&&A2==2)
			no = "32";
		if(A1==4&&A2==3)
			no = "33";
		if(A1==4&&A2==4)
			no = "30";
		
		return no;
	}
	
	
}
