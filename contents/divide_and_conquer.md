# Divide and Conquer 알고리즘

- '분할정복' 기법 이라고도 부릅니다.
- 문제(problem)를 잘게 쪼개면서(sub-problem) 풀어나가고 다시 병합하며 해를 찾는 알고리즘 입니다.
- 상위 문제를 구하기 위해 아래로 내려가며 답을 찾는 하향식 접근법
- [divide and conquer](https://www.youtube.com/watch?v=2Rr2tW9zvRg)


### 알고리즘 설계 조언
1. Divide: 분할이 가능한 문제라면 분할 기준을 선택하여 문제를 2개 이상으로 나눈다.
2. Conquer: 분할이 불가능한 경우 문제를 푼다.
3. Combine: 정복한 문제를 병합하여 해를 찾는다. 제대로 나누면 병합하기도 쉽다.


### 알고리즘 효율성
- 분할정복 알고리즘은 Recursion calls(재귀호출)가 사용되는 경우가 많다. 재귀호출에서 알고리즘 효율이 떨어질 수 있다. => 분할 기준에 따라 효율이 달라질 수 있다.


### 분할정복 관련 자료

- [백준 Z](https://www.google.com/search?q=%EB%B0%B1%EC%A4%80+z+%EB%AC%B8%EC%A0%9C&oq=%EB%B0%B1%EC%A4%80+z+%EB%AC%B8%EC%A0%9C&aqs=chrome..69i57j0l9.3894j0j7&sourceid=chrome&ie=UTF-8)
- [별 찍기 풀이](https://st-lab.tistory.com/95)
- https://gamedevlog.tistory.com/58
