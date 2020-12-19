# Programmers 여행경로 문제

- 여행경로
    - https://programmers.co.kr/learn/courses/30/lessons/43164

### 문제 이해하기
출발 도시와 도착 도시가 고정된 항공권 목록이 주어진다. 
이 항공권을 모두 이용하여 여행경로를 짜야한다. 
첫 출발지는 "ICN"이며, 항공권을 모두 사용할 수 없는 경우는 주어지지 않는다.
만약 가능한 여행경로가 여러 개라면, 알파벳 순으로 앞서는 경로를 구한다.

#### 입력
- String[][] tickets : 항공권의 목록
    - 모든 ticket은 길이 2의 String 배열로 이루어져 있다
    - ticket의 첫번째 원소는 출발지, 두번째 원소는 도착지이다

#### 출력
- String[] : "ICN"으로부터 시작하는 여행 경로의 도시 목록

### 문제 접근 방법
모든 가능성을 전부 탐색하면서 항공권을 모두 사용하는 여행경로를 찾는다.
그 방법은 다음과 같다.
1. 현재 위치한 도시를 찾는다. (처음은 ICN)
2. 현재 위치한 도시에서 갈 수 있는 모든 도시를 찾는다.
3. 각 다음 도시에 대해 그 도시를 현재의 도시로 하여 이 전체 과정을 반복한다. 즉, 그 도시로 이동할 경우 가능한 여행경로 중 가장 좋은 경로를 찾는다.
4. 과정 3에서 찾은 각 다음 도시의 가장 좋은 여행경로 중 조건에 맞는 여행경로를 찾는다.

여기서 조건이 맞다는 것은 아래와 같다.
1. 이 도시에서 시작하는 여행경로 중 가장 긴 경로일 것.
한 여행경로보다 더 긴 여행경로가 있다는 것은, 그 여행경로가 충분히 많은 도시를 여행하지 않았다는 뜻이다.
또한, 문제의 조건에서 모든 도시를 여행하지 못하는 경우는 없다고 했기 때문에 (즉, 그런 여행경로가 없는 경우를 판단할 필요가 없기 때문에), 모든 항공권을 다 사용한 여행경로는 필연적으로 가장 길 것이다.
2. 만약 여러 여행경로의 길이가 같다면, 이 중 알파벳 순으로 앞서는 것을 선택한다.

### 구현 배경 지식
DFS, Backtracking

### 문제를 해결한 코드
~~~java
import java.util.ArrayList;
import java.util.HashMap;

public class Solution {

    public String[] solution(String[][] tickets) {
        // tickets 정보를 HashMap에 넣는다
        HashMap<String, ArrayList<String>> list = new HashMap<>();
        for (String[] ticket : tickets) {
            ArrayList<String> dest = new ArrayList<>();
            if (list.containsKey(ticket[0])) {
                dest = list.get(ticket[0]);
            }
            dest.add(ticket[1]);
            list.put(ticket[0], dest);
        }

        // ICN을 시작으로 여행경로 찾기
        ArrayList<String> path = new ArrayList<>();
        path.add("ICN");
        path = findPath(path, list);

        return path.toArray(new String[path.size()]);
    }

    private ArrayList<String> findPath(ArrayList<String> path, HashMap<String, ArrayList<String>> list) {
        ArrayList<String> finalpath = path;
        String depart = path.get(path.size()-1);

        // 이 다음으로 갈 수 있는 모든 목적지에 대해서 경로 탐색하기
        if (list.get(depart) == null) return path;
        for (String dest : list.get(depart)) {
            // 사용한 티켓을 제외한 list 만들기
            HashMap<String, ArrayList<String>> newlist = new HashMap<>(list);
            ArrayList<String> temp = new ArrayList<>(list.get(depart));
            temp.remove(dest);
            if (temp.size() == 0) {
                newlist.remove(depart);
            } else {
                newlist.put(depart, temp);
            }

            // 새로운 목적지로 가는 path 만들기
            temp = new ArrayList<>(path);
            temp.add(dest);

            // 그 결과!
            temp = findPath(temp, newlist);
            finalpath = comparePath(temp, finalpath);
        }

        return finalpath;
    }

    private ArrayList<String> comparePath(ArrayList<String> path1, ArrayList<String> path2) {
        // 더 긴 경로가 정답일 것
        if (path1.size() < path2.size()) return path2;
        if (path1.size() > path2.size()) return path1;

        // 길이가 같다면, 알파벳 순으로 먼저 오는 것이 정답일 것
        ArrayList<String> answer = path1;
        for (int i=0; i<path1.size(); i++) {
            int comp = path1.get(i).compareTo(path2.get(i));
            if (comp == 0) continue; // 동일하다면 다음 장소 비교
            if (comp > 0) answer = path2;
            break;
        }
        return answer;
    }
}
~~~
