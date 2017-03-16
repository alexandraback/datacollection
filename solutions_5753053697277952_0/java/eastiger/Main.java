import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
            
public class Main {
	
	public static int T, N, numOfSenate;
	public static int[] arr;
 
 
    public static void main(String[] arg) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringBuffer sb = new StringBuffer();
    	T = Integer.parseInt(br.readLine());
    	
    	for(int t = 1 ; t <= T ; t++){
    		N = Integer.parseInt(br.readLine());
    		
    		arr = new int[N];
    		
    		StringTokenizer st = new StringTokenizer(br.readLine());
    		
    		numOfSenate = 0;
    		
    		for(int i = 0 ; i < N ; i++){
    			arr[i] = Integer.parseInt(st.nextToken());
    			numOfSenate += arr[i];
    		}
    		
    		sb.append("Case #").append(t).append(":");
    		
    		while(numOfSenate != 0){
    			sb.append(" ").append(evacuateSenators());	
    			
    		}
    		sb.append("\n");
    		
    	}
    	System.out.println(sb);

        
    }


	private static String evacuateSenators() {
		
		StringBuffer sb = new StringBuffer();
		int maxIndex = -1;
		int max = 0;
		
		for(int i = 0 ; i < N ; i++){
			if(arr[i] > max){
				max = arr[i];
				maxIndex = i;
			}
		}
		
		sb.append(Character.toChars(65+maxIndex));
		numOfSenate--;
		arr[maxIndex] -= 1;
		
		if(numOfSenate%2 == 0){
			return sb.toString();
		}
		
		maxIndex = -1;
		max = 0;
		
		for(int i = 0 ; i < N ; i++){
			if(arr[i] > max){
				max = arr[i];
				maxIndex = i;
				
			}
		}
		
		sb.append(Character.toChars(65+maxIndex));
		numOfSenate--;
		arr[maxIndex] -= 1;
		
		return sb.toString();
	}
       
}