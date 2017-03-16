import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.SortedSet;
import java.util.TreeSet;
 
 
public class Main {
	
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter file = new PrintWriter("output.txt");
		
		int t = Integer.parseInt(in.readLine());
		for(int i = 0; i < t; ++i){
			String line[] = in.readLine().split(" ");
			int b = Integer.parseInt(line[0]);
			int n = Integer.parseInt(line[1]);
			
			int [] times = new int [b];
			line = in.readLine().split(" ");
			int biggest = 0;
			int bI = 0;
			for(int j = 0; j < b; ++j){
				times[j] = Integer.parseInt(line[j]);
				if(times[j]>=biggest){
					biggest=times[j];
					bI = j;
				}
			}
			
			int myBarber = -1;
			
			int m = 1;
			if(n <= b)myBarber = n;
			else{
				n -= b;
				ArrayList<Integer>pattern = new ArrayList<>(b);
				int gcf = 1;
				for(int j = 0; j < b; ++j){
					gcf *= times[j];
				}
				for(int j = 2; j < gcf; ++j){
					boolean lower = true;
					for(int k = 0; k < b; ++k){
						if(j%times[k]!=0){
							lower = false;
							break;
						}
					}
					if(lower){
						gcf = j;
						break;
					}
				}
				
				for(int j = 1; j <= gcf; ++j){
					for(int k = 0; k < b; ++k){
						if(j%times[k]==0){
							pattern.add(k);
						}
					}
				}
				if(n < pattern.size()){
					myBarber = pattern.get(n-1)+1;
				}
				else{
					int pos = n%(pattern.size());
					if(pos == 0)pos= pattern.size();
					--pos;
					myBarber = pattern.get(pos)+1;
				}
			}
			
			file.println("Case #"+(i+1)+": "+myBarber);
		}
		file.close();
		in.close();
	}
}; 