# 2019 KAKAO BLIND RECRUITMENT 오픈채팅방

https://programmers.co.kr/learn/courses/30/lessons/42888

## 문제 접근 방법

1. 첫 번째 for loop에서 Map에 `uid, nickname`정보를 저장
2. 두 번째 for loop에서 최종 닉네임으로 출력

### 코드

```java
import java.util.HashMap;
import java.util.Map;

class Solution {
    private final String USER_ENTER_EN = "Enter";
    private final String USER_LEAVE_EN = "Leave";
    private final String USER_CHANGE_EN = "Change";

    private final String USER_ENTER_KR = "님이 들어왔습니다.";
    private final String USER_LEAVE_KR = "님이 나갔습니다.";

    public String[] solution(String[] record) {
        Map<String, String> userInfo = new HashMap<>();
        int resultCount = 0;
        for (String r : record) {
            String[] token = r.split(" ");
            if (USER_ENTER_EN.equals(token[0])) {
                userInfo.put(token[1], token[2]);
                resultCount++;
            } else if (USER_CHANGE_EN.equals(token[0])) {
                userInfo.replace(token[1], token[2]);
            } else {
                resultCount++;
            }
        }

        String[] answer = new String[resultCount];
        int idx = 0;
        for (String r : record) {
            String[] token = r.split(" ");
            if (USER_ENTER_EN.equals(token[0])) {
                answer[idx++] = userInfo.get(token[1]).concat(USER_ENTER_KR);
            } else if (USER_LEAVE_EN.equals(token[0])) {
                answer[idx++] = userInfo.get(token[1]).concat(USER_LEAVE_KR);
            }
        }

        return answer;
    }
}
```

### Time complexity

O(N) N=record.length

### Space complexity

O(N+M) N=record.length, M=userInfo.size()

### 실행 결과

```
테스트 1 〉	통과 (1.95ms, 50.2MB)
테스트 2 〉	통과 (1.90ms, 50.4MB)
테스트 3 〉	통과 (2.59ms, 50.7MB)
테스트 4 〉	통과 (2.32ms, 52.2MB)
테스트 5 〉	통과 (11.51ms, 56.5MB)
테스트 6 〉	통과 (18.19ms, 52.5MB)
테스트 7 〉	통과 (10.96ms, 55MB)
테스트 8 〉	통과 (11.49ms, 55.8MB)
테스트 9 〉	통과 (14.21ms, 54.5MB)
테스트 10 〉	통과 (20.90ms, 56.3MB)
테스트 11 〉	통과 (7.44ms, 53.1MB)
테스트 12 〉	통과 (6.97ms, 52.9MB)
테스트 13 〉	통과 (11.52ms, 54.9MB)
테스트 14 〉	통과 (18.53ms, 53MB)
테스트 15 〉	통과 (2.00ms, 52.6MB)
테스트 16 〉	통과 (2.09ms, 52.1MB)
테스트 17 〉	통과 (2.91ms, 50.3MB)
테스트 18 〉	통과 (3.30ms, 52.4MB)
테스트 19 〉	통과 (13.77ms, 53.7MB)
테스트 20 〉	통과 (10.35ms, 55.5MB)
테스트 21 〉	통과 (10.81ms, 56.1MB)
테스트 22 〉	통과 (10.86ms, 55.7MB)
테스트 23 〉	통과 (18.68ms, 55.2MB)
테스트 24 〉	통과 (13.39ms, 55.5MB)
테스트 25 〉	통과 (264.98ms, 149MB)
테스트 26 〉	통과 (277.02ms, 158MB)
테스트 27 〉	통과 (297.38ms, 164MB)
테스트 28 〉	통과 (297.34ms, 166MB)
테스트 29 〉	통과 (279.47ms, 166MB)
테스트 30 〉	통과 (266.87ms, 153MB)
테스트 31 〉	통과 (275.66ms, 159MB)
테스트 32 〉	통과 (261.82ms, 151MB)
```
