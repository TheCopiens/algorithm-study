# 프로그래머스 문제

- 베스트앨범
    - https://programmers.co.kr/learn/courses/30/lessons/42579
    
### 문제 이해하기
- 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
- 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
- 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.

### 문제 접근 방법
해시 맵 정렬 코드를 구현하여 문제를 푼다.

### 구현 배경 지식
Comparable, Comparator

### 접근 방법을 적용한 코드

```java
import java.util.*;
class Solution {
    public int[] solution(String[] genres, int[] plays) {
        ArrayList<Integer> list=new ArrayList<Integer>();
      
        HashMap<String, Integer> add=new HashMap<String, Integer>();
        HashMap<String, ArrayList<Song>> map=new HashMap<String, ArrayList<Song>>();
        for(int i=0;i<genres.length;i++) {
        	if(add.containsKey(genres[i])) {
        		add.put(genres[i], add.get(genres[i])+plays[i]);
        		ArrayList<Song> array=map.get(genres[i]);
        		array.add(new Song(plays[i], i));
        		map.put(genres[i], array);
        	}
        	else {
        		add.put(genres[i], plays[i]);
        		ArrayList<Song> array=new ArrayList<Song>();
        		array.add(new Song(plays[i], i));
        		map.put(genres[i], array);
        	}
        }
        
        Map<String, Integer> sortAdd = sortByValue(add); 
        for (Map.Entry<String, Integer> en : sortAdd.entrySet()) { 
            String genre=en.getKey();
            ArrayList<Song> songs=map.get(genre);
            songs.sort(new SongComparator());
            for(int i=0;i<=1;i++) {
            	if(i>=songs.size()) break;
            	else list.add(songs.get(i).index);
            }
        } 
        
        
        return list.stream().mapToInt(i->i).toArray();
    }
    public static HashMap<String, Integer> sortByValue(HashMap<String, Integer> hm) 
    { 
        // Create a list from elements of HashMap 
        List<Map.Entry<String, Integer> > list = new LinkedList<Map.Entry<String, Integer>>(hm.entrySet()); 
  
        // Sort the list 내림차순
        Collections.sort(list, new Comparator<Map.Entry<String, Integer> >() { 
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) { 
                return (o2.getValue()).compareTo(o1.getValue()); 
            } 
        }); 
          
        // put data from sorted list to hashmap  
        HashMap<String, Integer> temp = new LinkedHashMap<String, Integer>(); 
        for (Map.Entry<String, Integer> aa : list) { 
            temp.put(aa.getKey(), aa.getValue()); 
        } 
        return temp; 
    } 
}
class Song implements Comparable<Song>{
	int play;
	int index;
	public Song(int play, int index) {
		this.play=play;
		this.index=index;
	}
	@Override
	public int compareTo(Song o) {
		if (this.play < o.play) {
            return 1;
        } 
		else if (this.play > o.play) {
            return -1;
        }
        return 0;
	}
}
class SongComparator implements Comparator<Song>{
	@Override
	public int compare(Song arg0,Song arg1) {
		return arg0.compareTo(arg1);
	}
}
```

