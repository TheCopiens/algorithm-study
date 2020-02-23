# 프로그래머스 서머코딩/윈터코딩(~2018) 문제 
- 스킬트리
    - https://programmers.co.kr/learn/courses/30/lessons/49993

### 문제와 주어진 조건 이해하기
- skill의 순서를 지키기만 하면 된다.
- skill문자열 앞뒤에 어떠한 데이터가 끼어들어도 원본 skill의 순서만 유지하면 된다.
- 주의할 점은, **스킬 순서유지가 중요할뿐 반드시 모든 스킬을 배우지 않아도 된다.**
- 입력 데이터는 스킬과 유저들의 스킬트리 배열, 출력 데이터는 스킬순서를 지킨 유저 수

### 문제 접근 방법
- skill문자열을 쪼개 순서대로 조회가능한 자료구조에 저장한다
    - 배열/스택중 요소조회,삭제,가변크기조회 가능한 스택사용
- 유저의 문자열 조회하며 있는스킬은 삭제하고, 스택에 남은 스킬이 유저한테 있는지 확인
- 풀이순서 
1. 문자열 배열로 쪼개 스택에 저장 
    - String/char중에 char배열로 쪼갬
2. 모든 유저들의 스킬트리 순회
3. 스킬트리 문자열 쪼개 순회
    - 스택에 저장한 스킬 하나씩 꺼내며 유저의 스킬과 비교
    - 각 유저 순회끝났을때 스택비어있다 or 안비었지만 유저가 가진 스킬이 아닐경우 count++

* 개선해야할 부분
    - skill을 스택에 저장하면 유저들이 들어올때마다 새로 스택을 생성해야하는 단점이 있다.
    - dept가 4이므로 줄일 수 있도록 한다.
    - char배열로 문자열을 쪼갰더니 일치문제때 String으로 변환해야하는 번거로움이 있다.

### 배경지식
- String을 배열로 만드는 메서드 toCharArray
- Stack 구현 및 사용방법. char 제네릭 선언 시 꺽쇠안에 Character 넣기
- char형을 String으로 변환하는 메서드 String.valueOf
- 문자열안에 특정 문자열이 포함되어 있는지 확인하는 메서드 contains

### 접근 방법을 적용한 코드
```java
import java.util.*;
class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        char[] skill_arr = skill.toCharArray();
        Stack<Character> stack;
       
        for(int i=0 ; i<skill_trees.length ; i++){
            stack = new Stack<>();
            for(int k=skill_arr.length-1; k>=0 ; k--)
                stack.push(skill_arr[k]);
            char[] skill_tree = skill_trees[i].toCharArray();
            for(int j=0 ; j<skill_tree.length ; j++){
                if(!stack.empty() && stack.peek()==skill_tree[j]){
                     stack.pop();
                }
            }
            if(stack.empty())    answer++;
            if(!stack.empty()){
                boolean check =true;
                while(!stack.empty()){
                    String str = String.valueOf(stack.pop());
                    if(skill_trees[i].contains(str))    check = false;
                }
                if(check)   answer++;
            }
        }
        return answer;
    }
}
```