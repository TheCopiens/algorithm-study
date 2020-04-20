import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Scanner;

import java.lang.Math;

public class Main{
    public static void solution(int n,int[][] rgb){
        for(int i=1 ; i<n ; i++){
            rgb[i][0]= rgb[i][0]+Math.min(rgb[i-1][1],rgb[i-1][2]);
            rgb[i][1]= rgb[i][1]+Math.min(rgb[i-1][0],rgb[i-1][2]);
            rgb[i][2]= rgb[i][2]+Math.min(rgb[i-1][0],rgb[i-1][1]); 
        }
        int min=0;
        min = Math.min(rgb[n-1][0],rgb[n-1][1]);
        min = Math.min(min,rgb[n-1][2]);
        System.out.println(min);
    }
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] rgb = new int[n][3];
        for(int i=0 ; i<n ; i++){
            String[] rgbStr = br.readLine().split(" ");
            rgb[i][0] = Integer.parseInt(rgbStr[0]);
            rgb[i][1] = Integer.parseInt(rgbStr[1]);
            rgb[i][2] = Integer.parseInt(rgbStr[2]);
        }
        solution(n,rgb);
    }
}