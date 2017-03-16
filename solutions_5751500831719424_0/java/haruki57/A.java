package googleCodeJam2014r1b;

import java.util.Scanner;

public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt(); 
		for(int t=1;t<=T;t++){
			System.out.print("Case #"+t+": ");
			int N = sc.nextInt();
			if(N>=3)continue;
			char[][] s = new char[N][];
			StringBuffer[]sb=new StringBuffer[N];
			for(int i=0;i<N;i++){
				s[i]=sc.next().toCharArray();
				sb[i]=new StringBuffer();
				sb[i].append(s[i][0]);
				for(int j=1;j<s[i].length;j++){
					if(s[i][j]!=s[i][j-1]){
						sb[i].append(s[i][j]);
					}
				}
			}
			if(!sb[0].toString().equals(sb[1].toString())){
				System.out.println("Fegla Won");
				continue;
			}
			int i1=0,i2=0;
			int ans=0;
			for(int i=0;i<sb[0].length();i++){
				char c = sb[0].charAt(i);
				int c1=0,c2=0;
				for(;i1<s[0].length;){
					if(s[0][i1]==c){
						c1++;
						i1++;
					}
					else{
						break;
					}
				}
				for(;i2<s[1].length;){
					if(s[1][i2]==c){
						c2++;
						i2++;
					}
					else{
						break;
					}
				}
				ans+=Math.abs(c1-c2);
			}
			System.out.println(ans);
			
		}
	}

}
