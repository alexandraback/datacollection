import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;




public class prbl1 {
	static Random ran = new Random();
	public static int happy(int r, int c, int n){
		long startTime = System.currentTimeMillis();
		int Min = Integer.MAX_VALUE;
		int[][] a = new int[r][c];
		int x;
		int y;
		for(int i=0;i<400000 && Min !=0;i++){
			int min = 0;
			for(int j=0;j<n;j++){
				do{x= ran.nextInt(r);
				y= ran.nextInt(c);}
				while(a[x][y] !=0);
				a[x][y] = 1;	
			}
			boolean cond = true;
			for(int l=0;cond &&l<r;l++){
				for(int m=0;cond&&m<c;m++){
					if(a[l][m] ==1){					
						if( l<r-1 && a[l+1][m]==1)min++;
						if( m<c-1 && a[l][m+1]==1)min++;
					}
					if(!(min<Min)) cond = false;
				}
			}
			
			if(min<Min) Min = min;
			a = new int[r][c];
		}
		
		
		return Min;
	}
	public static void main(String[] args) throws IOException {
		long startTime = System.currentTimeMillis();
		FileWriter fw = new FileWriter("out.txt");
		Scanner sc = new Scanner(new File("B-small-attempt1.in"));
		BufferedWriter out = new BufferedWriter(fw);
		int nb = sc.nextInt();
		// System.out.println(i);
	
		for (int i = 0; i < nb; i++) {
			int h =happy(sc.nextInt(),sc.nextInt(),sc.nextInt());
			System.out.println(h);
			
			out.write("Case #"+(i+1)+": "+h+"\n");
		}
		//out.flush();
		out.close();
		long endTime = System.currentTimeMillis();
		System.out.println("That took " + (endTime - startTime)/1000 + " seconds");
	}
}
