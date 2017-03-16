
import java.util.*;
import java.io.*;

public class StringEqualize {

    public static void main(String [] args) {

	Scanner k = new Scanner(System.in).useLocale(Locale.US);
	int cases = k.nextInt();

	for(int numCase = 0; numCase < cases; numCase++) {
	    int maxLines = k.nextInt();

	    k.nextLine();
	    String [] lines = new String[maxLines];
	    for(int line = 0; line < maxLines; line++) {
		lines[line] = k.nextLine();
	    }

	    int minActions = minimumActions(lines);
	    String output = "Fegla Won";
	    if(minActions != -1)
		output = "" + minActions;

	    System.out.printf("Case #%d: %s\n", numCase+1, output);

	}
    }

    public static int minimumActions(String [] str) {

	int emptyStrings = 0;
	// If there is both an empty string and a non empty string it fails
	for(int i = 0; i < str.length; i++) {
	    if(str[i].length() == 0)
		emptyStrings++;
	}
	if(emptyStrings != 0) {
	    if(emptyStrings != str.length)
		return -1;
	    else
		return 0;
	}

	int minActions;
	
	boolean moreThanOneChar = false;
	for(String s : str)
	    moreThanOneChar = moreThanOneChar || moreThanOneChar(s);

	if (moreThanOneChar)
	    minActions = minimumActionsMoreThanOneChar(str);
	else
	    minActions = minimumActionsOneChar(str);

	return minActions;
    }

    public static String [] segment(String str) {
	    int charIndex=1;
	    for(; charIndex<str.length() && str.charAt(charIndex) == str.charAt(0); charIndex++);

	    
	    String firstStr = str.substring(0, charIndex);
	    String newStr = str.substring(charIndex, str.length());

	    return new String[] {firstStr, newStr};
    }

    public static int minimumActionsMoreThanOneChar(String [] str) {
	char firstChars = str[0].charAt(0);
	
	String [] firstStr = new String[str.length];
	String [] newStr = new String[str.length];
	for(int i=0; i<str.length; i++) {

	    if(str[i].charAt(0) != firstChars)
		return -1;

	    String [] segments = StringEqualize.segment(str[i]);
	    firstStr[i] = segments[0];
	    newStr[i] = segments[1];

	}

	int firstMinOtherActions = StringEqualize.minimumActions(firstStr);
	int minOtherActions = StringEqualize.minimumActions(newStr);
	if(minOtherActions == -1 || firstMinOtherActions == -1)
	    return -1; // Cannot be done
	    
	return  firstMinOtherActions + minOtherActions;
    }

    public static int minimumActionsOneChar(String [] str) {

	int minActions = 100000;
	
	for(int startingString = 0; startingString < str.length; startingString++) {
	    if(str[startingString].charAt(0) != str[0].charAt(0)) // Important, ensure its the same char
		return -1;

	    int minActionsToMakeAllLikeThis = 0;
	    for(int otherString = 0; otherString < str.length; otherString++) {

		minActionsToMakeAllLikeThis += Math.abs(str[startingString].length() - str[otherString].length());
		    
	    }

	    if(minActions > minActionsToMakeAllLikeThis)
		minActions = minActionsToMakeAllLikeThis;
	}

	return minActions;
    }

    public static boolean moreThanOneChar(String str) {
	for(int i=0; i<str.length(); i++) {
	    if(str.charAt(0) != str.charAt(i)) {
		return true;
	    }
	}

	return false;
    }
    
}
