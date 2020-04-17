# 동적프로그래밍(Dynamic Programming) 요약설명

### 개념 이해하기

탐욕 알고리즘처럼 전체 문제를 작게 여러개로 나누어 푸는 경우가 있다. 작은 문제들을 풀다보면 같은 문제들을 반복해서 푸는 경우가 있는데 그 문제를 재계산하지 않고 값을 저장해 두었다가 재사용하는 기법이 **동적 프로그래밍(DP)** 이다. <br>

- 분할정복 문제와 비교
  - 분할정복은 나누어진 작은 문제에서 반복이 일어나는 부분이 없지만 동적 프로그래밍은 작은 부분 문제들이 반복된다.
  - 분할정복은 부분 문제들이 서로 독립적 관계이지만 동적계획은 부분 문제들이 의존적 관계다.

### DP기법 문제를 푸는 방법

- 모든 작은 문제들은 한번만 풀어야 한다. 따라서 정답을 구한 작은 문제를 어딘가에 메모해야 한다. ( `메모제이션` )
- 이후에 그보다 큰 문제를 풀어나갈때 동일한 작은 문제가 나타나면 앞서 메모한 작은 문제의 결과값을 이용한다.

- DP으로 풀기위한 조건
  1. 작은 문제가 반복적으로 일어나는 경우
  2. 같은 문제는 구할 때 마다 정답이 같다.

### DP 기법의 두 가지 타입

1. 하향식 계산법 (탑다운 Top-down) : 가장 큰 문제를 방문 후 작은 문제를 호출하여 답을 찾는 방식
   - 주로 **재귀호출** 사용해 구현
   - **메모제이션**을 이용하면 함수호출을 줄일 수 있다.
   - **점화식**을 이해하기 쉽다는 장점이 있다.

- 점화식 : 재귀식 이라고도 부른다. 이웃하는 두개의 항 사이에 성립하는 관계를 나타내는 관계식이다. 등차수열이나 등비수열 같은, 단순하게 예를 들자면 a(n) = a(n-1) + d (a는 변수 d는 상수) 형태의 식.

2. 상향식 계산법 (바텀업 Bottom-up) : 가장 작은 문제들 부터 답을 구해가며 전체 문제의 답을 찾는 방식
   - 상향식 계산법이 **성능이 더 좋은 경우가 많다.**
   - 주로 **반복문** 이용해 구현
   - 재귀함수를 사용하지 않으므로 **시간과 메모리 사용량을 줄일 수 있다.**

### 동적 프로그래밍의 대표적인 세 가지 문제

1. 막대 자르기 문제
2. 최장 공통 부분 수열 문제
   - 비슷한 문제 : [프로그래머스 큰수만들기](https://programmers.co.kr/learn/courses/30/lessons/42883)
3. 배낭 문제

### 탐욕법을 활용한 문제풀이

- [RGB거리](https://github.com/TheCopiens/algorithm-study/blob/master/source/ohhako/boj/1149_dp.md)
- [정수 삼각형](https://github.com/TheCopiens/algorithm-study/blob/master/source/ohhako/boj/1932_DP.md)
- [동물원](https://www.acmicpc.net/problem/1309)
- [기타리스트](https://www.acmicpc.net/problem/1495)
- [LCS](https://www.acmicpc.net/problem/9251)
- [동전2](https://www.acmicpc.net/problem/2294)

---

### 위에서 나온 용어정리

- 재귀호출 : 함수 내부에서 해당 함수를 또 호출하는 방식
- 메모제이션 : 재계산 하지 않도록 값을 저장해 두는 기법으로 DP의 핵심이 된다.
- 점화식 : 재귀식 이라고도 부른다. 이웃하는 두개의 항 사이에 성립하는 관계를 나타내는 관계식이다. 등차수열이나 등비수열 같은, 단순하게 예를 들자면 a(n) = a(n-1) + d (a는 변수 d는 상수) 형태의 식.

---

본 글은 아래의 사이트를 참고해 작성되었습니다.

- https://semaph.tistory.com/16
- https://www.zerocho.com/category/Algorithm/post/584b979a580277001862f182
- https://m.blog.naver.com/PostView.nhn?blogId=qbxlvnf11&logNo=221222565505&proxyReferer=https%3A%2F%2Fwww.google.com%2F
- https://m.blog.naver.com/PostView.nhn?blogId=qbxlvnf11&logNo=221222565505&proxyReferer=https%3A%2F%2Fwww.google.com%2F
