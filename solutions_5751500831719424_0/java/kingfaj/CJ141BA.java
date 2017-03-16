package cj141ba;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class CJ141BA {

    static BufferedReader inp;
    static PrintWriter out;
    public static void main(String[] args) throws FileNotFoundException, IOException {
        inp = new BufferedReader(new FileReader("C:\\Users\\Faheem\\Desktop\\ina.txt"));
        int t = Integer.parseInt(inp.readLine());
        String mi;
        String[] k = null;
        PrintWriter outp = new PrintWriter(new FileWriter("C:\\Users\\Faheem\\Desktop\\Output.txt"));

        for (int i = 0; i < t; i++) {
            outp.print("Case #" + (i + 1) + ": ");
            mi = inp.readLine();
            int n = Integer.parseInt(mi);
            String[] strs = new String[n];
            String[] strs1 = new String[n];
            int[] lens = new int[n];
            for(int j = 0;j<n;j++){
                strs[j] = inp.readLine();
                strs1[j] = strs[j];
                lens[j] = strs[j].length();
                char[] vals = strs[j].toCharArray();
                String temp = ""+vals[0];
                for(int l=1;l<vals.length;l++){
                    if(vals[l]!=vals[l-1])
                        temp +=vals[l];
                }
                strs[j] = temp;
            }
            Arrays.sort(strs);
            boolean st = true;
            for(int j=1;j<n;j++){
                if(!strs[j].equals(strs[j-1])){
                    st=false;
                    break;
                }
            }
            int ans = 0;
            //int tempans = 0;
            if(st){                
//                for(int j=0;j<n;j++){
//                    tempans = 0;
//                    for(int l=0;l<n;l++){
//                        tempans+=lens[l]-lens[j];
//                    }
//                    if(ans==-1 || tempans<ans)
//                        ans = tempans;
//                }                
                int[][] counts = new int[n][strs[0].length()];
                for(int j=0;j<n;j++){
                    int tc=0;
                    for(int l=1;l<strs1[j].length();l++){
                        if(strs1[j].charAt(l)==strs1[j].charAt(l-1)){
                            counts[j][tc]++;
                        }
                        else{
                            tc++;
                        }
                    }
                }
                for(int j=0;j<strs[0].length();j++){
                    int[] nums = new int[n];
                    for(int l=0;l<n;l++){
                        nums[l] = counts[l][j];
                    }
                    Arrays.sort(nums);
                    int max = nums[n-1];
                    int tempAns = -1;
                    int tta = 0;
                    for(int y=0;y<max+1;y++){
                        tta = 0;
                        for(int x=0;x<n;x++){
                            tta+=Math.abs(nums[x]-y);
                        }
                        if(tempAns==-1 || tempAns>tta){
                            tempAns = tta;
                        }
                    }
                    ans+=tempAns;
                }          
                
                
                outp.println(ans);
                //System.out.println(ans);
            }
            else{
                String ans1 = "Fegla Won";
                outp.println(ans1);
                //System.out.println(ans1); 
            }
        }
        outp.close();
    }
}
