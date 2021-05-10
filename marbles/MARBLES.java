import java.math.BigInteger;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;  import java.io.IOException;
import java.io.PrintStream; 

public class MARBLES {
    public static BigInteger fact(BigInteger n,BigInteger k) {
        if (n.equals(k)) return n;
        return n.multiply(fact(n.subtract(BigInteger.valueOf(1)),k));
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        PrintStream o = new PrintStream(new File("A.txt"));
        PrintStream console = System.out;
        System.setOut(o);
        BigInteger n;
        BigInteger k;
        Scanner sc = new Scanner(System.in);
        n = sc.nextBigInteger();
        k = sc.nextBigInteger();
        BigInteger num = fact(n.subtract(BigInteger.valueOf(1)),n.subtract(k.subtract(BigInteger.valueOf(1))));
        BigInteger den = fact(k.subtract(BigInteger.valueOf(1)),BigInteger.valueOf(1));
        try {
            FileWriter myWriter = new FileWriter("filename.txt");
            System.out.println(num.divide(den));
            myWriter.close();
        }
        catch (IOException e) {
            System.out.println("An error occurred.");
        }
    }
}