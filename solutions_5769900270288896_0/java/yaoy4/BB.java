import java.io.*;
import java.util.*;

public class BB {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner console = new Scanner(new File("BB-small-attempt0.in"));
		PrintStream output = new PrintStream(new File("BBfinal.txt"));
		int caseNum = console.nextInt();
		for (int i = 1; i <= caseNum; i++) {
			int R = console.nextInt();
			int C = console.nextInt();
			int N = console.nextInt();
			output.println("Case #"+i+": " + find(R,C,N));
		}
	}

	public static int find(int R,int C,int N) {
		if(R>C){
			return find(C,R,N);
		}
		if(N<=R*C/2){
			return 0;
		}
		int X=R*C-N;
		int T=R*(C+1)+C*(R+1)-2*C-2*R;
		if(C==1){
			if(R%2==0){
				if(N==R/2+1){
					return 1;
				}
				return T-X*2;
			}
				return T-X*2;
			
		}
		if(C==2){
				if(N<=R*C/2+2){
					return 2*(N-R*C/2);
				}
				
				return T-3*X;
			}	
	
		if(C%2==0&&R%2==0){
			if(N<=R*C/2+2){
				return 2*(N-R*C/2);
			}
			if(N<=R*C/2+R+C-4){
				return 6+3*(N-R*C/2);
			}
			return T-4*X;		
		}else if(C%2!=0&&R%2!=0){
			if(N<=R*C/2+1){
				return 0;
			}
			if(N<=R*C/2+4){
				return 2*(N-R*C/2);
			}
			if(N<=R*C/2+2*(R+1)+2*(C+1)-8){
				return 8+3*(N-(R*C/2+2*(R+1)+2*(C+1)-8));
			}
			return T-4*X;
		}else{
			if(N<=R*C/2+2){
				return 2*(N-R*C/2);
			}
			if(N<=R*C/2+R+C-4){
				return 6+3*(N-R*C/2);
			}
			return T-4*X;	
		}
		
		}
		
}
	

