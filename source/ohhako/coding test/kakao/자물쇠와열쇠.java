import java.util.*;
class Solution {
    public int[][] rotation(int[][] key){
        int m = key.length;
        int[][] newKey = new int[m][m];
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<m ; j++){
                newKey[j][m-i-1] = key[i][j];
            }
        }
        return newKey;
    }

    public boolean compareKeychain(int[][] newKey,int[][] lock){
        boolean answer= true;

        for(int i=0 ; i< m ; i++){ //자물쇠 비교 시작점 우측으로 옮기기
            for(int j=0 ; j<m ; j++){  //자물쇠 비교 시작점 아래로 옮기기
                for(int p=0 ; p<m-i ; p++){
                    for(int k=0 ; k<m-j ; j++ ){
                    }
                }
            }
        }
        return answer;
    }

    public boolean solution(int[][] key, int[][] lock) {
        boolean answer = false;
        int[][] newKey = key;
        for(int i=0 ; i<4 ; i++){
            newKey = rotation(newKey);
            if(compareKeychain(newKey,lock)){
                answer=true;
                break;
            }
        }
        return answer;
    }
}