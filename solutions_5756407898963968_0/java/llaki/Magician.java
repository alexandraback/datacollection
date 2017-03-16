import java.util.*;
import java.io.*;

public class Magician {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int[][] a = new int[4][4];
		int[][] b = new int[4][4];
		PrintWriter pw = new PrintWriter(System.out);
		for(int i=1; i<=T; i++){
			int ans1 = sc.nextInt();
			for(int j=0; j<4; j++){
				for(int k=0; k<4; k++){
					a[j][k] = sc.nextInt();
				}
			}
			int ans2 = sc.nextInt();
			for(int j=0; j<4; j++){
				for(int k=0; k<4; k++){
					b[j][k] = sc.nextInt();
				}
			}
			boolean[] canBe = new boolean[17];
			for(int j=0; j<4; j++){
				canBe[a[ans1-1][j]] = true;
			}
			ArrayList<Integer> found = new ArrayList<Integer>();
			for(int j=0; j<4; j++){
				int cur = b[ans2-1][j];
				if(!canBe[cur]) continue;
				found.add(cur);
			}
			pw.print("Case #"+i+": ");
			if(found.size()==1){
				pw.println(found.get(0));
			}
			else if(found.size()==0){
				pw.println("Volunteer cheated!");
			}
			else{
				pw.println("Bad magician!");
			}
		}
		pw.flush();
		pw.close();
	}
}
