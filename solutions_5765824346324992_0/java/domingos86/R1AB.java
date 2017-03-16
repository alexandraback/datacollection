package codejam.CJ2015.R1A;

import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class R1AB {
	
	private static class Barber implements Comparable<R1AB.Barber>{
		private final int id;
		private final int defaultTime;
		private final double reciprocal;
		private long nextVacancy;
		
		public Barber(int id, int defaultTime){
			this.id = id;
			this.defaultTime = defaultTime;
			reciprocal = 1d/defaultTime;
			nextVacancy = 0;
		}
		
		@Override
		public int compareTo(Barber o) {
			if(this.nextVacancy != o.nextVacancy) return (this.nextVacancy - o.nextVacancy>0)? 1: -1;
			else return this.id - o.id;
		}
		
		public int getId(){
			return id;
		}
		
		public int getDefaultTime(){
			return defaultTime;
		}
		
		public double getReciprocal(){
			return reciprocal;
		}
		
		public long numOfPatrons(long t){
			return t/defaultTime;
		}
		
		public void nextPatron(){
			nextVacancy+=defaultTime;
		}
		
		public void addPatrons(long patrons){
			nextVacancy+=defaultTime*patrons;
		}
		
	}
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i=1; i<=t; i++){
			int b = in.nextInt();
			long n = in.nextLong();
			int shortestTime = 100000;
			
			ArrayList<Barber> m = new ArrayList<>(b);
			for(int j = 0; j<b; j++){
				int timeRead = in.nextInt();
				m.add(new Barber(j+1,timeRead));
				if(shortestTime > timeRead) shortestTime = timeRead;
			}
			
			m.sort((a,c)->((a.getDefaultTime() > c.getDefaultTime())?-1:1));	
			
			double speed = 0;
			
			for(int j = 0; j<b; j++){
				speed += m.get(j).getReciprocal();
			}
			long finalTime = (long) Math.floor(((double) (n-b))/speed);
			long patronsServed = n;
			while(patronsServed >=n){
				patronsServed = 0;
				for(int j = 0; j<b; j++) patronsServed += m.get(j).numOfPatrons(finalTime);
				if(patronsServed >=n) finalTime -= b*shortestTime;
			}
			
			PriorityQueue<Barber> queue = new PriorityQueue<>(b);
			for(int j = 0; j<b; j++){
				m.get(j).addPatrons(m.get(j).numOfPatrons(finalTime));
				queue.add(m.get(j));
			}
			
			Barber head = null;
			
			while(patronsServed < n-1){
				head = queue.poll();
				head.nextPatron();
				queue.offer(head);
				patronsServed++;
			}
			
			
			System.out.print("Case #" + i + ": ");
			
			System.out.print(queue.peek().getId());
			System.out.println();
		}
		
		in.close();
	}
}
