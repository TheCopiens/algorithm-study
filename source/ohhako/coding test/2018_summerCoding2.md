# 프로그래머스 서머코딩/윈터코딩(~2018) 탐욕법(Greedy) 문제 
- 예산
    - https://programmers.co.kr/learn/courses/30/lessons/12982


### 문제 접근 방법
- 가장 많은 부서를 지원하려면 가장 적은 지원비부터 차례대로 지원해야 한다.
- 부서만큼 반복 수행
- 총지원비가 해당 부서의 금액을 감당할 수 있으면 지원
    - 지원이란, 총지원비 감소와 부서수 증감을 동반함
- 총지원비가 마이너스 되면 for문 탈출(break)

### 접근 방법을 적용한 코드
1. 첫번째 코드
```java
import java.util.Arrays;
class Solution {
  public int solution(int[] d, int budget) {
      int answer = 0;
      Arrays.sort(d);
      for(int i=0 ; i< d.length ; i++){
        if(budget-d[i]>=0){
              budget-=d[i];
              answer++;
        }else break;
      }

      return answer;
  }
}
```


2. 두번째 코드
```java
import java.util.Arrays;
class Solution {
  public int solution(int[] d, int budget) {
      int answer = 0;
      int i=0;
      Arrays.sort(d);
      while(budget-d[i]>=0){ 
              budget-=d[i];
              answer++;
              i++;
          if(!(i<d.length)) break;
      }
      
      return answer;
  }
}
```
- if 조건문을 while 조건 안으로 넣으려 했으나 코드 문법에 위배되는 사항이 생긴다.
    - while 조건문에 budget과 i를 같이 사용하지 못함
    - i의 길이를 먼저 조건문으로 걸어 break 해야함
    - 안그러면 d[] 배열에서 outbound 에러가 발생
- 어차피 인덱스가 d의 길이를 넘지않는 조건이 반드시 있어야 하므로 안전하게 첫번째 코드를 사용하는게 좋다.
    

