```java
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the countingValleys function below.
    static int countingValleys(int n, String s) {
        int result = 0;
        String[] sarr = s.split("");
        int[] hiking = new int[sarr.length];
        int i =0;
        for(String sa : sarr ){
            if(sa.equals("D")){
                hiking[i] = -1;
            }else{
                hiking[i] = 1;
            }
            i++;
        }
        int sum = 0;
        for( i=0; i<hiking.length; i++){
            sum+=hiking[i];
            hiking[i]=sum;
        }
        boolean flag = true;
        for(int h : hiking){
            if(h==0){
                if(!flag){
                    result++;
                }
                flag=true;
            }else if(h<0&&flag){
                flag=false;
            }
        }

        return result;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String s = scanner.nextLine();

        int result = countingValleys(n, s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

```

