import java.util.ArrayList;
import java.util.Scanner;


public class magic {
	public static void main(String[] args){
		Scanner f = new Scanner(System.in);
		int n = i(f.nextLine());
		for(int i = 0; i < n; i++){
			int r = i(f.nextLine());
			int[][] grid = new int[4][4];
			for(int j = 0; j < 4; j++){
				String[] cur = f.nextLine().split(" ");
				for(int k = 0; k < 4; k++){
					grid[j][k] = i(cur[k]);
				}
			}
			int[] temps = new int[4];
			temps = grid[--r];
			r = i(f.nextLine());
			int[][] gd = new int[4][4];
			for(int j = 0; j < 4; j++){
				String[] cur = f.nextLine().split(" ");
				for(int k = 0; k < 4; k++){
					gd[j][k] = i(cur[k]);
				}
			}
			ArrayList<Integer> a = new ArrayList<Integer>();
			for(int j = 0; j < 4; j++){
				int y = temps[j];
				for(int k = 0; k < 4; k++){
					if(gd[r - 1][k] == y){
						a.add(y);
					}
				}
			}
			if(a.size() == 1){
				System.out.println("Case #" + (i + 1) + ": " + a.get(0));
			}else if(a.size() == 0){
				System.out.println("Case #" + (i + 1) + ": Volunteer cheated!");
			}else{
				System.out.println("Case #" + (i + 1) + ": Bad magician!");
			}
		}
	}
	public static int i(String s){ return Integer.parseInt(s);}
}
