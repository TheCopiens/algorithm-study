## 방금그곡 코드 리팩터링
* &#42; DataB님이 도움주신 코드입니다.

### 개선된 부분
- 내가 들은 음계m과 음계를 비교하는 부분
    - 기존 방식: 시간 길이만큼 sheet와 m의 음을 chatAt메서드로 하나씩 확인했다.
    - 변경 방식
        - 시간동안 실제로 나온 음계를 경우로 나누어 구했다. (realMelody)
        - 실제나온 음계를 순회하며 내가들은 음계와 비교했다.
        - realMelody에서 m첫음과 일치하는 음을 만나면 m길이만큼 검사한다.

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
      // Music maxTimeMusic = new Music();
      
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