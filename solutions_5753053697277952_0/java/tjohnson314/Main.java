
import java.util.Scanner;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Comparator;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for(int testNum = 1; testNum <= tests; testNum++)
		{
			System.out.print("Case #" + testNum + ": ");
			int numParties = sc.nextInt();
			int members[] = new int[numParties];
			for(int i = 0; i < numParties; i++)
				members[i] = sc.nextInt();
			
			int total = 0;
			PriorityQueue<Party> queue = new PriorityQueue<Party>();
			for(int i = 0; i < numParties; i++)
			{
				queue.add(new Party(i, members[i]));
				total += members[i];
			}
			
			StringBuilder toPrint = new StringBuilder();
			while(!queue.isEmpty())
			{
				//The next party has only one element
				if(total == 3)
				{
					Party p = queue.remove();
					String str = Character.toString(p.letter);
					toPrint.append(str + " ");
					p.members--;
					if(p.members > 0)
						queue.add(p);
					total--;
				}
				else
				{
					//There can't be only one party
					Party p1 = queue.remove();
					Party p2 = queue.remove();
					String str1 = Character.toString(p1.letter);
					String str2 = Character.toString(p2.letter);
					p1.members--;
					p2.members--;
					toPrint.append(str1);
					toPrint.append(str2);
					toPrint.append(" ");
					total -= 2;
					
					if(p1.members > 0)
						queue.add(p1);
					
					if(p2.members > 0)
						queue.add(p2);
				}
			}
			
			System.out.println(toPrint);
		}
	}
}

class Party implements Comparable<Party>
{
	int members;
	char letter;
	
	public Party(int i, int members)
	{
		this.members = members;
		this.letter = (char) (i + (int)'A');
	}
	
	public int compareTo(Party otherParty)
	{
		Integer i = otherParty.members;
		return i.compareTo(this.members);
	}
}
