# 탐색방법 요약

### 완전탐색 (Brute-force)
빠른 cpu를 이용해 가능한 경우의 수를 모두 나열하여 답을 찾는 방법이다. 가능한 방법을 전부 만들어 무식하게 푸는 알고리즘이다.

- **BF 문제 목록**
- [소수찾기](https://github.com/TheCopiens/algorithm-study/blob/master/source/ohhako/200227_BF.md)
- [모의고사](https://github.com/TheCopiens/algorithm-study/blob/master/source/ohhako/200128_%EC%99%84%EC%A0%84%ED%83%90%EC%83%89.md)
- [일곱난쟁이](https://www.acmicpc.net/problem/2309)
- [boj 분해합](https://www.acmicpc.net/problem/2231)
- [boj 모든순열](https://www.acmicpc.net/problem/10974)
- [boj 차이를 최대로](https://www.acmicpc.net/problem/10819)
- [boj 로또](https://www.acmicpc.net/problem/6603)

### 탐욕법 (greedy 탐색)
매순간 최적이라고 생각되는 것을 선택해 나가는 방식이다. 그리디 알고리즘을 풀 때 중요 포인트는 '어떤 기준으로' 탐욕적인 선택을 하느냐 이다. 
1. 답 내는 과정 여러부분으로 나누기
2. 탐욕적 선택 기준 정하기
3. 탐욕적 선택 속성, 최적 부분 구조 따져보기 
    - [탐욕법 알고리즘 정리글 참고](https://github.com/TheCopiens/algorithm-study/blob/master/contents/greedy.md)
<br>

- **탐욕법 문제 목록**
- 배낭문제
- [체육복](https://github.com/TheCopiens/algorithm-study/blob/master/source/ohhako/200202_greedy.md)
    - 최소부분해(체육복 있는 학생)/다음 부분해(체육복 없지만 여분있는)/다음 부분해(앞뒤로 체육복 빌리는 학생)
- [큰수만들기](https://github.com/TheCopiens/algorithm-study/blob/master/source/ohhako/200228_greedy.md)
- [조이스틱](https://github.com/TheCopiens/algorithm-study/blob/master/source/ohhako/200303_greedy.md)
    - 해 구하는 방법을 네가지로 나눈다. (위아래 이동/우로 이동/좌로이동/우로 이동하다 되돌아와 좌로 이동)
- [예산](https://github.com/TheCopiens/algorithm-study/blob/master/source/ohhako/coding%20test/2018_summerCoding2.md)
    - '가장 금액이 낮은 지원비'는 탐욕적 선택 속성이며 본 문제는 최적 부분 구조를 만족한다