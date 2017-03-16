import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Haircut {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("B-small-attempt2.in"));//C-small-practice.inB-small-attempt1.in
		PrintWriter out = new PrintWriter("out.txt");
		int T = in.nextInt();
		for(int i=1;i<=T;i++){
			int B = in.nextInt();
			int N = in.nextInt();
			int[] M = new int[B];
			for(int j=0;j<B;j++ ){
				M[j] = in.nextInt();
			}
			int idx = findN(M,N);
			out.println("Case #"+i+": "+idx);
		}
		out.close();
		in.close();
	}
	
	private static int findN(int[]M, int N){
		int maxM = M[0];
		int common=M[0];
		for(int i=1;i<M.length;i++){
			maxM = Math.max(maxM,M[i]);
			common=minCommon(common,M[i]);			
		}
		int sum=0;
		for(int i=0;i<M.length;i++){
			sum+=common/M[i];
		}
		N=N-(N-1)/sum*sum;
		int r = maxM*N, l=0;
		while(l<r-1){
			int m = (l+r)/2;
			if(count(M,m)>=N){
				r=m;
			}
			else{
				l=m;
			}
		}
		//int [] res = new int[M.length];
		if(count(M,l)>=N){
			r=l;
		}
		int count=0;
		for(int i=0;i<M.length;i++){
			count+=r/M[i];
//			res[i]=r-r/M[i]*M[i];
//			N-=(int)Math.ceil((r+1)/M[i]);
//			if(N<=0){
//				return i;
//			}
		}
		return N-count;
//		if(count==N){
//			return M.length-1;
//		}
//		Arrays.sort(res);
//		int val = res[M.length-1-(N-count)];
//		int k=1;
//		for(int i=M.length-(N-count);i<M.length;i++){
//			if(res[i]==res[i-1]){
//				k++;
//			}
//			else{
//				break;
//			}
//		}
//		for(int i=0;i<M.length;i++){
//			if(r-r/M[i]*M[i]==val){
//				k--;
//				if(k==0){
//					return i;
//				}
//			}
//		}
//		return 0;
	}
	
	private static int count(int[]M, int t){
		int res=0;
		for(int i=0;i<M.length;i++){
			res+=(int)Math.ceil((t+1)*1.0/M[i]);
		}
		return res;
	}
	
	private static int minCommon(int a, int b) {  
        int aa = a / comp(a,b);  
        int  bb = b / comp(a,b);  
          
        return aa * bb * comp(a,b);  
    }  
  
    private static int comp(int a, int b) {  
        if (Math.max(a, b) % Math.min(a, b) == 0) {  
            return Math.min(a, b);  
  
        } else {  
            int c = Math.min(a, b) / 2;  
            while (c >= 2) {  
                if (a % c == 0 && b % c == 0) {  
                    return c;  
                } else {  
                    c--;  
                }  
            }  
            return c;  
        }  
    } 

}
