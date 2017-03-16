import java.io.*;
import java.util.*;

public class codeJamB
{
	public static void main(String[] args) throws IOException
	{
	//barbers
		File f = new File("test.txt");
		Scanner in = new Scanner(f);
		PrintWriter out = new PrintWriter(new FileWriter("testout.txt"));
		int numCases = in.nextInt();
		in.nextLine();

		//problem specific: we do binary search on the time elapsed. At a specific time period, how many people had their hair cut? 		
		long position;
		int numBarbers;
		int[] timeRequired;
		
		for(int i = 0; i < numCases; i++){
			numBarbers = in.nextInt();
			position = in.nextLong();
			System.out.println(numBarbers + " " + position);
			//for each barber
			//in.nextLine();
			timeRequired = new int[ numBarbers ];
			for(int j = 0; j < numBarbers; j++ ){	//for each barber, store time required
				timeRequired[j] = in.nextInt();
				System.out.println("a time " + timeRequired[j]);
			}
			
			//find out how many haircuts at least started at 50 minutes. 
			long total = 0;
			long time = 0;
			long answer = -1;
			while(true){ //double the time required until satisfies
				total = 0;
				for(int j = 0; j < numBarbers; j++ ){ //for each barber
					total += time / timeRequired[j] + 1; //rounds down.
				}			
				if (total < position ){ //take more time. 
					if (time == 0){
						time = 5;
					} else {
						time *= 2;
					}
				} else { //exit
					break;
				}
			}
			
			if (time == 0){ //done first thing
				answer = position;
			}
			//now binary search for the right time
			long high = time;
			long low = time / 2;
			int nthAvail = 0;
			while ( high >= low ){
				long mid = (high + low) / 2;
				total = 0;
				time = mid;
				for(int j = 0; j < numBarbers; j++ ){ //for each barber
					total += time / timeRequired[j] + 1; //rounds down.
				}			
				if (total < position ){ //need more time
					low = mid + 1;
				} else if ( total > position ){ //less time
					high = mid - 1;
				} else { //got it!
					time = mid;
					break;
				}
			} //now see how low we can go. 
			long prevTime, curTime;
			curTime = -1;
			prevTime = -1;
			if ( total >= position ){ //find first instance in which it's less than
				while( total >= position ){ 
					time --;
					total = 0;
					for(int j = 0; j < numBarbers; j++ ){ //for each barber
						total += time / timeRequired[j] + 1; //rounds down.
					}			
				}
				prevTime = time;
				curTime = time + 1;
			} else if ( total < position ){
				while( total < position ){ 
					time ++;
					total = 0;
					for(int j = 0; j < numBarbers; j++ ){ //for each barber
						total += time / timeRequired[j] + 1; //rounds down.
					}			
				}
				prevTime = time - 1;
				curTime = time;			
			}
			//see difference
			long difff = 0;
			for(int j = 0; j < numBarbers; j++ ){ //for each barber
				//difff += curTime / timeRequired[j] + 1; //rounds down.
				difff += prevTime / timeRequired[j] + 1;
			}		
			//answer = time;
			
			//find which barbers are available
			difff = position - difff;
			ArrayList<Integer> avails = new ArrayList<Integer>();
			
			for(int j = 0; j < numBarbers; j++ ){ //see if hey are availbale at current time
				if ( curTime % timeRequired[j] == 0){ //jth barber is free
					avails.add( j + 1 );
				}
			}
			answer = avails.get( (int) difff - 1);
			//out.format("Case #%d: %s\n", i + 1, total + " after this much time " + curTime + " and answer is " + answer + " and dif is " + difff);			
			out.format("Case #%d: %s\n", i + 1, answer);			
		}

		out.close();
	}
}
