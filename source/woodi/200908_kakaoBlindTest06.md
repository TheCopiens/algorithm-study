# 프로그래머스 카카오 블라인드 2020 문제
- 문자열 압축
    - https://programmers.co.kr/learn/courses/30/lessons/60057

## 풀이 방법
### 문제 이해하기
- [입력값]
    - Stirng s
- [출력값]
    - 압축 후 최소 길이
### 문제 접근 방법
- 문자열 s를 n개의 단위(1<= n < s.length()/2 )로 나누어서 배열 a에 담는다
- 배열 a의 원소를 차례로 검사하면서 앞선 원소와 같은지 비교한다.
    - Stack : 같은 문자열만 담는다.
    - a[i]에 대하여 stack에 담긴 문자열과
        - 같다 -> 스택에 a[i]를 추가
        - 다르다 -> (stack.size ==1) s= s+stack.pop() 
                -> (stack.size > 1) s= s+stack.size() + stack.pop()
                -> stack을 완전히 비우고, 스택에 a[i]를 추가한다.
- a의 모든 원소에 대해 검사한 후, 여전히 스택에 남아있는 문자열에 대하여 s에 더해준다.



### 접근 방법을 적용한 코드
```java
class Solution {
    public int splitlen(int n, String s) {
		String[] a = {};
		int len = s.length();
		if(len%n !=0) {
			a = new String[len/n+1];
		}else {
			a = new String[len/n];
		}
		int k=0;
		int j=0;
		while(k<s.length()) {
			int temp = k+n;
			if(temp > s.length()) {
				a[j] = s.substring(k, s.length());
				break;
			}
			a[j] = s.substring(k, temp);
			k = temp;
			j++;
		}

		String ns = "";	// stringBuilder가 좀더 낫다.
		Stack<String> st = new Stack<>();
		st.add(a[0]);
		for(int i=1; i<a.length; i++) {
			if(st.peek().equals(a[i])) {
				st.add(a[i]);
			}else {
				if(st.size()==1) {
					ns+=st.pop();
				}else {
					int c = st.size();
					ns+= Integer.toString(c);
					ns+= st.pop();
				}
				st.clear();
				st.add(a[i]);
			}
		}
		// stack에 남아있는거 다 붙여주기 
		if(st.size()==1) {
			ns+=st.pop();
		}else {
			int c = st.size();
			ns+= Integer.toString(c);
			ns+= st.pop();
		}
		return ns.length();
	}
    public int solution(String s) {
        int answer = 0;
        int min = s.length();
        for(int i=1; i<=s.length()/2; i++) {
        	int k = splitlen(i, s);
        	min = min > k ? k : min;
        }
        answer = min;
        return answer;
    }
}
```

