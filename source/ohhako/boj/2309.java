// https://www.acmicpc.net/status?user_id=hrkeon0503&problem_id=2309&from_mine=1
import java.util.*;
public class Main{
    public static void main(String[] args){
        //입력을 모두 더한 값에서 두명을 뺏을때 100이어야 함.
        int[] dwarfs = new int[9];
        Scanner sc = new Scanner(System.in);
        int total = 0;
        for(int i=0 ; i<dwarfs.length ; i++){
            dwarfs[i] = sc.nextInt();
            total+= dwarfs[i];
        }
        
        for(int i=0 ; i<dwarfs.length ; i++){
            for(int j=0 ; j<dwarfs.length ; j++){
                if(i==j) continue;
                int value = total-dwarfs[i] - dwarfs[j];
                if(value==100){
                    dwarfs[i] = -1;
                    dwarfs[j] = -1;
                    break;
                }
            }
        }
        
        Arrays.sort(dwarfs);
        for(int i=0 ; i<dwarfs.length ; i++){
            if(dwarfs[i]!=-1)
                System.out.println(dwarfs[i]);
        }
    }
}