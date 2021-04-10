import java.util.Scanner;
import java.math.BigInteger;

class BigIntegers{
    public static void main(String[] args) {
        // System.out.println("arun");
        Scanner s = new Scanner(System.in);
        BigInteger x = s.nextBigInteger();
        // calc 3x^2 - x + 10 and 4x^3 +2x^2 - 5x + 4
        BigInteger xcube = x.multiply(x).multiply(x);
        BigInteger xsquare = x.multiply(x);
        BigInteger eq1 = BigInteger.valueOf(3).multiply(xcube).subtract(x).add(BigInteger.valueOf(10));
        BigInteger eq2 = BigInteger.valueOf(4).multiply(xcube).add(BigInteger.valueOf(2).multiply(xsquare)).subtract(BigInteger.valueOf(5).multiply(x)).add(BigInteger.valueOf(4));
        BigInteger res = eq1.add(eq2);
        System.out.println(res);
        s.close();
    }
}