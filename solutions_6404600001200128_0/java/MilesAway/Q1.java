import java.util.*;
import java.io.*;
import java.lang.Math;
import java.math.*;

public class Q1{
	public static int first(int[] mushrooms){
		int eat = 0;
		int prev = mushrooms[0];
		for(int i : mushrooms){
			if(i >= prev){
				prev = i;
			} else {
				eat += (prev - i);
				prev = i;
			}
		}
		return eat;
	}

	public static int second(int[] a){
		int interval = 0;
		int eat = 0;
		int prev = a[0];
		for(int i = 1; i<a.length;i++){
			if(a[i] < prev){
				if(prev - a[i] > interval){
					interval = prev - a[i];
				}
			} 
			prev = a[i];
		}

		for(int i = 0; i < a.length - 1; i++){
			if(a[i] <= interval){
				eat += a[i]; // eat up;
			} else {
				eat += interval;
			}
		}
		return eat;
	}

	public static void main(String args[]){
		File f = new File(args[0]);
		try{
			Scanner s = new Scanner(f);
			int time = Integer.parseInt(s.next());
			PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
			for(int in = 1; in <= time; in++) {
				int timeslots = Integer.parseInt(s.next());
				int[] mushrooms = new int[timeslots];
				for(int m = 0; m < timeslots; m ++){
					mushrooms[m] = Integer.parseInt(s.next());
				}
				int m1 = first(mushrooms);
				int m2 = second(mushrooms);
				System.out.println("Finished: " + in);
				writer.println("Case #" + in + ": " + m1 + " " + m2);
			}
			writer.close();
		}catch (Exception e){
			e.printStackTrace();
		}
	}
}
