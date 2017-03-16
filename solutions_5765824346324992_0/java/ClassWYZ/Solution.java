import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

import Haircut.Pair;


public class Solution {
	
	private static int gcd(int a, int b)
	{
	    while (b > 0)
	    {
	        int temp = b;
	        b = a % b; // % is remainder
	        a = temp;
	    }
	    return a;
	}
	
	private static int lcm(int a, int b)
	{
	    return a * (b / gcd(a, b));
	}

	private static int lcm(int[] input)
	{
	    int result = input[0];
	    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
	    return result;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		in.nextLine();
		for (int i = 0; i < num; ++i) {
			int barberNum = in.nextInt();
			int customer = in.nextInt();
			
			in.nextLine();
			int[] arr = new int[barberNum];
			for (int j = 0; j < barberNum; ++j) arr[j] = in.nextInt();
			int l = lcm(arr);
			//System.out.println("lcm " + l);
			int cycle = 0;
			for (int j = 0; j < barberNum; ++j) cycle += l / arr[j];
			//System.out.println("cycle " + cycle);
			customer %= cycle;
			if (customer == 0) customer += cycle;
			if (customer <= barberNum) {
				//if (customer == 0) customer = barberNum;
				System.out.println("Case #" + (i + 1) + ": " + customer);
				continue;
			}
			
			//customer += cycle;
			Queue<Pair> minHeap = new PriorityQueue<>(barberNum, new Comparator<Pair>() {
		        public int compare(Pair a, Pair b) {
		        	if (a.count < b.count) return -1;
		        	else if (a.count > b.count) return 1;
		        	else {
		        		if (a.val < b.val) return -1;
		        		else return 1;
		        	}
		        }
		    });
			
			for (int j = 0; j < barberNum; ++j) minHeap.offer(new Pair(j, arr[j]));
			for (int j = 0; j < customer - 1 - barberNum; ++j) {
				Pair tmp = minHeap.poll();
				minHeap.offer(new Pair(tmp.val, tmp.count + arr[tmp.val]));
			}
			int res = minHeap.poll().val + 1;
			
			System.out.println("Case #" + (i + 1) + ": " + res);
			in.nextLine();
		}
		in.close();

	}

}
