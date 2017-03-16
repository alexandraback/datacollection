import java.util.ArrayList;
import java.util.Scanner;

public class pro3 {
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int T= scanner.nextInt();

		for( int t=0; t<T; t++){
			int N = scanner.nextInt();
			Tree[] trees = new Tree[N];

			for( int i=0; i<N; i++){
				int x = scanner.nextInt();
				int y = scanner.nextInt();
				trees[i] = new Tree(x,y);
			}
			
			double[][][] vertex = new double[N][N][2];
			
			for( int i=0; i<N; i++){
				for( int j=0; j<=i; j++){
					Tree a = trees[i];
					Tree b = trees[j];
					double m;
					if( a.X == b.X ){
						m = Double.MAX_VALUE;
					}
					else{
					 	m = (a.Y-b.Y)/(a.X-b.X);
					}
					
					double beta;
					if( a.X == b.X){
						beta = 0;
					}
					else{
						beta = -m*a.X+a.Y;
					}

					vertex[i][j][0] = m;
					vertex[i][j][1] = beta;
					
					
					vertex[j][i][0]	= m;
					vertex[j][i][1]	= beta;
				}
			}
			

			int[] ans= new int[N];
			for( int s=0; s<N; s++){
				double[][] selected = vertex[s];
				
				int min = N-1;
				for( int i=0; i<N; i++){
					if( i == s )	continue;
					double m = selected[i][0];
					double beta = selected[i][1];
					Tree onVertex = trees[i];
					
					int plusIndex = 0;
					int minusIndex = 0;
					if( m == Double.MAX_VALUE ){
						int axis = onVertex.X;
						for (int j=0; j<N; j++){
							if( axis > trees[j].X){
								plusIndex++;
							}
							else if (axis < trees[j].X){
								minusIndex++;
							}
						}
					}
					else{
						for( int j=0; j<N; j++){
							if( j==s || j==i)	continue;
							Tree checkVertex = trees[j];
							double onY = m*checkVertex.X+beta;

							if( onY < checkVertex.Y ){
								plusIndex++;
							}
							else if( onY > checkVertex.Y){
								minusIndex++;
							}
						}
					}
					/*
					if( s == 4 ){
						System.out.println("s,i"+s+" "+i);
						System.out.println("plusIndex"+plusIndex);
						System.out.println("minusIndex"+minusIndex);

					}
					*/
					min = Math.min(min, Math.min(plusIndex, minusIndex));
				}
				ans[s] = min;
			}
			
			
			System.out.println("Case #"+(t+1)+":");			
			for( int i=0; i<N; i++){
				System.out.println(ans[i]);			
			}
			
		}
	}
	static class Tree{
		int X;
		int Y;
		Tree(int x, int y){
			X= x;
			Y= y;
		}
	}
}
