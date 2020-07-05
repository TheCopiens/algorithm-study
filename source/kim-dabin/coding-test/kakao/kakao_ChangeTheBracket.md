# 괄호변환

https://programmers.co.kr/learn/courses/30/lessons/60058#qna



## 문제 접근

- 다음과 같이 문제에서 시키는 데로 함

  ```
  1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
  2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
  3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
    3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
  4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
    4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
    4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
    4-3. ')'를 다시 붙입니다. 
    4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
    4-5. 생성된 문자열을 반환합니다.
  ```

-  **4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.**  이 부분에서 괄호 방향을 뒤집는게 아니라, reverse를 사용했더니 틀렸음 -> 하나 하나 다 괄호 방향을 바꿔줌



## 소스 구현

```java
import java.util.*;
class Solution {
    public static String getBracket(String p) {
		int left =0; 
		int right = 0;
		StringBuffer u = new StringBuffer();
		String v ="";
		String tmp ="";
		if(p.length()<1||p.equals("")) {
			return "";
		}
		
		for(int i=0; i<p.length(); i++) {
			if(p.charAt(i)=='(') {
				left++;
			}else{
				right++;
			}
			if(left>0&&left==right) {
				u.append(p.substring(0,i+1));
				v=p.substring(i+1);
				break;
			}
		}//for end 
		
	
		if(u.length()>0&&u.charAt(0)=='(') {
			 return u.append(getBracket(v)).toString();
		}else {
			tmp="("+getBracket(v)+")";
			for(int i=0; i<u.length(); i++) {
				if(u.charAt(i)=='(')	u.replace(i, i+1, ")");
				else u.replace(i, i+1, "(");
			}
		
			tmp+=u.substring(1, u.length()-1);
			return tmp;
		}

	}
  
	public String solution(String p) {
        String answer = "";
        
        if(p.equals("")){
            return p;
        }
     
        answer = getBracket(p);
        return answer;
    }
    
}
```

