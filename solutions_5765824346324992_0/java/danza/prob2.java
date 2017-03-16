import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Arrays;


public class prob2 {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		/*int Blen = 2;
		int Nlen = 4;
		int[] B = {10,5};*/
		
		/*int Blen = 3;
		int Nlen = 12;
		int[] B = {7,7,7};*/
		System.out.println("lcm:"+lcm(new int[] {4,3,8,16}));
		int Blen = 3;
		int Nlen = 8;
		int[] B = {4,2,1};
		int lcm = lcm(B);
		int c = getCount(lcm,B);
		System.out.println("c:"+c+" "+((Nlen%c))+" "+12%3);
		int t;
		if(Nlen%c==0)
			t = getTime(Blen,c,B);
		else
			t = getTime(Blen,Nlen%c,B);
		System.out.println(t);
		
		try (Writer writer = new BufferedWriter(new OutputStreamWriter(
	              new FileOutputStream("/home/danza/Downloads/output2.txt"), "utf-8"))) {
	  // writer.write("something");
		
		int j=1;
		BufferedReader br = new BufferedReader(new FileReader("/home/danza/Downloads/B-small-attempt1 (1).in"));
	    try {
	        StringBuilder sb = new StringBuilder();
	        String line = br.readLine();
	        while (line != null) {
	            sb.append(line);
	            sb.append(System.lineSeparator());
	            String line1 = br.readLine();
	            Blen = Integer.parseInt(line1.split(" ")[0]);
	            Nlen = Integer.parseInt(line1.split(" ")[1]);

	            line = br.readLine();
	            int[] arr = new int[Blen];
	            String[] sarray = line.split(" ");
	            for(int i=0;i<Blen;i++){
	            	arr[i] = Integer.parseInt(sarray[i]);
	            }
	            
	            lcm = lcm(arr);
	            c = getCount(lcm,arr);
	            if(Nlen%c==0)
	    			t = getTime(Blen,c,arr);
	    		else
	    			t = getTime(Blen,Nlen%c,arr);
	            
	            //int min = getTime(Blen,Nlen,arr);
	    		writer.write("Case #"+(j++)+": "+t+"\n");
	        }
	        String everything = sb.toString();
	    }catch(Exception e){
	    	
	    }
	    finally {
	        br.close();
	    }
		}
	}

	private static int getTime(int blen, int nlen, int[] b) {
		int tar[] = new int[blen];
		int cur=1;
		boolean done = false;
		for(int i=0;i<nlen;i++){
			//System.out.println("\nnew i:"+i+Arrays.toString(tar));
			done = false;
			for(int j=0;j<blen;j++){
				if(tar[j]==0 && !done){
					done = true;
					tar[j] = b[j];
					cur =j;
					//System.out.println("done:"+Arrays.toString(tar));
					
				} /*else if(tar[j]>0){
					tar[j]--;
					//System.out.println("--");
				}*/
				//System.out.println(j+":"+Arrays.toString(tar));
			}
			//System.out.println(i);
			if(!done){
				//System.out.println("not done:"+Arrays.toString(tar));
				int min = Integer.MAX_VALUE;
				for(int j=0;j<blen;j++){
					if(min>tar[j])
						min = tar[j];
				}
				//System.out.println("min:"+min);

				for(int j=0;j<blen;j++){
					tar[j] -=min;
				}
				i--;
			}
			//System.out.println("final:"+Arrays.toString(tar));
		}
		return cur+1;
	}
	
	private static int getCount(int lcm, int[] b) {
		int ans=0;
		for(int i=0;i<b.length;i++){
			ans+=lcm/b[i];
		}
		
		return ans;
	}
	private static boolean allzero(int[] tar) {
		for(int i : tar)
			if(i!=0)
				return false;
		return true;
	}

	private static int lcm(int[] input)
	{
	    int result = input[0];
	    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
	    return result;
	}
	private static int lcm(int a, int b)
	{
	    return a * (b / gcd(a, b));
	}
	private static int gcd(int a, int b)
	{
	    while (b > 0)
	    {
	        int temp = b;
	        b = a % b; 
	        a = temp;
	    }
	    return a;
	}

}
