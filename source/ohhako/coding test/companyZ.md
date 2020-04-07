```java
import java.util.*;
class Solution {
    public int solution(int[] A) {
        HashMap<Integer,Integer> hm = new HashMap<>();
		for(int i=0 ; i<A.length ; i++) 
			hm.put(A[i],hm.getOrDefault(A[i],0)+1);
		ArrayList<Integer> list = new ArrayList<>();
		for(int key: hm.keySet()) {
			if(key==hm.get(key)) {
				list.add(key);
			}
		}
		if(list.isEmpty())
			return 0;
		int answer= list.get(0);
		for(int i=1 ; i<list.size() ; i++) {
			if(answer<list.get(i))
				answer=list.get(i);
		}
		return answer;
    }
}
```

```java
import java.util.*;
class Solution {
    public int solution(int[] A) {
        int answer=0;
		ArrayList<Integer> total = new ArrayList<>();
		for(int i=0 ; i<A.length-1 ; i++) {
			for(int j=i+1 ; j<A.length ; j++) {
				int a = A[i];
				int b = A[j];
				int c=0; //a의 자리값 합  
				int d=0; //d의 자리값 합
				
				String[] str1= String.valueOf(a).split("");
				String[] str2= String.valueOf(b).split("");
				for(String st: str1)
					c+= Integer.parseInt(st);
				for(String st: str2)
					d+= Integer.parseInt(st);
				if(c==d) 
					total.add(a+b);
			}
		}
		int max=0;
		if(total.size()!=0) {
			max=total.get(0);
			for(int i=1 ; i<total.size(); i++) {
				if(max<total.get(i))
					max = total.get(i);
			}
		}
		return total.size()==0 ? -1 : max;
    }
}
```

```java
import java.util.*;
class Solution {
    public int solution(int[] A) {
        int num=0;
		 for(int i=0 ; i<A.length-1 ; i++) {
			 if(i%2==0 && A[i]<A[i+1]) {
				 num++;
			 }else if(i%2!=0 & A[i]>A[i+1]) {
				 num++;
			 }
		 }
		 if(num==A.length-1)
			 return 0;
		 num=0;
		 for(int i=0 ; i<A.length-1 ; i++) {
			 if(i%2==0 && A[i]>A[i+1]) {
				 num++;
			 }else if(i%2!=0 & A[i]<A[i+1]) {
				 num++;
			 }
		 }
		 int ways=0;
		 for(int i=0 ; i<A.length ; i++) { //돌아가면서 하나씩 잘려보기.
			 ArrayList<Integer> list = new ArrayList<>();
			 for(int j=0 ; j< A.length ; j++) {
				 if(j==i) continue;
				 list.add(A[j]);
			 }
			 boolean isPos=true;
			 for(int j=0 ; j< list.size()-1; j++) { //하나빠진 그래프 확인.
				 if(j%2==0) {
					 if(list.get(j)>=list.get(j+1)) {
						 isPos =false;
						 break;
					 }
				 }else { // 홀수일때
					 if(list.get(j)<=list.get(j+1)) {
						 isPos=false;
						 break;
					 }
				 }
			 }
			 if(isPos) {
				 ways++;
				 continue;
			 }
			 isPos=true;
			 for(int j=0 ; j< list.size()-1; j++) { //하나빠진 그래프 확인.
				 if(j%2==0) {
					 if(list.get(j)<=list.get(j+1)) {
						 isPos =false;
						 break;
					 }
				 }else { // 홀수일때
					 if(list.get(j)>=list.get(j+1)) {
						 isPos=false;
					 }
				 }
			 }
			 if(isPos) {
				 ways++;
			 }
		 }
		 return ways==0 ? -1: ways ;
    }
}
```

```java
import java.util.HashMap;
class Solution {
    public String solution(String S, String C) {
        StringBuffer sb = new StringBuffer();
		S.replace("-", " ");
		HashMap<String,Integer> hm = new HashMap<>();
		String[] names = S.split(";");
		
		for(int i=0 ; i<names.length ; i++) { // 사람 email만들기
			names[i] = names[i].trim(); //본래 이름
			String[] name = names[i].split(" ");
			String first = name[0];
			String last = name[1];
			if(name.length==3)
				last = name[2];
			if(last.contains("-"))
				last = last.replace("-","");
			String id = last+"_"+first; //first_last
			String em = C.toLowerCase()+".com"; 	// @company.com
			hm.put(id,hm.getOrDefault(id, 0)+1);
			
			if(hm.get(id)==1)
				sb.append(String.format("%s <%s@%s>; ",names[i],id.toLowerCase(),em));
			else
				sb.append(String.format("%s <%s%d@%s>; ",names[i],id.toLowerCase(),hm.get(id),em));
		}
		
		String answer = sb.toString().substring(0,sb.length()-2);
		return answer;
    }
}

```