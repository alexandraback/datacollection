import java.util.Scanner;


public class Mushrooms {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
        	
            int n = sc.nextInt();
            int[] ar = new int[n];
            for(int j=0; j<n; j++){
            	ar[j] = sc.nextInt();
            }
            long c1 = calc1(ar);
            long c2 = calc2(ar);
            
            System.out.println("Case #"+(i+1)+": "+c1+" "+c2);

        }
    }


	private static long calc1(int[] ar) {
		long sum = 0;
		for(int i=0; i<ar.length-1;i++){
			if(ar[i]>ar[i+1]){
				sum += ar[i]-ar[i+1];
			}
		}
		return sum;
	}

	private static long calc2(int[] ar) {
		int rate = 0;
		for(int i=0; i<ar.length-1;i++){
			if(ar[i]>ar[i+1]){
				if(ar[i]-ar[i+1] > rate){
					rate = ar[i]-ar[i+1];
				}
			}
		}
		
		long sum = 0;
		for(int i=0; i<ar.length-1;i++){
				if(ar[i] >= rate){
					sum += rate;
				} else {
					sum += ar[i];
				}
		}
		
		return sum;
	}

}
