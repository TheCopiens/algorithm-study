package boj;
import java.util.*;

public class boj_2583 {
	public static int n, m, k;
    public static int[][] graph = new int[100][100];
    //public static int[] size = new int[100];
    public static ArrayList<Integer> size= new ArrayList<Integer>();
    public static int check = 0;
    
    public static boolean dfs(int x, int y) {
    	if(x<0 || x >=m || y<0 || y >= n) {
    		return false;
    	}
    	if(graph[x][y] == 0) {
    		graph[x][y] = 1;
    		//상
    		dfs(x-1,y);
    		//하
    		dfs(x+1,y);
    		//좌
    		dfs(x,y-1);
    		//
    		dfs(x,y+1);
    		check++;
    		return true;
    	}
        	
    	return false;
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		m = sc.nextInt();
		n = sc.nextInt();
		k = sc.nextInt();
		sc.nextLine();
		
		for(int i=0;i<k;i++) {
			String str = sc.nextLine();
			//System.out.println(str);
			int num3 = Character.getNumericValue(str.charAt(4));
			//str.charAt(4) - '0'
			int num2 = Character.getNumericValue(str.charAt(2));
			
			int num1 = Character.getNumericValue(str.charAt(0));
			
			int num4 = Character.getNumericValue(str.charAt(6));
			
			for(int x=m-num4;x<m-num2;x++) {
				for(int y=num1;y<num3;y++) {
					graph[x][y] = 1;
				}
			}
		}
		
		int result = 0;
		
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(dfs(i,j)) {
					result++;
					size.add(check);
					check = 0;
				}
			}
		}
		
		Collections.sort(size);
		
		
		System.out.println(result);
		for(int i=0;i<size.size();i++) {
			System.out.print(size.get(i)+" ");
		}
//		for(int i=0;i<m;i++) {
//			for(int j=0;j<n;j++) {
//				System.out.print(graph[i][j]+" ");
//			}
//			System.out.println();
//		}
		
    }
}
