import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Round1C {
	
	public static Integer sum(List<Integer> list) {
	     Integer sum = 0; 
	     for (Integer i:list)
	         sum = sum + i;
	     return sum;
	}
	

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    int t = in.nextInt();
	    char[] alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();
	    
	    for (int i = 0; i<t; i++){
	    	int n = in.nextInt();
	    	int sumnumber;
	    	List<Integer> numbers = new ArrayList<Integer>();
	    	List<String> evacuation = new ArrayList<String>();
	    	
	    	for (int j = 0; j< n; j++){
	    		numbers.add(in.nextInt());
	    	}
	    	sumnumber = sum(numbers);
	    	while(sumnumber > 3){
	            String string = "";
	    		Integer max = Collections.max(numbers);
	    		int index = numbers.indexOf(max);
	    		numbers.set(index, (numbers.get(index)-1));
	    		string = string + alphabet[index];
	    		max = Collections.max(numbers);
	    		index = numbers.indexOf(max);
	    		numbers.set(index, (numbers.get(index)-1));
	    		string = string + alphabet[index];
	    		evacuation.add(string);
	    		
	    		sumnumber = sum(numbers);
	    	}
	    	if(sumnumber == 3){
	    		Integer max = Collections.max(numbers);
	    		int index = numbers.indexOf(max);
	    		numbers.set(index, (numbers.get(index)-1));
	    		String string = "" + alphabet[index];
	    		evacuation.add(string);
	    	}
	    	Integer max = Collections.max(numbers);
    		int index = numbers.indexOf(max);
    		numbers.set(index, (numbers.get(index)-1));
    		String string = "" + alphabet[index];
    		max = Collections.max(numbers);
    		index = numbers.indexOf(max);
    		numbers.set(index, (numbers.get(index)-1));
    		string = string + alphabet[index];
    		evacuation.add(string);
    		
    		String result = "";
    		
    		for (String temp : evacuation){
    			result = result + " "  + temp;
    		}
    		
    		System.out.println("Case #" + (i+1) + ":" + result);
	    	
	    	
	    }

	}

}
