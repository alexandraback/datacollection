import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class MagicTrick {
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens())
				tk=new StringTokenizer(br.readLine());
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
	}
	
	
	
	static int[][] readgrid(Scanner sc) throws NumberFormatException, IOException{
		int[][] ret = new int[4][4];
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				ret[i][j] = sc.nextInt();
		return ret;
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 0; c < T; c++){
			int ans1 = sc.nextInt() - 1;
			int[][] grid1 = readgrid(sc);
			int ans2 = sc.nextInt() - 1;
			int[][] grid2 = readgrid(sc);
			TreeSet<Integer> first = new TreeSet<Integer>();
			TreeSet<Integer> ans = new TreeSet<Integer>();
			for(int j = 0; j < 4; j++)
				first.add(grid1[ans1][j]);
			for(int j = 0; j < 4; j++)
				if (first.contains(grid2[ans2][j]))
					ans.add(grid2[ans2][j]);
			String print = "Volunteer cheated!";
			if (ans.size() == 1)
				print = "" + ans.first();
			if (ans.size() > 1)
				print = "Bad magician!";
			System.out.printf("Case #%d: %s\n", c + 1, print);
		}
	}

}
