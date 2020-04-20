import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class Main{
    public static void makeBridge(int n,int m){
        int answer=0;
        int parent=1;
        int child=1;
        for(int i=0 ; i<n-1 ; i++){
            parent = parent*(m-i);
        }
        parent = parent*(m-n+1);
        
        for(int i=1 ; i<=n ; i++)
            child = child*i;
        System.out.println(parent/child);
    }
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for(int i=0 ; i<t ; i++){
            String[] cmd = br.readLine().split(" ");
            makeBridge(Integer.parseInt(cmd[0]),Integer.parseInt(cmd[1]));
        }
    }
}