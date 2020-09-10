# 프로그래머스 카카오 블라인드 2020 문제
- 괄호변환
    - https://programmers.co.kr/learn/courses/30/lessons/60058

## 풀이 방법
### 문제 이해하기
- 1) String p가 올바르거나 빈 문자열일 경우 -> 그대로 반환
- 2) 올바르지 않을 경우 
    - p를 u(균형잡힌, 더이상 분리 불가능한) , v로 분리
    - 2-1) u가 올바를 경우
        - return u+solution(v)
    - 2-2) u가 올바르지 않을 경우
        - return "(" + solution(v)+")"+ [u의 앞뒤제거하고 괄호 방향 바꾼 결과]
- [입력값]
    - Stirng p
- [출력값]
    - 괄호 올바르게 변환
### 문제 접근 방법
- 주어진 문자열 p는 이미 균형 잡힌 상태
- boolean isRight(String w) : 문자열 w가 올바른지 판단하는 함수
- int SplitUV(Stirng w) : 문자열 w를 u,v로 분리했을때, 분리되는 지점의 인덱스 반환
- solution(String p) : 재귀함수 


### 접근 방법을 적용한 코드
```java
class Solution {
    public boolean isRight(String w) {
		boolean istrue = true;
		Stack<String> s = new Stack<>();
		for(int i=0; i<w.length(); i++) {
			if(w.charAt(i)=='(') {
				s.push("(");
			}
			if(w.charAt(i)==')') {
				if(!s.isEmpty()) {
					s.pop();
				}else {
					istrue= false;
					break;
				}
			}
		}
		return istrue;
	}
    public int splitUV(String w) {
		int count_open=0;
		int count_close=0;
		int idx=0;
		for(int i=0; i<w.length(); i++) {
			if(w.charAt(i)=='(') {
				count_open++;
			}
			if(w.charAt(i)==')') {
				count_close++;
			}
			if(count_open==count_close) {
				idx=i;
				break;
			}
		}
		return idx;
	}
    public String solution(String p) {
       String answer = "";
        // base case : 올바르다 or 빈 문자열 -> 문자열 반환 
        if(p.equals("")) {
        	return "";
        }else if(isRight(p)) {
        	return p;
        }
        // recur : 올바르지 않다 -> u,v로 분할
        // u : 균형 잡힌 + 더이상 분리 불가
        int idx = splitUV(p);
        String u = p.substring(0,idx+1);
        String v = p.substring(idx+1);
        // u가 올바르다 -> u+solution(v)
        if(isRight(u)) {
        	answer = u+solution(v);
        }else {// u가 올바르지 않다 -> '('+solution(v)+')' + u의 첫번째 마지막 제거 후 괄호 방향 뒤집어서 뒤에 붙이기
        	String nu = u.substring(1,u.length()-1);// 첫번째 마지막 제거 
        	StringBuilder new_u = new StringBuilder(nu);
        	for(int i=0; i<nu.length(); i++) {
        		if(new_u.charAt(i)=='(') {
        			new_u.setCharAt(i, ')');
        		}
        		else if(new_u.charAt(i)==')') {
        			new_u.setCharAt(i, '(');
        		}
        	}
        	nu = new_u.toString();
        	answer = "("+solution(v)+")"+nu;
        }
        return answer;
    }
}
```

