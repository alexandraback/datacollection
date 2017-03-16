import java.util.ArrayList;
import java.util.Scanner;

public class pro2 {
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int T= scanner.nextInt();

		for( int t=0; t<T; t++){
			int B = scanner.nextInt();
			int N = scanner.nextInt();
			int[] M = new int[B];
			int mult[] = new int[B];
			ArrayList<Integer> list = new ArrayList<Integer>();
			
			for( int i=0; i<B; i++){
				M[i] = scanner.nextInt();
				mult[i] = M[i];
				list.add(i);
			}
			
			boolean isLcm = false;
			while( !isLcm ){
				int min = 0;
				isLcm = true;
				for( int i=0; i<B; i++){
					int a = mult[min];
					int b = mult[i];
					if( a == b ){ continue;	}
					isLcm = false;
					if( a > b ){
						min = i;
					}
				}
				if( isLcm )	continue;
				mult[min] += M[min];
				list.add(min);
			}
			
			

			int length = list.size();
			int ans = list.get((N-1)%length);
			ans++;

			/*
			for (int i=0; i< length; i++){
				System.out.print(list.get(i)+" ");
			}
			*/
			System.out.println("Case #"+(t+1)+": "+ans);			
			
		}
	}
}
