import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for(int c=1;c<=cases;c++){
			int n = sc.nextInt();
			int[] p  = new int[n];
			for(int i=0;i<n;i++){
				p[i] = sc.nextInt();
			}
			StringBuilder sb = new StringBuilder();
			int m = findMax(p);
			while(!Empty(p)){
				p[m]--;
				sb.append((char) (m+65));
				int k = findMax(p);
				if(p[k]/(double) sum(p)>0.5){
					p[k]--;
					sb.append((char) (k+65));
				}				
				sb.append(" ");
				m = findMax(p);
			}
			System.out.printf("Case #%d: %s\n",c, sb.toString());
		}
	}
	
	public static int sum( int[] a){
		int s = 0;
		for(int i:a) s+=i;
		return s;
	}
	
	public static boolean Empty(int[] a){
		int count = 0;
		for(int i:a){
			if(i!=0) return false;
		}
		return true;
	}
	
	public static int findMax(int[] a){
		int max = -1;
		int maxPos = -1;
		for(int i=0;i<a.length;i++){
			if(a[i]>max){
				max = a[i];
				maxPos = i;
			}
		}
		return maxPos;
	}
}