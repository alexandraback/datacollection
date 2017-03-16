import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashMap;
import java.util.Map;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
 
public class Repeat {
 
	public static void main(String[] args) {
 
		BufferedReader br = null;
		BufferedWriter bw = null;

		try {
 
			String sCurrentLine;
				
			File file = new File("out.txt");
			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			bw = new BufferedWriter(fw);
 
			br = new BufferedReader(new FileReader("input.txt"));
 
			int T = Integer.valueOf(br.readLine());
			
			for(int t=1;t<=T;t++){
				int N = Integer.valueOf(br.readLine());
				
				String array[] = new String[N];
				for(int n=0;n<N;n++){
					array[n] = br.readLine();
				}
				
				String identity="";
				boolean flag =true;
				
				for(int n=0;n<N;n++){
					String unique = "";
					char c='A';
					for(int k=0;k<array[n].length();k++){
						if(c == array[n].charAt(k)){
							continue;
						}	
						c = array[n].charAt(k);
						unique=unique+c;
					}
					if(identity.equals(""))
						identity = unique;
					else if(!identity.equals(unique)){
						flag =false;
						break;
					}
				}
				
				if(!flag){
					bw.write("Case #"+t+": Fegla Won\n");
				}
				else{
					int char_count[] = new int[identity.length()];
					
					int array2d[][] = new int[N][];
					
					for(int n=0;n<N;n++){
						array2d[n] =new int[identity.length()];
						
						char c='A';
						int h=-1;
						int count =0;
						for(int k=0;k<array[n].length();k++){
							if(c == array[n].charAt(k)){
								count++;
								continue;
							}	
							c = array[n].charAt(k);
							if(h==-1);
							else{
								array2d[n][h] = count;		
							}
							h++;
							count=1;
						}
						array2d[n][h] = count;
					}
					
					/*for(int i=0;i<N;i++){
						for(int j=0;j<identity.length();j++){
							System.out.print(array2d[i][j]+" ");
						}
						System.out.println();
					}*/
					
					int step=0;
					for(int j=0;j<identity.length();j++){
						Map<Integer,Integer> map = new HashMap<Integer,Integer>();
						for(int i=0;i<N;i++){
							if(map.containsKey(array2d[i][j])){
								int v = map.get(array2d[i][j]);
								v++;
								map.put(array2d[i][j],v);
							}
							else{
								map.put(array2d[i][j],1);
							}		
						}
						
						int key[] =  new int[map.size()];
						int value[] = new int[map.size()];
						
						int l=0;
						for (Map.Entry<Integer, Integer> entry : map.entrySet())
						{
							key[l] = entry.getKey();
							value[l] = entry.getValue();
							l++;
						}
						
						/*for(l=0;l<map.size();l++){
							System.out.println(key[l]+" : "+value[l]);
						}
						System.out.println();*/
						
						
						int result[] = new int[map.size()];
						for(l=0;l<map.size();l++){
							for(int m=0;m<map.size();m++){
								result[l] += (Math.abs(key[m]-key[l])*value[m]);
							}
						}
						
						int min = result[0];
						int minKey = key[0];
						for(l=0;l<map.size();l++){
							if(result[l]<min){
								min = result[l];
								minKey = key[l];
							}
						}
						
						step+=min;
					}
					
					bw.write("Case #"+t+": "+step+"\n");
				}
			}
		
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
				bw.close();
			} catch (Exception ex) {
				ex.printStackTrace();
			}
		}
		
	}
}