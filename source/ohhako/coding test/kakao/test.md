1. 
```java
import java.util.*;
class Solution {
    public int solution(int[][] board, int[] moves) {
        
        int answer = 0;
        Stack<Integer> basket = new Stack<>();
        for(int i=0 ; i<moves.length ; i++){
            
            for(int j=0 ; j<board.length ; j++){
                int doll=board[j][moves[i]-1]; 
                if(doll!=0){
                    board[j][moves[i]-1] =0; //꺼낸다
                    if(!basket.isEmpty() && basket.peek()==doll){
                        basket.pop();
                        answer+=2;
                    }else{
                        basket.push(doll);
                    }
                    break;
                }
            }
        }
        
        return answer;
    }
}
```

2. 
```java
import java.util.*;
class Solution {
    public int[] solution(String s) {
        if(s.length()==5){
            int a = Integer.parseInt(String.valueOf(s.charAt(2)));
            int[] ans = {a};
            return ans;
        }
        
        s = s.substring(1,s.length()-1);
        String[] s_arr = s.split("},\\{");
        s_arr[0] = s_arr[0].substring(1,s_arr[0].length());
        s_arr[s_arr.length-1] = s_arr[s_arr.length-1].substring(0,s_arr[s_arr.length-1].length()-1);
        Node[] nodes = new Node[s_arr.length];
        
        for(int i=0 ; i<s_arr.length ; i++){
            nodes[i] = new Node(s_arr[i],s_arr[i].replace(",","").length());
        }
        Arrays.sort(nodes, new Comparator<Node>(){
           @Override
            public int compare(Node n1,Node n2){
                return Integer.compare(n1.len ,n2.len);
            }
        });
        int[] answer = new int[nodes.length];
        answer[0] = Integer.parseInt(nodes[0].str);
        for(int i=1 ; i<nodes.length ; i++){
            for(int j=0 ; j< nodes[i].number_list.size() ; j++){
                if(!nodes[i-1].number_list.contains(nodes[i].number_list.get(j))){
                    answer[i] = Integer.parseInt(nodes[i].number_list.get(j));
                    break;
                }
            }
        }
        
        return answer;
    }
}

class Node{
    String str;
    int len;
    List<String> number_list;
    Node(String str,int len){
        this.str = str;  // 11,223 이런식으로 저장되어 있음
        this.len = len;
        number_list = new ArrayList<>();
        String[] strArr = str.split(",");
        for(String st : strArr)
            number_list.add(st);
    }
}

```


4. -1
```java
import java.util.*;
class Solution {
    public long[] solution(long k, long[] room_number) {
        HashMap<Long,Integer> book = new HashMap<>();
        
        long[] answer = new long[room_number.length];
        for(int i=0 ; i<room_number.length ; i++){
            long n = room_number[i]; 
            while(book.containsKey(n))
                n++;
            book.put(n,1);
            answer[i]=n;
        }
        
        return answer;
    }
}
```

4. -2
```java
import java.util.HashMap;
class Solution {
    public long[] solution(long k, long[] room_number) {
        HashMap<Long,Integer> book = new HashMap<>();
        long[] answer = new long[room_number.length];
        for(int i=0 ; i<room_number.length ; i++){
            long key = room_number[i]; 
            while(book.containsKey(key)){
                key++;
            }
            book.put(key,1);
            answer[i] = key;
        }
        return answer;
    }
}
```


4. -3
```java
import java.util.HashMap;
class Solution {
    public long[] solution(long k, long[] room_number) {
        // HashMap<Long,Integer> book = new HashMap<>();
        HashMap<Long,Integer> notbook = new LinkedHashMap<>();//예약안된방
        for(long i=1 ; i<=k ; i++)
            notbook.put(i,1);
        Iterator<Long> iter = notbook.keySet().iterator();
        long[] answer = new long[room_number.length];
        for(int i=0 ; i<room_number.length ; i++){
            long key = room_number[i]; 
            
            while(!notbook.containsKey(key)){
                key++;
            }
            notbook.remove(key);
            answer[i] = key;

        }
        
        return answer;
    }
}
```

5. 
```java
class Solution {
    public int solution(int[] stones, int k) {
        int answer = 0; //건넌친구 수
        
        while(true){
            boolean isSuccess= true;
            int notCross =0;
            for(int i=0 ; i<stones.length ; i++){
                if(notCross==k){//건너기 실패
                    isSuccess = false;
                    break; 
                }
                if(stones[i]==0){//못건너는 다리
                    notCross++;
                    continue;
                }
                notCross=0;
                stones[i]--;
            }
            if(isSuccess)
                answer++;
            else
                break;
        }
        return answer;
    }
}
```

<!-- 2번문제 dataB님 
```java
public int[] solution(String s) {
	    HashMap<Integer, String[]> map = new HashMap<>();
	    HashMap<String, Integer> check = new HashMap<>();
	    s = s.substring(1, s.length()-1 );
	    String[] str = s.split("},");
	    
	    for(int i =0; i<str.length; i++) {
	    	String sdata = str[i].replaceAll("\\{|\\}|,"," ");
	    	String[] data = sdata.trim().split(” “);
	    	map.put(data.length, data);
	    }
	    for(int i=0; i<=map.size(); i++) {
	    	String[] key = map.get(i+1);
	     	if(key!=null) {	
	    	    for(int j=0; j<key.length; j++) {
	    		    check.put(String.valueOf(key[j]), check.getOrDefault(String.valueOf(key[j]),0)+1);
	    	    }
	     	}
	    }
	    Set<String> keyset = check.keySet();
	    int[] answer = new int [check.size()];
	    for(String key : keyset ) {
	    	answer[check.size()-check.get(key)] = Integer.valueOf(key);
	    }
	    return answer;
	  }
``` -->