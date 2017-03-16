import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Logging {

	public void work() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			int n = sc.nextInt();
			int[] X = new int[n];
			int[] Y = new int[n];
			for ( int i = 0 ; i < n ; ++i ){
				X[i] = sc.nextInt();
				Y[i] = sc.nextInt();
			}
			
			bw.write("Case #" + z + ": \n");
			if ( n == 1 ){
				bw.write("0\n");
				continue;
			}
			
			for ( int i = 0 ; i < n ; ++i ){
				int min = Integer.MAX_VALUE;
				for ( int j = 0 ; j < n ; ++j ){
					if ( i == j )
						continue;
					int leftCount = 0;
					int rightCount = 0;
					if ( X[i] == X[j] ){
						for ( int k = 0 ; k < n ; k++ ){
							if ( k == i || k == j )
								continue;
							if ( X[k] < X[i] )
								leftCount++;
							if ( X[k] > X[i] )
								rightCount++;
							if ( leftCount >= min && rightCount >= min )
								break;
						}
					}
					else {
						double K = (Y[i]-Y[j])*1.0/(X[i]-X[j]);
						for ( int k = 0 ; k < n ; k++ ){
							if ( k == i || k == j )
								continue;
							double y = K*(X[k]-X[i]) - (Y[k]-Y[i]);
							if ( Math.abs(y) <= Double.MIN_VALUE )
								continue;
							if ( y < 0 )
								leftCount++;
							else rightCount++;
							if ( leftCount >= min && rightCount >= min )
								break;
						}
					}
					
					min = Math.min(min, Math.min(leftCount, rightCount));
					if ( min == 0 )
						break;
				}
				bw.write(min + "\n");
			}
			
		}
		bw.close();
		sc.close();
	}
	
	void dfs( int index, int cur, boolean[] cut ){
		
	}
	
	
	public void work2() throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			int n = sc.nextInt();
			int[] X = new int[n];
			int[] Y = new int[n];
			for ( int i = 0 ; i < n ; ++i ){
				X[i] = sc.nextInt();
				Y[i] = sc.nextInt();
			}
			
			bw.write("Case #" + z + ": \n");
			
		}
		bw.close();
		sc.close();
	}

}
