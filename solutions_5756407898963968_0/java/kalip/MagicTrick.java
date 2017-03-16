import java.io.*;
import java.util.*;
class MagicTrick
{
    public static void main(String args[])throws IOException
    {
        new MagicTrick().go();
    }
    public void go()throws IOException
    {
        BufferedReader bf=new BufferedReader(new FileReader("small.in"));
        PrintWriter pr=new PrintWriter(new FileWriter("out.txt"));
        int C,count,tmp,T,A,L=Integer.parseInt(bf.readLine()),op[]=new int [4];
        StringTokenizer st;
        for(int i=0;i<L;i++)
        {
            count=tmp=C=0;
            A=Integer.parseInt(bf.readLine());
            for(int j=0;j<4;j++)
            {
                st=new StringTokenizer(bf.readLine());
                if(j+1==A)
                {
                    for(int k=0;k<4;k++)
                        op[k]=Integer.parseInt(st.nextToken());
                }
            }
            A=Integer.parseInt(bf.readLine());
            for(int j=0;j<4;j++)
            {
                st=new StringTokenizer(bf.readLine());
                if(j+1==A)
                {
                    for(int k=0;k<4;k++)
                    {
                        tmp=Integer.parseInt(st.nextToken());
                        for(int x=0;x<4;x++)
                            if(op[x]==tmp)
                            {
                                C=tmp;
                                count++;
                            }
                    }
                }
            }
            if(count==1)
            {
                System.out.println("Case #"+(i+1)+": "+C);
                pr.println("Case #"+(i+1)+": "+C);
            }
            else if(count==0)
            {
                pr.println("Case #"+(i+1)+": Volunteer cheated!");
                System.out.println("Case #"+(i+1)+": Volunteer cheated!");
            }
            else if(count>1)
            {
                pr.println("Case #"+(i+1)+": Bad magician!");
                System.out.println("Case #"+(i+1)+": Bad magician!");
            }
            }
            bf.close();
            pr.close();
    }
}
