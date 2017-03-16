import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;

public class Senate {
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		
		FileInputStream file = new FileInputStream("D:\\Work\\Resources\\CodeJam2016\\Personal\\A-large.in");
		InputStreamReader reader = new InputStreamReader(file);
		BufferedReader br = new BufferedReader(reader);
		String strLine = "";
		double numberOfTestCases = Double.parseDouble(br.readLine());
		for(int testCaseCounter = 1;testCaseCounter<=numberOfTestCases;testCaseCounter++){
			String output = "Case #" + testCaseCounter + ": ";
			int noOfParties = Integer.parseInt(br.readLine());
	        
	        int sum = 0;
	        int[]  parties = new int[noOfParties];
	        String[] partiesString = br.readLine().split(" ");
	        
	        for(int i=0;i<noOfParties;i++){
	            parties[i] = Integer.parseInt(partiesString[i]);
	            sum+= parties[i];
	        }
	        String ans = "";
	        while(sum > 0){
	            int mx = getMax(parties);
	            parties[mx]--;
	            ans+=(myAns(mx));
	            sum--;
	            int nx = getMax(parties);
	            parties[nx]--;
	            if(isValid(parties)){
	                ans += (myAns(nx));
	                sum--;
	            } else {
	                parties[nx]++;
	            }

	            ans += " ";

	        }
	        System.out.println(output + ans);
		}
	}
	
	private static int max(int i, int j){
		if(i>j)
			return i;
		else return j;
	}
	private static boolean isValid(int[] parties) {
	    int mx = 0;
	    int sum = 0;
	    for(int i=0;i<parties.length; i++) {
	        mx = max(mx, parties[i]);
	        sum += parties[i];
	    }
	    if(2*mx > sum){
	        return false;
	    } else return true;
	}

	private static char myAns(int i){
		char returnChar = 'A';
		returnChar = (char)((int)returnChar + i);
		return returnChar;
	}
	private static int getMax(int[] parties){
	    int mx = 0;
	    int indx = 0;
	    for(int i=0;i<parties.length; i++) {
	        if(mx< parties[i]){
	            mx = parties[i];
	            indx = i;
	        }
	    }
	    return indx;
	}
}
