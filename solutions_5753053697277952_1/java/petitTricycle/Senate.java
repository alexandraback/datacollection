import java.util.*;
import java.io.*;

public class Senate{
    static Scanner in = new Scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args){
	int t = in.nextInt();

	for(int c = 1; c<=t; c++){
	    out.println("Case #"+c+":"+solve());
	}

	out.close();
    }

    static String solve(){
	int n = in.nextInt();
	int total = 0;
	int[] p = new int[n];
	for(int i = 0; i<n; i++){
	    p[i]=100*in.nextInt()+i;
	    total+=p[i]/100;
	}
	Arrays.sort(p);

	StringBuilder answer = new StringBuilder();

	while(total>3){
	    if(p[n-1]/100>=p[n-2]/100+2){
		answer.append(' ');
		answer.append((char)('A'+p[n-1]%100));
		answer.append((char)('A'+p[n-1]%100));
		p[n-1]-=200;
	    } else {
		answer.append(' ');
		answer.append((char)('A'+p[n-1]%100));
		answer.append((char)('A'+p[n-2]%100));
		p[n-1]-=100;
		p[n-2]-=100;
	    }
	    total-=2;
	    Arrays.sort(p);
	}

	if(total==3)
	    if(p[n-1]==2){
		answer.append(' ');
		answer.append((char)('A'+p[n-1]%100));
		answer.append(' ');
		answer.append((char)('A'+p[n-1]%100));
		answer.append((char)('A'+p[n-2]%100));
	    } else {
		answer.append(' ');
		answer.append((char)('A'+p[n-1]%100));
		answer.append(' ');
		answer.append((char)('A'+p[n-2]%100));
		answer.append((char)('A'+p[n-3]%100));
	    }
	else{
	    answer.append(' ');
	    answer.append((char)('A'+p[n-1]%100));
	    answer.append((char)('A'+p[n-2]%100));
	}
	
	return answer.toString();
    }

}

