## 방금그곡 코드 리팩터링

\* DataB님이 도움주신 코드입니다.

### 개선된 부분

- [이전코드](https://github.com/TheCopiens/algorithm-study/blob/master/source/ohhako/coding%20test/kakao/2018_%EB%B0%A9%EA%B8%88%EA%B7%B8%EA%B3%A1.md)
- 내가 들은 음계m과 음계를 비교하는 부분
  - 기존 방식: 시간 길이만큼 sheet와 m의 음을 chatAt메서드로 하나씩 확인했다.
  - 변경 방식
    - 시간동안 실제로 나온 음계를 경우로 나누어 구했다. (realMelody)
    - 실제나온 음계를 순회하며 내가들은 음계와 비교했다.
    - realMelody에서 m첫음과 일치하는 음을 만나면 m길이만큼 검사한다.
    - 조건에 맞는 리스트에서 객체를 저장하는것이 아닌, Max time과 title 을 저장했다.

```java
import java.util.*;
class Solution {
  public String solution(String m, String[] musicinfos) {
      List<Music> list = new ArrayList<>();
      for(int i=0 ; i<musicinfos.length ; i++){
          //재생시간(time) 구하기
          String[] info = musicinfos[i].split(",");
          String[] stop = info[1].split(":");
          String[] start = info[0].split(":");
          int time = (Integer.parseInt(stop[0])-Integer.parseInt(start[0]))*60
              + Integer.parseInt(stop[1]) -Integer.parseInt(start[1]);

          //재생시간동안 실제 반복된 음들을 구하라!
          String sheet = info[3].replace("C#","c").replace("D#","d").replace("F#","f").replace("G#","g").replace("A#","a");
          m = m.replace("C#","c").replace("D#","d").replace("F#","f").replace("G#","g").replace("A#","a");
          int len = time - sheet.length();
          String realMelody = ""; //시간동안 실제로 나온 음계

          if(len<0) { // 음악길이보다 재생된 시간이 짦으므로 처음부터 재생시간만큼만 재생된다.
				realMelody = sheet.substring(0,sheet.length()+len);
			}else if(len>0) { //음악길이가 더 길면 악보(sheet)가 재생된다.
				int cnt = time/sheet.length(); //반복 횟수
				int res = time%sheet.length(); //여분 길이
				for(int x=0; x<cnt; x++) { //반복 횟수만큼 이어붙이기
					realMelody = realMelody.concat(sheet);
				}
				realMelody = realMelody.concat(sheet.substring(0,res)); //여분길이만큼 자라 덧붙이기
			}else { //음악이 처음부터 재생되므로 음악길이=악보길이면 악보가 full로 나온 것
				realMelody = sheet;
			}

            //내가 들은 음계와 실제멜로디 일치 확인하기
          boolean flag = false; //일치를 확인하려는 플래그일까.
          for(int j=0 ; j<realMelody.length() ; j++){
              if(flag){
                  list.add(new Music(time,info[2]));
                  break;
              }
              if(realMelody.charAt(j)==m.charAt(0)){  //내 음계의 시작과 일치하는 음이 있다면
                for(int x = 0; x<m.length(); x++){   // 내 음계 길이만큼 해당 악보를 검사한다.
                    if(j+x<realMelody.length()&&realMelody.charAt(j+x)==m.charAt(x)){
                         flag = true;
                    }else{
                        flag = false;
                        break;
                    }
                }//for end
            }
        }//for end
      }

      if(list.isEmpty())
          return "(None)";

      String maxTimeMusic = "";
      int max = 0;
      for(int i=0 ; i<list.size() ; i++){
          if(max<list.get(i).time){
              maxTimeMusic = list.get(i).title;
              max = list.get(i).time;
            }
      }
      return maxTimeMusic;
  }
}
class Music{
    int time;
    String title;
    Music(int time,String title){
        this.time = time;
        this.title = title;
    }
}
```

```
테스트 1 〉	통과 (2.44ms, 52.1MB)
테스트 2 〉	통과 (1.48ms, 51.9MB)
테스트 3 〉	통과 (1.63ms, 52.4MB)
테스트 4 〉	통과 (1.34ms, 52MB)
테스트 5 〉	통과 (1.44ms, 52.3MB)
테스트 6 〉	통과 (1.52ms, 52.1MB)
테스트 7 〉	통과 (2.31ms, 54.6MB)
테스트 8 〉	통과 (2.15ms, 52.6MB)
테스트 9 〉	통과 (2.34ms, 51MB)
테스트 10 〉	통과 (2.44ms, 50.5MB)
테스트 11 〉	통과 (2.37ms, 52.1MB)
테스트 12 〉	통과 (2.60ms, 50.1MB)
테스트 13 〉	통과 (2.57ms, 50.4MB)
테스트 14 〉	통과 (2.35ms, 50.2MB)
테스트 15 〉	통과 (2.51ms, 50MB)
테스트 16 〉	통과 (2.18ms, 52.9MB)
테스트 17 〉	통과 (2.59ms, 52.9MB)
테스트 18 〉	통과 (2.33ms, 52.4MB)
테스트 19 〉	통과 (3.71ms, 52.3MB)
테스트 20 〉	통과 (2.32ms, 50.6MB)
테스트 21 〉	통과 (2.26ms, 52.5MB)
테스트 22 〉	통과 (2.01ms, 52.6MB)
테스트 23 〉	통과 (2.48ms, 50.6MB)
테스트 24 〉	통과 (2.00ms, 50.5MB)
테스트 25 〉	통과 (1.45ms, 53.1MB)
테스트 26 〉	통과 (1.59ms, 50.6MB)
테스트 27 〉	통과 (1.39ms, 52.2MB)
테스트 28 〉	통과 (1.48ms, 52.3MB)
테스트 29 〉	통과 (14.73ms, 50.7MB)
테스트 30 〉	통과 (15.25ms, 52.8MB)
```
