/******************************************************************
 * Compilation:  javac In.java
 * Execution     java In
 * 
 * Reads in data of various types from standard input, files, and URLs.
 *
 *****************************************************************/

import java.io.File;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.InputMismatchException;

/**
 * <i>Input</i>. This calss provides methods for reading strings and numbers from file input
 * @author Jing Cui
 */
public class In {

    private Scanner scanner;

    private static final String CHARSET_NAME = "UTF-8";
    private static final Locale LOCALE = Locale.US;
    private static final Pattern WHITESPACE_PATTERN
	= Pattern.compile("\\p{javaWhitespace}+");
    private static final Pattern EMPTY_PATTERN
	= Pattern.compile("");
    /**
     * Create an input stream from a filename
     */
    public In(String s) {
	try {
	    File file = new File(s);
	    if (file.exists()) {
		scanner = new Scanner(file, CHARSET_NAME);
		scanner.useLocale(LOCALE);
		return;
	    }
	}
	catch (IOException ioe) {
	    System.err.println("Could not open " + s);
	}
    }
    
    /**
     * Does the input have a next line? Use this to know whether the next call to 
     * {@link #readLine()} will succeed.
     * <p> Functionally equivalent to {@link #hasNextChar()}.
     */
    public boolean hasNextLine() {
	return scanner.hasNextLine();
    }

    /**
     * Is the input empty (including whitespace)? Use this to know
     * whether the next call to {@link #readChar()} will succeed. <p> Functionally
     * equivalent to {@link #hasNextLine()}.
     */
    public boolean hasNextChar() {
        scanner.useDelimiter(EMPTY_PATTERN);
        boolean result = scanner.hasNext();
        scanner.useDelimiter(WHITESPACE_PATTERN);
        return result;
    }
    
    /**
     * Read and return the next line.
     */
    public String readLine() {
	String line;
	try                 { line = scanner.nextLine(); }
	catch (Exception e) { line = null;               }
	return line;
    }

    /**
     * Read and retrun the next character.
     */
    public char readChar() {
	scanner.useDelimiter(EMPTY_PATTERN);
	String ch = scanner.next();
	assert (ch.length() == 1) : "Internal (Std)In.readChar() error!"
	    + " Please cnatact the authors.";
	scanner.useDelimiter(WHITESPACE_PATTERN);
	return ch.charAt(0);
    }

    /**
     * Read and return the next string.
     */
    public String readString() {
        return scanner.next();
    }

    /**
     * Read and return the next int.
     */
    public int readInt() {
        return scanner.nextInt();
    }

    /**
     * Read and return the next double.
     */
    public double readDouble() {
        return scanner.nextDouble();
    }

    /**
     * Read and return the next float.
     */
    public float readFloat() {
        return scanner.nextFloat();
    }

    /**
     * Read and return the next long.
     */
    public long readLong() {
        return scanner.nextLong();
    }

    /**
     * Read and return the next short.
     */
    public short readShort() {
        return scanner.nextShort();
    }

    /**
     * Read and return the next byte.
     */
    public byte readByte() {
        return scanner.nextByte();
    }

    /**
     * Read and return the next boolean, allowing case-insensitive
     * "true" or "1" for true, and "false" or "0" for false.
     */
    public boolean readBoolean() {
        String s = readString();
        if (s.equalsIgnoreCase("true"))  return true;
        if (s.equalsIgnoreCase("false")) return false;
        if (s.equals("1"))               return true;
        if (s.equals("0"))               return false;
        throw new InputMismatchException();
    }

    /**
     * Close the input stream.
     */
    public void close() {
	scanner.close();
    }

    /**
     * Test
     */
    public static void main(String[] args) {
	In in;
	String filename = "Test_In.txt";
	in = new In(filename);
	System.out.println(in.readInt());
	System.out.println(in.readDouble());	
	System.out.println(in.readString());
	System.out.println(in.readChar());
	System.out.println(in.readChar());
	in.close();
    }
}