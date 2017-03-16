package googlecodejam;
import java.io.*;
import java.util.*;

public class Haircut {


	  public static void main (String [] args) throws IOException {
	    // Use BufferedReader rather than RandomAccessFile; it's much faster
	    BufferedReader f = new BufferedReader(new FileReader("B-small-attempt2.in"));
	                                                  // input file name goes above
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("haircut.out.txt")));
	    // Use StringTokenizer vs. readLine/split -- lots faster
	    StringTokenizer st = new StringTokenizer(f.readLine());
							  // Get line, break into tokens
	    
	   //enter program here
	    
	    String answer ="";
	    int numCases = Integer.parseInt(st.nextToken());
	    for (int i = 0; i<numCases;i++){
		    st = new StringTokenizer(f.readLine());
	    	int numBarbers = Integer.parseInt(st.nextToken());
	    	int finalPos = Integer.parseInt(st.nextToken());
	    	int currPos = 0;
	    	int[][] holder = new int[numBarbers][3];
	    	st = new StringTokenizer(f.readLine());
	    	for (int j = 0; j<numBarbers;j++){
	    		holder[j][0] = Integer.parseInt(st.nextToken());
	    	}
	    	//System.out.println(finalPos+" "+numBarbers);
	    	ArrayList<Integer> positions = new ArrayList();
	    	boolean flag = false;
	    	search:
	    	while (currPos<finalPos){
	    		/**
	    		for (int j = 0; j<numBarbers;j++){
	    			System.out.println(holder[j][0]+" "+holder[j][1]+" "+holder[j][2]);
	    		}**/

	    		for (int j = 0;j<numBarbers;j++){
	    			if (holder[j][1]==0){
	    				currPos+=1;
	    				holder[j][2]=currPos;
	    				if (currPos==finalPos){
	    					answer = (j+1)+"";
	    					break search;
	    				}else{
	    					positions.add(j+1);
	    				}
	    			}
	    		}
	    		int minTime = Integer.MAX_VALUE;
	    		for (int j = 0; j<numBarbers;j++){
	    			if (holder[j][0]-holder[j][1]<minTime){
	    				minTime = holder[j][0]-holder[j][1];
	    			}
	    		}
	    		for (int j = 0; j<numBarbers;j++){
	    			holder[j][1] = (holder[j][1]+minTime)%holder[j][0];
	    		}
	    		if (currPos!=0){
	    			flag = true;
	    		}
	    		for (int j = 0; j<numBarbers;j++){
	    			if (holder[j][1]!=0){
	    				flag = false;
	    			}
	    		}
	    		if (flag){
	    			answer = ""+positions.get((finalPos-1)%currPos);
	    			break search;
	    		}
	    	}
	    	
	    	
	    	
	    	
	    	System.out.println("Case #"+(i+1)+": "+answer);
	    	out.println("Case #"+(i+1)+": "+answer);
	    }
	    // answer output

    	out.close();	    
	    System.exit(0);                               // don't omit this!
	  }

}