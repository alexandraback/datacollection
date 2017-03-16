package cj16;

import java.io.*;
import java.util.LinkedList;

/**
 * Created by AmesingFlank on 5/8/16.
 */
public class fire {

    public static void main2(String[] args){
        System.out.println(solveOne("3","2 3 1"));
    }

    public static void main(String[] args){
        String raw[] = readFile("/Users/AmesingFlank/Downloads/qtest.in");
        int cases=Integer.valueOf(raw[0]);
        String[] ans=new String[cases];
        for (int i = 0; i < cases; i++) {
            ans[i]=String.valueOf(solveOne(raw[i*2+1],raw[i*2+2]));
        }
        writeFile("/Users/AmesingFlank/cj2016/Q1test.txt",ans);


    }

    public static String solveOne(String Nin,String Senatorsin) {
        String[] alphabet={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
        int N=Integer.valueOf(Nin);
        int [] Senators=getarr(Senatorsin);
        String ans="";
        while (sum(Senators)!=0){
            if (sum(Senators)!=3){
                boolean dou=false;
                int Max=-1;
                int index0=-1;
                int index1=-1;
                for (int i = 0; i <N ; i++) {
                    if(Senators[i]>Max){
                        Max=Senators[i];
                        dou=false;
                        index1=-1;
                        index0=i;
                    }
                    if(Senators[i]==Max){
                        dou=true;
                        index1=i;
                    }
                }
                if(dou){
                    ans+=alphabet[index0]+alphabet[index1]+" ";
                    Senators[index0]--;
                    Senators[index1]--;
                }
                else {
                    ans+=alphabet[index0]+alphabet[index0]+" ";
                    Senators[index0]-=2;
                }
            }
            else {
                for (int i = 0; i <N ; i++) {
                    if (Senators[i]>0){
                        ans+=alphabet[i]+" ";
                        Senators[i]--;
                        break;
                    }
                }
            }

        }

        String str="";
        for (int i = 0; i < ans.length()-1; i++) {
            str+=ans.charAt(i);
        }
        return str;


    }


    public static int sum(int[] ints){
        int sum=0;
        for (int i:
             ints) {
            sum+=i;
        }
        return sum;
    }


    public static int[] getarr(String numberString){
        String[] numbers = numberString.split("\\s+");
        int[] ints = new int[numbers.length];
        for (int i = 0; i < ints.length; i++)
            ints[i] = Integer.parseInt(numbers[i]);

        return  ints;
    }

    public static String[] readFile(String path){
        LinkedList<String> s=new LinkedList<String>();


        try {
            String encoding="GBK";
            File file=new File(path);
            if(file.isFile() && file.exists()){ //判断文件是否存在
                InputStreamReader read = new InputStreamReader(
                        new FileInputStream(file),encoding);//考虑到编码格式
                BufferedReader bufferedReader = new BufferedReader(read);
                String lineTxt = null;
                while((lineTxt = bufferedReader.readLine()) != null){
                    s.add(lineTxt);
                }
                read.close();
            }
        } catch (Exception e) {
            System.out.println("读取文件内容出错");
            e.printStackTrace();
        }

        String[] ans=new String[s.size()];
        for (int i = 0; i < s.size(); i++) {
            ans[i]=s.get(i);
        }
        return ans;
    }

    public static void writeFile(String path,String[] res){
        try {

            int trial=res.length;
            File file = new File(path);
            BufferedWriter ow = new BufferedWriter(new FileWriter(file));

            for(int i=0;i<trial;i++){

                String temp="Case "+"#"+String.valueOf(i+1)+": "+res[i];
                System.out.println(temp);
                ow.write(temp);

                ow.newLine();
            }

            ow.close();
            System.out.println("Finished Writing");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
