# Fork 한 Repository 최신으로 동기화 하는 방법

![img load fail](./imgs/fork_repository_update.png)

### 작업 설명 
원본 repository로부터 최신 정보를 가져와 fork한 repository를  **업데이트 시키는** 작업이다. 동기화 작업이 완료되면 local, remote 저장소가 모두 Origin Repository의 **최신 상태**에 동기화된다.

#### 요약 설명
1. <code>$git remote add upstream 원본저장소URL </code>
2. <code>$git remote -v </code>
3. <code>$git fetch upstream </code>
4. <code>$git checkout master </code>
5. <code>$git merge upstream/master </code>
6. <code>$git push origin master </code>
