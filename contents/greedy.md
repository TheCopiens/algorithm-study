# 탐욕법(Greedy) 알고리즘 요약설명 

- **분할정복 기법** 이라고도 부른다.
- 문제를 작은 단위로 쪼개 반복적으로 진행하며 접근하는 방식이다.
- 탐욕법은 각 단계마다 현재에 충실한 선택을 한다.
- 미래의 선택, 최종 결과는 고려하지 않는다.
- 반드시 최적의 해를 보장하는건 아니므로 '근사치 추정'을 위해 사용한다.


### 탐욕법을 적용한 문제 풀이
- 회의실 예약을 예시로 설명. 회의 시작 시간/끝나는 시간을 갖는 회의 목록이 존재한다. 회의실 하나를 겹치치 않게 최다로 사용할때 몇개의 회의를 진행 할 수 있을까?

- 탐욕적 선택 속성: 앞의 선택이 이후 선택에 영향을 주지 않는다. 답의 모든 부분을 고려하지 않고 탐욕적 선택만 하더라도 최적의 해를 구할 수 있는 속성
- 최적 부분 구조: 작은 부분 문제에서 구한 최적의 답으로 합쳐진 큰 문제의 최적의 답을 구할 수 있어야 한다. 

1. 문제의 답을 내는 과정을 여러 부분으로 나누자
    - 해: 겹치지 않고 선택한 회의 목록
    - 최적해: 겹치지 않고 최다로 선택한 회의 목록
2. 어떤 우선순위로 탐욕적 선택을 할지 선택 속성 결정
    - 회의 시간이 가장 짧은 회의부터 선택/ 가장 먼저 끝나는 회의부터 선택
3. 선택 속성이 최적 부분 구조를 만족하는지 따져본다.
    - 가장 빨리 끝나는 회의를 선택하면 가장 많은 회의를 선택 할 수 있다.



### 알고리즘 개선 방향

문제를 작은 단위로 쪼개 풀다보면 같은 문제를 반복해 푸는 경우가 있는데 이 때 그 문제들을 매번 재계산 하지 않고 값을 저장해두었다가 재사용 하는 동적프로그래밍(DP) 기법을 이용 할 수 있다.
- [DP 요약설명](https://github.com/TheCopiens/algorithm-study/blob/master/contents/DP.md)

### 탐욕법을 활용한 문제
* 동전을 최소 개수로 거슬러주기
* [체육복](https://github.com/TheCopiens/algorithm-study/blob/ohhako/source/ohhako/200202_greedy.md)
* [큰수만들기](https://programmers.co.kr/learn/courses/30/lessons/42883)
* [RGB거리](https://github.com/TheCopiens/algorithm-study/blob/master/source/ohhako/boj/1149_dp.md)
* [정수 삼각형](https://github.com/TheCopiens/algorithm-study/blob/master/source/ohhako/boj/1932_DP.md)
* [동물원](https://www.acmicpc.net/problem/1309)
* [기타리스트](https://www.acmicpc.net/problem/1495)
* [LCS](https://www.acmicpc.net/problem/9251)
* [동전2](https://www.acmicpc.net/problem/2294)
