import java.util.Scanner;


public class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int kases=1;kases<=T;kases++) {
			int R1=in.nextInt()-1;
			int [][] B1 = new int[4][4];
			for(int i=0;i<4;i++) {
				for(int j=0;j<4;j++) {
					B1[i][j]=in.nextInt()-1;
				}
			}
			int R2=in.nextInt()-1;
			int [][] B2 = new int[4][4];
			for(int i=0;i<4;i++) {
				for(int j=0;j<4;j++) {
					B2[i][j]=in.nextInt()-1;
				}				
			}
			boolean [] p1 = new boolean[16];
			boolean [] p2 = new boolean[16];
			for(int i=0;i<4;i++) {
				p1[B1[R1][i]]=true;
				p2[B2[R2][i]]=true;
			}
			int ans = -1;
			for(int i=0;i<16;i++) {
				if(p1[i] && p2[i]) {
					if(ans==-1)
						ans=i;
					else {
						ans=-2;
					}
				}
			}
			System.out.print("Case #"+kases+": ");
			if(ans>=0) {
				System.out.println(ans+1);
			}
			else if(ans==-1)
				System.out.println("Volunteer cheated!");
			else if(ans==-2)
				System.out.println("Bad magician!");
		
		}
	}

}
