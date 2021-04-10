import java.util.function.ToIntFunction;
import java.util.ArrayList; 

class pr{
    public int getCountOfOnes(int from,int to){
        ArrayList<Integer> primes = new ArrayList<Integer>();
        for (int i=from; i<=to; i++) {
            for (int j=2; j*j<=i; j++) {
                if (i%j==0) {
                    break;
                }
                if (j*j==i) {
                    primes.add(i);
                }
            }
        }
        return primes;
    }
    
    public static void main(String[] args) {
    
    }
}


