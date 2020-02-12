# 자주 쓰이는 문자열 다루기 메서드 정리

### 배열을 문자열(String) 타입으로 변환하는 메서드
- Arrays.toString() : 모든 타입을 문자열로 반환한 결과는 &#91;요소,요소, ...&#93; 형태를 유지한 문자열이다
- new String() : char 배열을 문자열로 변환한다
- String.valueOf() : 넘어온 파라미터를 문자열(String)로 변환한다
    - 파라미터로 사용할 수 있는 타입
    - char 배열 : String str = String.valueOf(char_array)
    - char형 : String str = String.valueOf('c')
    - int형 : String str = String.valueOf(124)


### 문자열을 다른 타입으로 변환하는 메서드
- toCharArray() : 문자열을 char 배열로 변환
- 코드 예시

```java
String s1;
char[] chr_arr = s1.toCharArray();
```
<br>

- Integer.parseInt() : 문자열을 int형 값으로 변환
- 코드 예시
```java
String s2 = "2342525";
int a = Integer.parseInt(s2);
```

<!-- int배열을 문자열로, 문자열을 int배열로 -->

### 배열 복사 메서드   
- void Arrays.copyOf(Object[] obj,int length)
- void Arrays.copyOfRange(Object[] obj,int from, int to+1)

### 정렬 메서드
#### 오름차순 정렬 메서드
- Arrays.sort(Object[] obj) 
- Arrays.sort(Object[] obj, int from, int to+1) : 인자의 배열을 인덱스 from부터 to까지 정렬
#### 내림차순 정렬 메서드
- Arrays.sort(Integer[] arr, Collections.reverseOrder())
- 넘겨주는 파라미터가 반드시 **Integer 타입**이어야 한다.


### 문자열 자르기 메서드
- param.substring(int start) : 인덱스 start부터 끝까지 문자열을 잘라서 저장
- param.substring(int start, int end+1) : 인덱스 start부터 end 까지 문자열을 잘라서 저장


### StringBuilder API 사용하기
- StringBuilder sb = new StringBuilder() : StringBuilder 객체 선언
- sb.toString() : 문자열 string으로 변환
- sb.substring(int from,int to+1) : 인덱스 이용해 문자열 추출 (반환할뿐, 저장하지 않음)
- sb.append(String param) : 문자열 마지막에 다른 문자열 연결하여 이어 붙이기
- sb.length() : 문자열의 길이
- sb.capacity() : 용량의 크기
- sb.reverse() : 문자열 역순으로 변경
* 참고로 StringBuilder는 단일 스레드용, StringBuffer는 멀티 스레드용으로 사용하는것을 권장한다.