package round2b;

import googleJam.Pair;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.TreeSet;

public class probB {

	
	public static void main(String...args) {
		Scanner reader = new Scanner(System.in);
		int caseCount = Integer.parseInt(reader.nextLine());
		
		for(int caseId = 1; caseId <= caseCount; caseId++) {
			
			int R = reader.nextInt();
			int C = reader.nextInt();
			int n = reader.nextInt();
			reader.nextLine();
			
			int maxWalls = ((R-1) * C) + ((C-1) * R);
			int minWall = 0;
			
			if(n == (R*C)) {
				minWall = maxWalls;	
			}
			else {
				
				List<int[][]> M = new ArrayList<int[][]>();
				M.add(new int[R][C]);
				
				for(int r = 0; r < R; r++) {
					for(int c = 0; c < C; c++) {
						
						
						List<int[][]> MNew = new ArrayList<int[][]>();
						for(int[][] m : M) {
							
							if(count(m, R, C) < n) {
								int[][] m2 = deepCopy(m);
								m2[r][c] = 1;
								MNew.add(m2);
							}
						}
						
						M.addAll(MNew);
					}
				}
				
				
				minWall = Integer.MAX_VALUE;
				for(int[][] m : M) {
					
					if(count(m, R, C) == n) {
						
						int w = walls(m, R, C);
						
						if(w < minWall) {
							minWall = w;
						}
					}
				}
				
				
			}
			
			System.out.println("Case #" + caseId + ": " + minWall);
		}
	}
	
	
	public static int walls(int[][] m, int R, int C) {
		int walls = 0;
		for(int r = 0; r < R; r++) {
			for(int c = 0; c < C; c++) {
				
				if(m[r][c] != 0) {
					if((r+1) < R && m[r+1][c] == 1) {
						walls += 1;
					}
					
					if((c+1) < C && m[r][c+1] == 1) {
						walls += 1;
					}
				}
			}
		}
		
		return walls;
	}
	
	public static int count(int[][] m, int R, int C) {
		int count = 0;
		for(int r = 0; r < R; r++) {
			for(int c = 0; c < C; c++) {
				
				count += (m[r][c] == 1) ? 1 : 0;
			}
		}
		
		return count;
	}
	
	public static int[][] deepCopy(int[][] m) {
	    
	    int[][] result = new int[m.length][];
	    for (int i = 0; i < m.length; i++) {
	    	
	        result[i] = m[i].clone();
	    }
	    return result;
	}
}
