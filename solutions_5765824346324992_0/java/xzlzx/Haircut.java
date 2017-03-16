package code.jam.yr2015;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Hashtable;
import java.util.Scanner;

public class Haircut {
	
	public static boolean checkEqual(ArrayList<Integer> list){
		int equal = list.get(0);
		for (int x : list){
			if (x == equal)
				continue;
			else
				return false;
		}
		return true;
	}
	
	
	public static void main(String[] args) throws IOException {
		File input = new File("B-small-attempt0.in");
		Scanner sc = new Scanner(input);
		int numCases = sc.nextInt();
		for (int i = 1; i <= numCases; i++) {
			int numB = sc.nextInt();
			int myNum = sc.nextInt();
			
			ArrayList<Integer> sortedList = new ArrayList<Integer>();
			ArrayList<Integer> seq  = new ArrayList<Integer>();
			Hashtable<Integer, Integer> myHash = new Hashtable<Integer, Integer>();
			Hashtable<Integer, Integer> fixedAdd = new Hashtable<Integer, Integer>();
			
			for (int j = 1; j <= numB; j++){
				int barberTime = sc.nextInt();
				sortedList.add(barberTime);
				seq.add(j);
				myHash.put(j, barberTime);
				fixedAdd.put(j, barberTime);
			}
			
			Collections.sort(sortedList);
			
			
			
			
			while(!checkEqual(sortedList)){
				int small = new Integer(sortedList.get(0));
				while (sortedList.contains((Integer) small)){
					sortedList.remove((Integer) small);
				}
				ArrayList<Integer> smallest = new ArrayList<Integer>();
				for (int key: myHash.keySet()){					
					if (myHash.get(key).equals(small)){
						smallest.add(key);
					}
				}
				Collections.sort(smallest);
				for (int n = 0; n < smallest.size(); n++){
					int next = small + fixedAdd.get(smallest.get(n));
					sortedList.add(next);
					seq.add(smallest.get(n));
					myHash.put(smallest.get(n), next);
				}
				Collections.sort(sortedList);
			}
			
			int result;
			if (seq.size() == numB){
				int rem = myNum % numB;
				if (rem == 0)
					result = seq.get(seq.size()-1);
				else
					result = seq.get(rem-1);
			}
			else{
				int rem2 = myNum % seq.size();
				if (rem2 == 0)
					result = seq.get(seq.size()-1);
				else
					result = seq.get(rem2-1);
			}
			System.out.println("Case #"+i + ": " + result);
			
		}
	}
}
