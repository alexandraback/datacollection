/**
 * File Name: Main.java
 * Package Name: com.ncfxy.MyAlgorithm
 * Description： TODO 
 *
 *   ver					date			author
 * ──────────────────────────────────
 *   1.0-SNAPSHOT			2016年4月9日			Administrator
 *
 * Copyright (c) 2016, ncfxy All Rights Reserved.
 */

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeMap;

/**
 * ClassName: Main<br/>
 * Description: TODO ADD Description
 *
 * @author Administrator
 * @version 1.0-SNAPSHOT
 * @Date 2016 2016年4月9日 上午9:45:38
 */

class Temp {
	String str;
	Integer value;
}

public class Main {

	public static void main(String[] args) {

		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int t = cin.nextInt();
			for (int i = 0; i < t; i++) {
				sol(cin,i+1);
			}
		}

	}

	public static void sol(Scanner cin,int index) {
		int n;
		int p[] = new int[27];
		String str[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
				"L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W",
				"X", "Y", "Z" };
		StringBuffer stringBuffer = new StringBuffer();
		Comparator<Temp> OrderIsdn = new Comparator<Temp>() {
			public int compare(Temp o1, Temp o2) {
				// TODO Auto-generated method stub
				int numbera = o1.value;
				int numberb = o2.value;
				if (numberb > numbera) {
					return 1;
				} else if (numberb < numbera) {
					return -1;
				} else {
					return 0;
				}

			}
		};
		PriorityQueue<Temp> q = new PriorityQueue<Temp>(26, OrderIsdn);
		n = cin.nextInt();
		for (int i = 0; i < n; i++) {
			p[i] = cin.nextInt();
			Temp t = new Temp();
			t.str = str[i];
			t.value = p[i];
			q.add(t);
		}
		while (q.size() > 2) {
			Temp t = q.poll();
			stringBuffer.append(" "+t.str);
			t.value = t.value - 1;
			if (t.value > 0) {
				q.add(t);
			}
		}
		if (q.size() == 2) {
			Temp t1 = q.poll();
			Temp t2 = q.poll();
			for (int i = 0; i < t1.value; i++) {
				stringBuffer.append(" "+t1.str + t2.str);
			}
		}
		System.out.println("Case #"+index+":"+stringBuffer.toString());
	}

}
