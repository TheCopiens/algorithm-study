# GitBash를 이용해 깃허브 원격 저장소의 브랜치 가져오는 방법 
### 작업 설명
원격 저장소에서 작업중이던 branch를 내 노트북의 작업폴더로 가져오는 작업입니다. 같은 노트북 내에서 작업폴더의 위치를 이동시키는건 **.git**을 포함하는 상위폴더를 사용자가 원하는 위치로 **CTR+C/CTR+V** 또는 **드래그** 하면 됩니다. 그러나 사용자가 실수로 작업폴더를 지웠을 경우에는 master, branch 작업을 원격저장소에서 가져와야 자신의 원격저장소와 GitBash 사이의 **연동 작업**이 가능합니다.

### 원격저장소 브랜치 가져와 설정하는 순서
1. 먼저 원하는 폴더에서 GitBash를 열고 작업폴더(working directory) 사용을 선언한다
    - 폴더명 '새폴더'를 원격저장소의 브랜치를 가져올 작업폴더로 만든다      
    - 아래 사진에서 폴더명 오른쪽에 파란글씨의 **(master)**가 있는지 확인
    - GitBash에 <code>$git init </code> 명령어 입력
    - **명령어 결과** 
    - ![img load fail](./imgs/1init.JPG) 




---
### 이 글은 아래 사이트를 참고해 작성되었습니다.
- https://wonjerry.tistory.com/6
- https://cjh5414.github.io/get-git-remote-branch/
