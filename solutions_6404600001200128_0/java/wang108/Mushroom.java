import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Mushroom {
	
	public void work() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			int n = sc.nextInt();
			int[] A = new int[n];
			for ( int i = 0 ; i < n ; ++i )
				A[i] = sc.nextInt();
			
			int ans1 = 0;
			int ans2 = 0;
			double maxRate = 0;
			for ( int i = 1 ; i < n ; ++i ){
				ans1 += Math.max(0, A[i-1] - A[i]);
				double rate = (A[i-1] - A[i])*1.0/10;
				if ( rate > maxRate )
					maxRate = rate;
			}
			
			for ( int i = 0 ; i < n-1 ; ++i )
				ans2 += Math.min(A[i], Math.ceil(maxRate*10));
			
			bw.write("Case #" + z + ": ");
			bw.write(ans1+" "+ans2);
			bw.write("\n");
		}
		bw.close();
		sc.close();
	}
}
