import java.util.Arrays;
import java.util.*;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.math.BigDecimal;

public class Main {
	
	public static void main(String[] args) {
		init();
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		for (int i = 0; i < T; ++i) {
			int N = scanner.nextInt();
			PriorityQueue<Node> que = new PriorityQueue<>();
			for (int j = 0; j < N; ++j) {
				int counter = scanner.nextInt();
				que.add(new Node(j, counter));
			}
			/*for (int j = 0; j < N; ++j) {
				System.out.print(que.peek().counter + " ");
				que.poll();
			}
			System.out.println();*/
			System.out.printf("Case #%d:", i + 1);
			while (!que.isEmpty()) {
				if (que.size() == 1) {
					Node node = que.poll();
					System.out.printf(" %c", node.index + 'A');
					node.counter -= 1;
					if (node.counter > 0) {
						que.add(node);
					}
				} else {
					Node n1 = que.poll();
					Node n2 = que.poll();
					boolean flag = que.size() == 1 && n1.counter == 1 && n2.counter == 1;
					flag = flag && que.peek().counter == 1;
					if (n1.counter == n2.counter && !flag) {
						--n1.counter;
						--n2.counter;
						System.out.printf(" %c%c", n1.index + 'A', n2.index + 'A');
					} else {
						--n1.counter;
						System.out.printf(" %c", n1.index + 'A');
					}
					if (n1.counter > 0) {
						que.add(n1);
					}
					if (n2.counter > 0) {
						que.add(n2);
					}
				}
			}
			System.out.println();
		}
	}
	
	
	private static class Node implements Comparable<Node> {
		int index;
		int counter;
		Node(int i, int c) {
			index = i;
			counter = c;
		}
		public int compareTo(Node o) {
			Node obj = (Node)o;
			return obj.counter - counter;
		}
		
	}

	
	
	
	
	
	
	
	
	
	public static void init() {
		FileInputStream fis = null;
		try {
			fis = new FileInputStream("/Users/zxj/Documents/workspace/Algorithm/src/test.in");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}  
        System.setIn(fis); 
	}
}

