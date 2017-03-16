import java.util.*;

public class A{

	static long dp[][][];
	static String s[];
	static int arr[][];



	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int ca = 1 ; ca <= T; ca++){
			int N = sc.nextInt();

			s = new String[N];
			for(int i = 0; i < N; i++)
				s[i] = sc.next();

			dp = new long[N][101][101];
			for(int i = 0; i < N; i++)
				for(int j = 0; j  <= 100 ; j++)
					for(int k = 0; k  <= 100; k++)
						dp[i][j][k] = -1;
			
			StringBuilder sb = new StringBuilder();
			sb.append(s[0].charAt(0));
			for(int i = 1; i < s[0].length(); i++)
				if(s[0].charAt(i-1) != s[0].charAt(i))
					sb.append(s[0].charAt(i));

			String base = sb.toString();
			arr = new int[N][sb.length()];
			for(int i = 0; i < N && arr != null; i++){
				int index = 0;
				int count = 0;
				for(int j = 0; j < base.length(); j++){
					count = 0;
					while(index < s[i].length() && s[i].charAt(index) == base.charAt(j)){
						count++;
						index++;
					}
					arr[i][j] = count;
				}

				for(int j = 0; j < base.length(); j++)
					if(arr[i][j] == 0){
						arr = null;
						break;
					}
				if(index != s[i].length()){
					arr = null;
				}
			}

			if(arr == null) System.out.printf("Case #%d: Fegla Won\n",ca);
			else{
				long total = 0;

				for(int index =  0; index < base.length(); index++){
					int min = 1<<30;
					for(int i = 0; i < N; i++){
						int count = 0;
						for(int j = 0; j < N; j++)
							count += Math.abs(arr[i][index]-arr[j][index]);
						min = Math.min(min,count);
					}
					total+=min;
				}
				
				System.out.printf("Case #%d: %d\n",ca,total);
			}
		}
	}
}