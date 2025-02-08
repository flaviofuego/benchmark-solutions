import java.io.FileWriter;
import java.io.IOException;

public class Solution {
    
    public static boolean isPrime(int n) {
        if(n < 2) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;
        int sqrt = (int) Math.sqrt(n) + 1;
        for (int i = 3; i < sqrt; i += 2) {
            if(n % i == 0)
                return false;
        }
        return true;
    }
    
    public static long sumFirstNPrimes(int n) {
        int count = 0;
        int num = 2;
        long total = 0;
        while(count < n) {
            if(isPrime(num)) {
                total += num;
                count++;
            }
            num++;
        }
        return total;
    }
    
    public static void main(String[] args) {
        long startTime = System.nanoTime();
        long total = sumFirstNPrimes(10000);
        long endTime = System.nanoTime();
        long execTimeMs = (endTime - startTime) / 1000000;
        
        // Escribir el resultado en /output/result_java.txt
        try (FileWriter writer = new FileWriter("/output/result_java.txt")) {
            writer.write(Long.toString(total));
        } catch(IOException e) {
            e.printStackTrace();
        }
        
        // Imprimir solo el tiempo de ejecución (ms)
        System.out.println(execTimeMs);
    }
}
