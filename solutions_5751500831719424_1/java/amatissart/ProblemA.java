package Round1B;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;


public class ProblemA {

	static int N;
	static int L;
	
	public static void main(String[] args) {
		
		FileReader fr = null ;
    	Scanner sc = null;
    	int n_cases = 0;
    	Locale.setDefault(Locale.US);
    
    
    	try{
    		fr = new FileReader(args[0]);
    		sc = new Scanner(fr);
    		
    		if (sc.hasNextInt()) n_cases = sc.nextInt();
    		
    		for (int i=0;i<n_cases;i++){
    			
    			boolean stop = false;
    			N = sc.nextInt();
    			int result = 0;
    			ArrayList<Character> chars = new ArrayList<Character>();
    			ArrayList<int[]> occ = new ArrayList<int[]>();
    			
    			sc.nextLine();
    			String s = sc.nextLine();
    			
    			chars.add(s.charAt(0));
    			occ.add(new int[N]);
				for (int k =0;k<s.length();k++){
					char c;
					if ((c = s.charAt(k)) != chars.get(chars.size()-1)){
						chars.add(c);
						occ.add(new int[N]);
						occ.get(occ.size()-1)[0]=1;
					}
					else{
						occ.get(occ.size()-1)[0]+=1;
					}
				}
							
				for(int j=1;j<N;j++){
    				s = sc.nextLine();
    				int n_char = 0;
    				for (int k =0;k<chars.size();k++){
    					char c;
    					while(n_char< s.length() && (c = s.charAt(n_char)) == chars.get(k)){
    						occ.get(k)[j]+=1;
    						n_char++;
    					}
    						
    					if(occ.get(k)[j]==0){
    						stop = true;
    						break;
    					}
    				}
    				if (n_char < s.length()){
    					stop = true;
    				}
    				
    			}
				
				for (int j=0;j<chars.size() && !stop;j++){
					Arrays.sort(occ.get(j));
					int median = occ.get(j)[N/2];
					for (int l=0;l<N;l++){
						result += Math.abs(occ.get(j)[l]-median);
					}
					
				}
    			
    	
				if (!stop)
					System.out.println("Case #"+(i+1)+": " + result);
				else
					System.out.println("Case #"+(i+1)+": Fegla Won");
	    				
    					
    		}
    		
    	} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
    	finally{
    		if(sc != null) sc.close();
    		if(fr != null)	try {fr.close();} catch (Exception e) {}
    	}
       	

	}


}
