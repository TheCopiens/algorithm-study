# 자주 쓰이는 문자열 API 메서드 정리

### 배열을 문자열(String) 타입으로 변환하는 메서드
- Arrays.toString() : 모든 타입을 문자열로 반환한 결과는 &#91;요소,요소, ...&#93; 형태를 유지한 문자열이다
- new String() : char 배열을 문자열로 변환한다

- String.valueOf() : 넘어온 파라미터를 문자열(String)로 변환한다
    - 파라미터로 사용할 수 있는 타입
    - char 배열 : String str = String.valueOf(char_array)
    - char형 문자 : String str = String.valueOf('c')
    - int형 숫자 : String str = String.valueOf(124)


### 문자열을 다른 타입으로 변환하는 메서드
- toCharArray() : 문자열을 char 배열로 변환

```java
String s1;
char[] chr_arr = s1.toCharArray();
```
- Integer.parseInt() : 문자열을 int형 값으로 변환
```java
String s2 = "2342525";
int a = Integer.parseInt(s2);
```

### 배열 복사 메서드   
- Arrays.copyOf(Object[] obj,int length)

- Arrays.copyOfRange(Object[] obj,int from, int to)

### 정렬 메서드
- 오름차순 정렬 메서드
    - Arrays.sort(Object[] obj) 
    - Arrays.sort(Object[] obj, int from, int toIndex+1)

- 내림차순 정렬 메서드
    - Arrays.sort(Integer[] arr, Collections.reverseOrder())
    - 넘겨주는 파라미터가 반드시 Integer 타입이어야 한다.