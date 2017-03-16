
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class SenateEvacuation {

	static PrintWriter writer;
	
	public static int Max(int sena[], int limit) {
		int min = -1;
		int index = -1;
		int count = 0;
		int another = -1;
		for(int i = 0; i < limit; ++i) {
			if(sena[i] > 0 &&(min == -1 || sena[i] > min)) {
				min = sena[i];
				index = i;
				count = 1;
				another = -1;
			}
			else if(sena[i] > 0 &&(min == -1 || sena[i] == min)){
				count ++;
				another = i;
			}
		}
		
		if(count == 2 && another > -1) {
			index += another * 100;
		}
		return index;
	}
	
	public static void main(String[] args) throws IOException {
		
		writer = new PrintWriter("out.txt");
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader("A-large (1).in"));
			String line = br.readLine();
		    int Num = Integer.parseInt(line);
		    for(int i = 0; i < Num; ++i) {
		    	line = br.readLine();
		    	int party = Integer.parseInt(line);
		    	line = br.readLine();
		    	String bufs[] = line.split(" ");
		    	int[] sena = new int[30];
		    	for(int j = 0; j < party; ++j){
		    		sena[j] = Integer.parseInt(bufs[j]);
		    	}
		    	
		    	String output = "";
		    	
		    	while(true) {
		    		int index =  Max(sena, party);
		    		if(index == -1) {
		    			break;
		    		}
		    		if(index < 30) { 
			    		sena[index] --;
			    		char a = (char) (index + 'A');
			    		output += (a + " ");
		    		}
		    		else {
		    			int another = index / 100;
		    			index = index % 100;

			    		sena[index] --;
			    		char a = (char) (index + 'A');
			    		char s = (char) (another + 'A');
			    		output += a;
			    		output += (s+ " ");
			    		sena[another] --;
		    		}
		    	}
		    	writer.println("Case #" + (i + 1) + ": " + output);
		    }
		} finally {
		    br.close();
			writer.close();
		}
	}
	
}
