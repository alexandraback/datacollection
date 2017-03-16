import java.util.*;

public class TheRepeater{
	
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int t=0; t<T; t++){
			
			int N = sc.nextInt();
			String[] s = new String[N];
			String[] basic = new String[N];
			boolean flag = true;
			int[][] count = new int[N][100];
			int move = 0;
			
			for(int i=0; i<N; i++){
				s[i] = sc.next();
				basic[i] = "";
			}
			
			for(int i=0; i<N; i++){
				int k=0;
				for(int j=0; j<s[i].length(); j++){
					if(j == 0){
						basic[i] += s[i].charAt(j);
					}else if(s[i].charAt(j) != s[i].charAt(j-1)){
						k++;
						basic[i] += s[i].charAt(j);
					}else{
						count[i][k] += 1;
					}
				}
			}
			
			/*
			for(int i=0; i<N; i++){
				System.out.println(s[i]);
				System.out.println(basic[i]);
			}
			*/
			
			for(int i=0; i<N; i++){
				if(!basic[i].equals(basic[0])){
					flag = false;
					break;
				}
			}
			
			if(flag){
				for(int j=0; j<count[0].length; j++){
					if(count[0][j]>=count[1][j]){
						move += count[0][j] - count[1][j];
					}else{
						move += count[1][j] - count[0][j];
					}
				}
			}
			
			System.out.println("Case #"+(t+1)+": "+(flag?move:"Fegla Won"));
			
		}
		
	}
	
}