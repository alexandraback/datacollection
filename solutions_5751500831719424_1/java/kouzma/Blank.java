package com.nastya.code_jam;

import java.io.BufferedReader; import java.io.FileReader; import java.io.IOException; import java.io.PrintWriter;

public class Blank {

public static void main(String args[]) {
	
	try {
		BufferedReader in = new BufferedReader(new FileReader("D:\\in.txt"));
		PrintWriter out = new PrintWriter("D:\\out.txt");
		
		int amount = Integer.parseInt(in.readLine());
		for (int k = 0; k < amount; k++) {
			String[] arrDim = in.readLine().split(" ");
			out.println("Case #" + (k + 1) + ": " + execute(
					Integer.parseInt(arrDim[0]),
					Integer.parseInt(arrDim[1]),
					Integer.parseInt(arrDim[2])
			));
		}
		
		in.close();
		out.close();
	} catch (IOException e) {
		e.printStackTrace();
	}
	//System.out.println("Конец!");
}
private static String execute(int a, int b, int k) {
	int count = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if((i & j) < k) {
				count++;
			}
				
		}
	}
	return "" + count;
}
}