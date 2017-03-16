package coogle.code.jam;

import java.io.*;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: Administrator
 * Date: 03.05.14
 * Time: 19:05
 * To change this template use File | Settings | File Templates.
 */
public class Repeater {

    public static void main(String[] args){
        BufferedReader buffer = null;
        BufferedWriter bw = null;

        try{
            buffer = new BufferedReader(new FileReader("D:\\jam\\A-small-attempt1.in"));
            File file = new File("D:\\jam\\A-small-attempt1.out");
            if (!file.exists()) {
                file.createNewFile();
            }

            FileWriter fw = new FileWriter(file.getAbsoluteFile());
            bw = new BufferedWriter(fw);

            String line = buffer.readLine();
            if(line != null ){
                Integer caseCount = Integer.parseInt(line);
                for(int i=1; i<= caseCount; i++ ){
                    System.out.println("-------CASR="+i+"-------------------------");
                    StringBuffer output = new StringBuffer();
                    line = buffer.readLine();
                    Integer N = Integer.parseInt(line);
                    String[] inputAr = new String[N];
                    String[] uniqueAr = new String[N];
                    List[] list = new List[N];
                    int[][] listVal = new int[N][110];
                    for( int j=0; j<N; j++ ){
                        line = buffer.readLine();
                        inputAr[j] = line;
                        char temp = '0';
                        int tempCount = 0;
                        StringBuffer strBuff = new StringBuffer();
                        int t = 0;
                        for(int z=0; z<line.length(); z++){
                            if(line.charAt(z)!=temp ){
                                if(temp != '0'){
                                    strBuff.append(temp);
                                    listVal[j][t] = tempCount;
                                    t++;
                                }
                                temp = line.charAt(z);
                                tempCount=1;
                            }
                            else{
                                tempCount++;
                            }
                        }

                        strBuff.append(temp);
                        listVal[j][t] = tempCount;


                        uniqueAr[j] = strBuff.toString();
                    }


                    boolean isVariant = true;
                    System.out.println("uniqueAr="+Arrays.toString(uniqueAr));
                    for(int j=1; j<N; j++){
                        if(!uniqueAr[0].equals(uniqueAr[j])){
                            isVariant = false;
                        }
                    }

                    int totalChanges = 0;
                    if(isVariant){
                        System.out.println("array"+Arrays.deepToString(listVal));
                        int val = uniqueAr[0].length();
                        for(int z=0; z<val; z++){
                            int temp = 0;
                            for(int ii=0; ii<N; ii++){
                                temp += listVal[ii][z];
                            }

                            Double xx = Math.ceil((double)temp / N);
                            int cl = xx.intValue();
                            int c2 = temp / N;
                            System.out.println("cl="+cl+" c2="+c2);
                            int totalC1 = 0;
                            int totalC2 = 0;
                            for(int ii=0; ii<N; ii++){
                                totalC1+=Math.abs(listVal[ii][z]-cl);
                                totalC2+=Math.abs(listVal[ii][z]-c2);
                            }

                            System.out.println("totalC1="+totalC1+" totalC2="+totalC2);
                            if(totalC1>totalC2) totalChanges+= totalC2;
                            else totalChanges+= totalC1;

                        }

                    }


                    boolean isResult;
                    isResult = true;
                    int maxNodesResult = totalChanges;

                    if(isVariant){
                        output.append("Case #"+i+": "+maxNodesResult+"\n");
                    }
                    else{
                        output.append("Case #"+i+": Fegla Won\n");
                    }
                    bw.write(output.toString());
                }

            }
        }
        catch(IOException e){
            e.printStackTrace();
        }
        finally {
            try {

                if (buffer != null) buffer.close();
                if (bw != null) bw.close();

            } catch (IOException ex) {
                ex.printStackTrace();
            }


        }

    }

}
