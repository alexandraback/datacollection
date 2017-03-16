import java.util.*;
import java.io.*;

public class B {
	
	public static boolean check(int[] a, int[] b) {
		for(int i=0; i<a.length; i++)
			if(a[i] != b[i]) return true;
		return false;
	}

    public static void main(String[] args) throws Exception {
    	Scanner s = new Scanner(new FileReader("b.in"));
    	PrintWriter printer = new PrintWriter(new FileWriter("b.out"));
    	int t = s.nextInt();
    	for(int i=0; i<t; i++) {
    		int b = s.nextInt();
    		int n = s.nextInt();
    		int[] arr = new int[b];
    		Vector<Integer> list = new Vector<Integer>();
    		int[] time = new int[b];
    		for(int j=0; j<b; j++) {
    			arr[j] = s.nextInt();
    			list.add(j);
    			time[j] = arr[j];
    		}
    		do {
    			for(int j=0; j<b; j++) {
    				time[j]--;
    				if(time[j] == 0) {
    					list.add(j);
    					time[j] = arr[j];
    				}
    				//System.out.print(time[j] + " ");
    			}
    			//System.out.println();
    		} while(check(arr, time));
    		for(int j=0; j<b; j++)
    			list.removeElementAt(list.size()-1);
    		//System.out.println(list);
    		int idx = (n%list.size())-1;
    		if(idx == -1) idx = list.size()-1;
    		int ans = list.elementAt(idx)+1;
    		System.out.println(ans + " " + list.size());
    		if(i < 6) System.out.println(list);
    		printer.println("Case #" + (i+1) + ": " + ans);
    	}
    	printer.close();
    }
}
