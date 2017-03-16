import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class TaskA {
	public static void main(String[] args) throws FileNotFoundException {
		new TaskA().solve();
	}

	private void solve() throws FileNotFoundException {
		int [][] a = new int[4][4];
		int [][] b = new int[4][4];

		Scanner in = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter("taskA.out");
		int testCase = in.nextInt();
		for (int ii = 0;ii<testCase;++ii){
			int rowA = in.nextInt();
			for (int i = 0;i<4;++i){
				for (int j = 0;j<4;++j){
					a[i][j] = in.nextInt();
					
				}
			}
			
			int rowB = in.nextInt();
			for (int i = 0;i<4;++i){
				for (int j = 0;j<4;++j){
					b[i][j] = in.nextInt();
				}
			}
			
			List<Integer> ansList = new ArrayList<Integer>();
			
			for (int i = 0;i<4;++i){
				for (int j = 0;j<4;++j){
					if (a[rowA-1][i] == b[rowB-1][j]){
						ansList.add(a[rowA-1][i]);
					}
				}
			}
			
			out.printf("Case #%d: ",ii+1);
			if (ansList.size() == 1){
				out.println(ansList.get(0));
			} else 
			if (ansList.size() == 0){
				out.println("Volunteer cheated!");
			} else {
				out.println("Bad magician!");
			}
			
		}
		out.close();
		in.close();
	}

}
