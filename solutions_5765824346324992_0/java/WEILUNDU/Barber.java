import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
public class Barber{
	static int B;
	static ArrayList<Integer> pattern = new ArrayList<Integer>();
	static int[] barber = new int[5];
	static int[] left = new int[5];
	static int N;
	static int minBarber;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine().trim());
		for(int i = 1; i <= T; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			B = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			minBarber = Integer.MAX_VALUE;
			for(int j = 0; j < B; j++){
				barber[j] = Integer.parseInt(st.nextToken());
				minBarber = Math.min(minBarber, barber[j]);			
			}
			//System.out.println(Arrays.toString(barber));
			sb.append(String.format("Case #%d: %d\n", i, solve()));
		}
		System.out.print(sb);
		br.close();
	}
	static boolean patternAppears(){
		for(int i = 0; i < B; i++){
			if(left[i] != 0)	return false;
		}
		return true;
	}
	static int findMin(){
		int r = left[0];
		for(int i = 1; i < B; i++){
			r = Math.min(r, left[i]);
		}
		return r;
	}
	static int solve(){
		pattern.clear();
		for(int i = 0; i < B; i++){
			left[i] = barber[i];
			pattern.add(i+1);
		}
		
		int step = B;
		while(!patternAppears() && step <= N){
			
			for(int i = 0; i < B; i++){
				if(left[i] == 0){
					left[i] = barber[i];
					pattern.add(i+1);
					step++;
				}
			}
			int min = findMin();
			for(int i = 0; i < B; i++){
				left[i] -= min;
			}
			//System.out.println("step "+ step);
			//System.out.println(Arrays.toString(left));
		}

		if(step == N)	return pattern.get(N-1);
		else return pattern.get((N - 1)  % pattern.size());

	}
}