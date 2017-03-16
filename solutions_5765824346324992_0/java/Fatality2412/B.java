package round_one_A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class B {

	static List<Integer> time = new ArrayList<>();
	static List<Boolean> busy = new ArrayList<>();
	static Map<List<Integer>, List<Map<List<Integer>, List<Integer>>>> knownSit;
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("C:\\Users\\Valentin\\workspace_luna\\CodeJam\\src\\B-small-attempt1(1).in"));
		System.setOut(new PrintStream(new File("C:\\Users\\Valentin\\workspace_luna\\CodeJam\\src\\test.out")));

		int t = sc.nextInt();
		for (int k = 0; k < t; k++) {
			int b = sc.nextInt();
			int n = sc.nextInt();
			List<Integer> barbers = new ArrayList<>();
			knownSit = new HashMap<>();
			busy = new ArrayList<>();
			time = new ArrayList<>();
			for (int i = 0; i < b; i++) {
				int temp = sc.nextInt();
				barbers.add(temp);
				time.add(temp);
				busy.add(false);
			}
			int next = -1;
			int firstNext = -1;
			//busy.set(getNextFree(barbers, busy), true);
			firstNext = getNextFree(barbers, busy);
			busy.set(firstNext, true);
			List<Integer> rememberTime = new ArrayList<>(time);
			List<Boolean> rememberBusy = new ArrayList<>(busy);
			boolean same = true;
			int rec = 0;
			for (int i = 1; i < n - 1; i++) {
				same = true;
				next = getNextFree(barbers, busy);
//				System.out.println(next+1);
				busy.set(next, true);
				for (int j = 0; j < b; j++) {
					same &= time.get(j) == rememberTime.get(j);
					same &= busy.get(j) == rememberBusy.get(j);
				}
				if (same) {
					rec = i;
					break;
				}
			}
			//myself
			if (rec != 0) {
				int nb = (n-1) % rec;
				for (int i = 0; i < nb; i++) {
					next = getNextFree(barbers, busy);
					busy.set(next, true);
				}
				System.out.println("Case #" + (k+1) + ": " + (next+1));
			}
			else {
				System.out.println("Case #" + (k+1) + ": " + (getNextFree(barbers, busy)+1));
			}
			
		}
	}

	private static int getNextFree(List<Integer> barbers, List<Boolean> busy) {
		for (int i = 0; i < busy.size(); i++) {
			if (!busy.get(i)) {
				return i;
			}
		}
//		System.out.println("Begin List");
//		for (Integer i : time) {
//			System.out.print(i + " ");
//		}
//		System.out.println("End List");
		
		
		List<Integer> tmp = new ArrayList<>(time);
		
			Collections.sort(tmp);
			int min = tmp.get(0);
			List<Integer> replace = new ArrayList<>();
			for (int i = 0; i < barbers.size(); i++) {
				if (time.get(i) - min == 0) {
					replace.add(barbers.get(i));
					busy.set(i, false);
				}
				else {
					replace.add(time.get(i) - min);
//					System.out.println("add " + i);
				}
			}
			time = new ArrayList<>(replace);
		for (int i = 0; i < busy.size(); i++) {
			if (!busy.get(i)) {
				return i;
			}
		}
		return -1;
		
	}

}
