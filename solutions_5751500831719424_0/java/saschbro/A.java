package oneb;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class A
{
    private static final String PATH_HOME = "y:/codejam/repository/projects/2014";

    private static final String PATH_INPUT = PATH_HOME + "/input/A-small-attempt2.in";

    private static final String PATH_OUTPUT = PATH_HOME + "/output/A-small-attempt2.out";

    private static List<String> readInput() throws IOException
    {
        List<String> tokens = new ArrayList<>();

        try ( BufferedReader reader = Files.newBufferedReader( Paths.get( PATH_INPUT ), Charset.forName( "UTF-8" ) ) )
        {
            String line = null;
            while ( ( line = reader.readLine() ) != null )
            {
                for ( String token : line.split( "\\s" ) )
                {
                    if ( !token.isEmpty() )
                    {
                        tokens.add( token );
                    }
                }
            }
        }

        return tokens;
    }

    private static void writeOutput( List<String> results ) throws IOException
    {
        try ( BufferedWriter writer = Files.newBufferedWriter( Paths.get( PATH_OUTPUT ), Charset.forName( "UTF-8" ) ) )
        {
            for ( int i = 0; i < results.size(); i++ )
            {
                writer.write( "Case #" + ( i + 1 ) + ": " + results.get( i ) );
                if ( i < results.size() - 1 )
                {
                    writer.newLine();
                }
            }
        }
    }

    public static void main( String[] args ) throws IOException
    {
        List<String> tokens = readInput();

        int cases = Integer.valueOf( tokens.remove( 0 ) );
        cases:
        for ( int i = 0; i < cases; i++ )
        {
            System.out.println( "Case: " + i );

            List<Word> words = new ArrayList<>();

            int lines = Integer.valueOf( tokens.remove( 0 ) );
            for ( int j = 0; j < lines; j++ )
            {
                words.add( new Word( tokens.remove( 0 ) ) );
            }

            Word word = words.get( 0 );
            for ( int j = 0; j < words.size(); j++ )
            {
                Word wordToCompare = words.get( j );
                if ( !word.chars.equals( wordToCompare.chars ) )
                {
                    tokens.add( "Fegla Won" );
                    continue cases;
                }
            }

            List<Integer> mins = new ArrayList<>();
            List<Integer> maxs = new ArrayList<>();

            for ( int j = 0; j < word.nums.size(); j++ )
            {
                mins.add( word.nums.get( j ) );
                maxs.add( word.nums.get( j ) );
            }

            for ( int j = 1; j < words.size(); j++ )
            {
                Word wordToCompare = words.get( j );
                for ( int k = 0; k < word.nums.size(); k++ )
                {
                    int value = wordToCompare.nums.get( k );
                    if ( mins.get( k ) > value )
                    {
                        mins.set( k, value );
                    }
                    else if ( maxs.get( k ) < value )
                    {
                        maxs.set( k, value );
                    }
                }
            }

            int changes = 0;
            while ( !mins.equals( maxs ) )
            {
                System.out.println( "mins: " + mins );
                System.out.println( "maxs: " + maxs );

                for ( int j = 0; j < mins.size(); j++ )
                {
                    if ( !mins.get( j ).equals( maxs.get( j ) ) )
                    {
                        int numMin = 0;
                        int numMax = 0;
                        for ( int k = 0; k < words.size(); k++ )
                        {
                            if ( words.get( k ).nums.get( j ).equals( mins.get( j ) ) )
                            {
                                numMin++;
                            }
                            else if ( words.get( k ).nums.get( j ).equals( maxs.get( j ) ) )
                            {
                                numMax++;
                            }
                        }

                        if ( numMax < numMin )
                        {
                            changes += numMax;
                            for ( int k = 0; k < words.size(); k++ )
                            {
                                if ( words.get( k ).nums.get( j ).equals( maxs.get( j ) ) )
                                {
                                    words.get( k ).nums.set( j, maxs.get( j ) - 1 );
                                }
                            }
                            maxs.set( j, maxs.get( j ) - 1 );
                        }
                        else
                        {
                            changes += numMin;
                            for ( int k = 0; k < words.size(); k++ )
                            {
                                if ( words.get( k ).nums.get( j ).equals( mins.get( j ) ) )
                                {
                                    words.get( k ).nums.set( j, mins.get( j ) + 1 );
                                }
                            }
                            mins.set( j, mins.get( j ) + 1 );
                        }
                    }
                }
            }

            tokens.add( "" + changes );
        }

        writeOutput( tokens );
    }

    private static class Word
    {
        String word;
        List<Character> chars = new ArrayList<>();
        List<Integer> nums = new ArrayList<>();

        public Word( String word )
        {
            this.word = word;

            char c = word.charAt( 0 );
            chars.add( c );
            int n = 1;
            for ( int i = 1; i < word.length(); i++ )
            {
                if ( c == word.charAt( i ) )
                {
                    n++;
                    continue;
                }
                chars.add( c );
                nums.add( n );

                c = word.charAt( i );
                n = 1;
            }

            chars.add( c );
            nums.add( n );
        }
    }
}
