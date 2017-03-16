package main;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Senate {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("data/A-large.in"));
			int nbCases = new Integer(br.readLine());
			
			for (int pb=0 ; pb<nbCases ; pb++) {
				int nbPartits = new Integer(br.readLine());
				
				int[] senate = new int[nbPartits];
				String[] split = br.readLine().split(" ");
				for (int idx=0 ; idx<nbPartits ; idx++) {
					senate[idx] = new Integer(split[idx]);
				}
				List<String> evac = evacuate (senate);
				
				System.out.print("Case #" + (pb+1) + ": ");
				for (String plan : evac)
					System.out.print(plan + ' ');
				System.out.println();
			}
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static List<String> evacuate(int[] senate) {
		List<Integer> maxs = null;
		List<String> evac = new ArrayList<>();
		
		while ((maxs = getMaxs (senate)) != null) {
			String val = "" + (char)('A' + maxs.get(0));
			senate[maxs.get(0)]--;
			if (maxs.size() % 2 == 0) {
				val += (char)('A' + maxs.get(1));
				senate[maxs.get(1)]--;
			}
			evac.add(val);
		}
		
		return evac;
	}

	private static List<Integer> getMaxs(int[] senate) {
		List<Integer> maxs = new ArrayList<>();
		int val = 0;
		
		for (int idx=0 ; idx < senate.length ; idx++)
			if (senate[idx] > val) {
				maxs.clear();
				maxs.add(idx);
				val = senate[idx];
			} else if (senate[idx] == val)
				maxs.add(idx);
		
		if (val == 0)
			return null;
		
		return maxs;
	}
	
}

	