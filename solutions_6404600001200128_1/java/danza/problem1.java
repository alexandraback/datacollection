import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;


public class problem1 {

	public static void main(String[] args) throws IOException {
		//int[] array = {23,90, 40, 0, 100, 9};
		//int[] array = {10,5,15,5};
		int[] array = {100,100};

		//int[] array = {81,81, 81 ,81 ,81 ,81 ,81 ,0};
		int min;/*
		min = getMin1(array);
		System.out.println(min);
		min = getMin2(array);
		System.out.println(min);*/
		try (Writer writer = new BufferedWriter(new OutputStreamWriter(
	              new FileOutputStream("/home/danza/Downloads/output1L.txt"), "utf-8"))) {
	  // writer.write("something");
		
		int j=1;
		BufferedReader br = new BufferedReader(new FileReader("/home/danza/Downloads/A-large (1).in"));
	    try {
	        StringBuilder sb = new StringBuilder();
	        String line = br.readLine();
	        while (line != null) {
	            sb.append(line);
	            sb.append(System.lineSeparator());
	            int len = Integer.parseInt(br.readLine());
	            line = br.readLine();
	            int[] arr = new int[len];
	            String[] sarray = line.split(" ");
	            for(int i=0;i<len;i++){
	            	arr[i] = Integer.parseInt(sarray[i]);
	            }
	            int min1 = getMin1(arr);
	    		System.out.println(min1);
	    		int min2 = getMin2(arr);
	    		System.out.println(min2);
	    		writer.write("Case #"+(j++)+": "+min1+" "+min2+"\n");
	        }
	        String everything = sb.toString();
	    }catch(Exception e){
	    	
	    }
	    finally {
	        br.close();
	    }
		}
	}
	private static int getMin2(int[] array) {
		int maxDiff = 0;
		for(int i=1;i<array.length;i++){
			if(array[i]<array[i-1]){
				int temp = Math.abs(array[i]-array[i-1]);
				if(temp>maxDiff)
					maxDiff = temp;
			}
		}
		int min=0;

		for(int i=0;i<array.length-1;i++){
			//int temp = Math.abs(array[i]-array[i-1]);
			if(array[i]>=maxDiff){
				min+=maxDiff;
			} 
			else
				min+=array[i];

		}
		
		return min;
	}
	private static int getMin1(int[] array) {
		int min = 0;
		for(int i=1;i<array.length;i++){
			if(array[i]<array[i-1]){
				int temp = Math.abs(array[i]-array[i-1]);
				min+=temp;
			}
		}
		return min;
	}
}
