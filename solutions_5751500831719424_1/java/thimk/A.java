import java.util.*;

public class A
{
    public static void main(String[] args)
    {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();

	for(int caseno = 1; caseno <= T; caseno++){
	    int N = in.nextInt(); 

	    String str[] = new String[N];
	    for(int i = 0; i < N; i++){
		str[i] = in.next();
	    }

	    char[] c = new char[100];
	    int nc = 0;
	    
	    int cnt[][] = new int[100][N];
	    
	    char prev = '0';
	    for(int i = 0; i < str[0].length(); i++){
		if(str[0].charAt(i) != prev){
		    prev = str[0].charAt(i);
		    c[nc] = prev;
		    cnt[nc][0] = 1;
		    nc++;
		}else{
		    cnt[nc-1][0]++;
		}
	    }

	    
	    boolean fail = false;

	    for(int i = 1; i < N && !fail; i++){
		if(str[i].charAt(0) != c[0]){
		    fail = true;
		}else{
		    int idx = 0;
		    cnt[idx][i] = 1;
		    
		    for(int j = 1; j < str[i].length() && !fail; j++){
			if(str[i].charAt(j) == c[idx]){
			    cnt[idx][i]++;
			}else{
			    idx++;
			    if(idx < nc && str[i].charAt(j) == c[idx]){
				cnt[idx][i] = 1;
			    }else{
				fail = true;
			    }
			}
		    }
		
		    if(idx != nc - 1) fail = true;
		}
	    }
		
	    /*
	    for(int i = 0; i < N; i++){
		for(int j = 0; j < nc; j++)
		    System.out.print(" " + cnt[i][j]);
		System.out.println();
		}*/

	    if(!fail){
		int cost = 0;
		for(int i = 0; i < nc; i++){
		    Arrays.sort(cnt[i]);
		    for(int j = 0; j < N-1-j; j++)
			cost += cnt[i][N-1-j] - cnt[i][j];
		}
		System.out.println("Case #" + caseno + ": " +cost);
	    }else
		System.out.println("Case #" + caseno + ": " + "Fegla Won");
	    
	}
    }
}
