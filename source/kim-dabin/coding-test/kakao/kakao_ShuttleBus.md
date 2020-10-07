# [자바/카카오2018] 1차 셔틀버스

[문제링크](https://programmers.co.kr/learn/courses/30/lessons/17678)

## 코드 구현

```java
import java.util.*;

public class Solution {

	private static ArrayList<ArrayList<Long>> timeList;

	public static void getTimeList(int n, int t, int m, String[] timetable) {
		timeList = new ArrayList<ArrayList<Long>>();
		int startTime = 540;
		int[] timeArr = new int[1441];// 00:00~23:59

		Arrays.fill(timeArr, -1);

		for (int i = 0; i < n; i++) {
			timeList.add(new ArrayList<Long>());
			if (i > 0) {
				int from = startTime + 1;
				int to = startTime += t;
				Arrays.fill(timeArr, from, to + 1, i);
			}
		}

		Arrays.fill(timeArr, 0, 541, 0);
		ArrayList<Long> sortedTimetable = new ArrayList<Long>();
		for (String table : timetable) {
			String[] time = table.split(":");

			long timeSet = ((Integer.parseInt(time[0])) * 60 + (Integer.parseInt(time[1])));

			sortedTimetable.add(timeSet);

		} // for end

		Collections.sort(sortedTimetable);// 정렬
		int cnt = 0;
		boolean flag = false;
		int idx = 0;
			
			for (int i = 0; i < sortedTimetable.size(); i++) {
				
				long convertTime = sortedTimetable.get(i);

				int tidx = timeArr[(int) convertTime];
				
				if(!flag) {
					idx = tidx;
					flag = true;
				}//flag end 
				
				if (tidx < 0) {
					idx++;
					continue;
				}//if end 
				
				if (cnt >= m) { //
					idx++;
					cnt = 0;
				}
				
				if (idx >= n) {
					break;
				}
				
			
				if (tidx <= idx && cnt < m) {// 제시간안에 도착했고, 버스 정원도 안참
					cnt++;					
				} else if (tidx > idx || cnt >= m) { // 버스 정원이 찼거나 늦게 도착 => 다음 버스 탐
					idx=tidx;
					cnt = 1;
                   
				}
				
				 timeList.get(idx).add(convertTime);
				
			} // for end
			

	}// getTimeList();

	public static String getTimeString(long time) {
		StringBuffer sb = new StringBuffer();

		sb.append(String.format("%02d", time / 60)).append(":").append(String.format("%02d", time % 60));
		return sb.toString();
	}

	public String solution(int n, int t, int m, String[] timetable) {

		getTimeList(n, t, m, timetable);

		if (n < 2) {
			if (timeList.get(0).size() < m)
				return "09:00";
			else
				return getTimeString(timeList.get(0).get(m - 1) - 1);
		} else {
			if (timeList.get(n - 1).size() < m) {
				return getTimeString(540 + (n - 1) * t);
			} else {
				return getTimeString(timeList.get(n - 1).get(m - 1) - 1);
			}
		}

	}// solution() end
}


```



## 실행 결과

```tex
테스트 1 〉	통과 (1.23ms, 52.4MB)
테스트 2 〉	통과 (1.63ms, 52MB)
테스트 3 〉	통과 (1.63ms, 52.3MB)
테스트 4 〉	통과 (1.62ms, 50.4MB)
테스트 5 〉	통과 (1.26ms, 52.3MB)
테스트 6 〉	통과 (1.54ms, 50.6MB)
테스트 7 〉	통과 (4.57ms, 52.9MB)
테스트 8 〉	통과 (1.74ms, 52.1MB)
테스트 9 〉	통과 (1.27ms, 50.2MB)
테스트 10 〉	통과 (1.62ms, 52.3MB)
테스트 11 〉	통과 (1.69ms, 52.1MB)
테스트 12 〉	통과 (4.21ms, 52.6MB)
테스트 13 〉	통과 (4.60ms, 52.8MB)
테스트 14 〉	통과 (2.03ms, 50.3MB)
테스트 15 〉	통과 (2.50ms, 52.1MB)
테스트 16 〉	통과 (2.80ms, 53.2MB)
테스트 17 〉	통과 (4.07ms, 52.8MB)
테스트 18 〉	통과 (4.45ms, 50.5MB)
테스트 19 〉	통과 (3.99ms, 52.3MB)
테스트 20 〉	통과 (4.23ms, 50.9MB)
테스트 21 〉	통과 (4.18ms, 52.1MB)
테스트 22 〉	통과 (13.99ms, 55.4MB)
테스트 23 〉	통과 (18.00ms, 54.1MB)
테스트 24 〉	통과 (5.95ms, 50.5MB)
```

