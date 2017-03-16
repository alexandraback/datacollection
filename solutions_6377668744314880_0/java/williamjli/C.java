import java.awt.Point;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class C {

	public static void main(String[] args) throws IOException {
		
		BufferedReader input = new BufferedReader(new FileReader("C:\\Users\\William Li\\Desktop\\input.txt"));
		PrintWriter output = new PrintWriter(new FileWriter("C:\\Users\\William Li\\Desktop\\output.txt"));
		
		int T = Integer.parseInt(input.readLine());
		
		for (int t = 1; t <= T; t++){
			
			int N = Integer.parseInt(input.readLine());
			
			Point[] trees = new Point[N];
			
			for (int i = 0; i < N; i++){
				
				String[] nextLine = input.readLine().split(" ");
				trees[i] = new Point(Integer.parseInt(nextLine[0]), Integer.parseInt(nextLine[1]));
				
				if (t == 61){
					
					System.out.println(trees[i].x + " " + trees[i].y);
					
				}
				
			}
			
			output.println("Case #" + t + ":");
			
			for (int i = 0; i < N; i++){
				
				if (N == 1){
					
					output.println(0);
					
				}else{
					
					output.println(calculateCloseness(trees, i));
				
				}
				
			}
			
		}
		
		input.close();
		output.close();
		
		System.exit(0);
		
	}
	
	public static int calculateCloseness(Point[] trees, int index) {
		
		int min = 2147483647;
		
		for (int i = 0; i < trees.length; i++){
			
			if (i != index) {
				
				double slope = (trees[i].y - (double) trees[index].y) / (trees[i].x - (double) trees[index].x);
				double intercept = trees[index].y - slope * trees[index].x;
				
				int positive = 0;
				int negative = 0;
				
				if (Double.isInfinite(slope)){
					
					for (int j = 0; j < trees.length; j++){
						
						if (trees[j].x < trees[index].x){
							
							positive++;
							
						}else if (trees[j].x > trees[index].x){
							
							negative++;
							
						}
						
					}
					
				}else{
				
					for (int j = 0; j < trees.length; j++){
						
						double result = trees[j].y - (slope * trees[j].x + intercept);
						//System.out.println(slope + " " + intercept + " " + result);
						if (essentiallyZero(result)){
							
						}else if (result > 0){
							
							positive++;
							
						}else{
							
							negative++;
							
						}
						
					}
				
				}
				
				min = Math.min(negative, Math.min(positive, min));
				
			}
			
		}
		
		return min;
		
	}
	
	public static boolean essentiallyZero(double value) {
		
		return Math.abs(value) < .0000001;
		
	}

}