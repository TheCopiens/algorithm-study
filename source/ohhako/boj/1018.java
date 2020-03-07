import java.util.*;
public class Main{
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        int n= sc.nextInt();
        int m= sc.nextInt();
        String[] row = new String[m];
        sc.nextLine();
        
        for(int i=0 ; i<n; i++){
            row[i] = sc.nextLine();
        }
            
        char[][] s3 = {{'W','B'},{'B','W'}};
        List<Integer> repaint = new ArrayList<>();
        for(int i=0 ; i<=m-8 ; i++){ //오른쪽 이동 횟수
            for(int j=0 ; j<=n-8 ; j++){ //아래쪽 이동 횟수
                int s1_count = 0; //기준과 다른 갯수
                int s2_count = 0;
                for(int p=0 ; p<8 ; p++){ //행 범위
                    String line = row[p+j]; //가로 한줄 가져옴
                    for(int k=0 ; k<8 ; k++){
                        if(line.charAt(k+i)!=s3[p%2][(k+i)%2])
                            s1_count++;
                        if(line.charAt(k+i)!=s3[p%2][(k+i)%2])
                            s2_count++;
                    }
                }
                repaint.add(Math.min(s1_count,s2_count));
            }
        }
        
        int min = repaint.get(0);
        for(int i=1;i<repaint.size();i++){
            if(min>repaint.get(i))
                min = repaint.get(i);
        }
        System.out.println(min);
    }
}