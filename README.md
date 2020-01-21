# algorithm-study

### 알고리즘 공부 방법

1. 알고리즘 관련 이론 공부해 이해한다.
- 자신이 이해할 수 있는 방식으로 이론을 정리하자.
- 블로그나 깃허브에 정리하는것도 하나의 방법이 될 수 있다.

2. 이론과 관련된 알고리즘 문제를 푼다.
- ex) 해쉬를 이용하는 문제, 배열을 이용하는 문제
- 문제의 레벨이나 자신의 눈높이에 맞추어 적당한 시간을 정해놓고 푼다.
- 대체로 60분~120분이 적당하다.
- 시간을 점점 단축시키는 방향으로 공부해야 실전에 대비할 수 있다.

3. 이해하기 어려운 문제는 질문하거나 풀이를 보자
- 주어진 문제를 풀다가 어디에서 막혔는지 혹은 자신이 무엇을 모르고 있는지 **명확히** 알아야 해법이 가능하다.
- 관련된 이론 참고하기, 정답 소스 보기, 다른 사람들 풀이 보기
- 이해하기 힘든건 주위 사람들 혹은 깃허브에 issue를 등록해 질문하자
- 쉬운것같은 문제도 괜찮으니 망설이지말고 질문하자. 지혜를 모으면 더 좋은 방법을 발견할 수 있다.

4. 알고리즘 이해 후 다시 풀기
- 코드에 주석을 달면 시간지나고 다시볼때 빠른 이해에 도움된다.

<br><br>

### 저장소 이용하는 법
##### 폴더 설명
- contents: 알고리즘 관련 이론을 정리해서 업로드하는 폴더
- docs: 이론 이외의 문서를 업로드하는 폴더
- source: 개인 폴더를 생성하고 알고리즘 source code를 업로드하는 폴더

<br>

##### 명령어 사용
workspace에 branch를 생성한다. <br>
1. <code> git checkout ohhako </code> - master에서 ohhako 브랜치로 전환
2. workspace에서 작업 
3. <code> git commit -m "message"</code> , <code> git push origin ohhako <code>
4. <code> git checkout master </code> - ohhako에서 master로 브랜치 전환
5. <code> git pull </code> - git원격 저장소의 master를 로컬로 가져오기
6. <code> git merge ohhako </code> - master에 ohhako의 브랜치작업 반영
7. <code> git push master </code>  


