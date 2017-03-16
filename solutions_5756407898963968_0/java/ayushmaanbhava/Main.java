import java.io.*;

class Main
{
    public static void main(String args[]) throws IOException
    {
        String in = null;
        BufferedReader br = new BufferedReader(new FileReader("inp.txt"));
        int nooftest = Integer.parseInt(br.readLine());
        for(int i=0;i<nooftest;i++)
        {
            int ans1 = Integer.parseInt(br.readLine());
            String row1[] = null, row2[] = null;
            int count = 0, ans = 0;
            for(int k=1;k<=4;k++)
            {
                String temp[] = br.readLine().split(" ");
                if(k == ans1)
                    row1 = temp;
            }
            int ans2 = Integer.parseInt(br.readLine());
            for(int k=1;k<=4;k++)
            {
                String temp[] = br.readLine().split(" ");
                if(k == ans2)
                    row2 = temp;
            }
            for(int k=0;k<4;k++)
            {
                for(int l=0;l<4;l++)
                {
                    if(row1[k].equals(row2[l]))
                    {
                        ans = Integer.parseInt(row1[k]);
                        count++;
                    }
                }
            }
            if(count == 0)
                System.out.println("Case #"+(i+1)+": Volunteer cheated!");
            else if(count > 1)
                System.out.println("Case #"+(i+1)+": Bad magician!");
            else
                System.out.println("Case #"+(i+1)+": "+ans);
        }
    }
}