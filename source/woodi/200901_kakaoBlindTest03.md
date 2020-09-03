# 프로그래머스 카카오 블라인드 2018 문제
- [1차] 비밀지도
    - https://programmers.co.kr/learn/courses/30/lessons/17681

## 풀이 방법
### 문제 이해하기
- [입력값]
    - n : 지도의 한변의 길이
    - arr1 : 지도 1
    - arr2 : 지도 2
- [출력값]
    - 두 지도를 겹쳤을 때 최종 지도의 형태 
### 문제 접근 방법 1 (내가 푼 방법)
- 반복문을 돌면서 arr1[i]과 arr2[i]의 모든 숫자를 이진수로 변환 후 String으로 저장한다.
- arr1[i]과 arr2[i]의 k번째 수를 비교한다
    - 둘 중 하나라도 1 -> #
    - 둘 다 0 -> 공백
- 비교 결과를 answer[i]에 append한다.

### 접근 방법1 을 적용한 코드
```java
class Solution {
    public String makingBinaryNum(int num, int n) {
		char[] bn = new char[n];  // 0*n 으로 초기화
		for(int i=0; i<n; i++) {
			bn[i] = '0';
		}
		while(num>=1) {
			--n;
			int q = num/2;
			int r = num%2;
			bn[n] = (char) (r+'0');
			num = q;
		}
		String binaryNum = String.valueOf(bn);
		return binaryNum;
	}
    public String[] solution(int n, int[] arr1, int[] arr2) {
       String[] answer = new String[arr1.length];
        for(int i=0; i<arr1.length; i++) {
        	String s1 = makingBinaryNum(arr1[i], n);
        	String s2 = makingBinaryNum(arr2[i], n);
        	answer[i] ="";
        	for(int k=0; k<s1.length(); k++) {
        		if(s1.charAt(k)=='1' || s2.charAt(k)=='1') {
        			answer[i]+="#";
        		}else if(s1.charAt(k)=='0' && s2.charAt(k)=='0' ) {
        			answer[i]+=" ";
        		}
        	}
        }
        return answer;
    }
}
```
### 문제 접근 방법 2 
- 비트연산을 이용한다. (문제 의도)
	- 참고 : https://bcp0109.tistory.com/entry/2018-KAKAO-BLIND-%EB%B9%84%EB%B0%80%EC%A7%80%EB%8F%84-Java

### 접근 방법2를 적용한 코드
```java
class Solution{
	public String[] bitOperation(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        for(int i=0; i<n; i++) {
        	String temp = Integer.toBinaryString(arr1[i] | arr2[i]);
        	temp = String.format("%"+n+"s", temp); 	// n자리 중에서 빈칸은 0으로 채워준다.
        	temp = temp.replaceAll("1", "#");
        	temp = temp.replaceAll("0", " ");
        	answer[i] =temp;
        }
        
        return answer;
    }
}
```