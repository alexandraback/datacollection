using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Magic_Trick {
    class Program {
        static void Main(string[] args) {
            DateTime now = DateTime.Now;
            string filename = @"c:\users\jshea\desktop\A-small-attempt0.in";
			if (args.Length >= 1) {
				filename = args[0].ToString();
			}


            using (StreamReader file = new System.IO.StreamReader(filename)) {

                int cases = Int32.Parse(file.ReadLine());
                for (int c = 0; c < cases; c++) {
                    var result = "Bad magician!";
                    int question1, question2;
                    
                    try {
                        question1 = Int32.Parse(file.ReadLine());
                        for (int i = 1; i < question1; i++) file.ReadLine();
                        var possibleAnswers = file.ReadLine().Split(' ').ToList();
                        for (int i = question1; i < 4; i++) file.ReadLine();


                        question2 = Int32.Parse(file.ReadLine());
                        for (int i = 1; i < question2; i++) file.ReadLine();
                        possibleAnswers = possibleAnswers.Intersect(file.ReadLine().Split(' ')).ToList();
                        for (int i = question2; i < 4; i++) file.ReadLine();

                        switch (possibleAnswers.Count) {
                            case 0:
                                result =  "Volunteer cheated!";
                                break;
                            case 1:
                                result = possibleAnswers[0].ToString();
                                break;
                        }

                        Console.WriteLine("Case #{0}: {1}", c+1, result);
                    } catch (Exception ex) {
                        Console.Write(ex.Message);
                    }
                }
            }

        }
    }
}
