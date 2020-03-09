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
#### char 배열로 변환하기
- toCharArray() : 문자열을 char 배열로 변환
- 코드 예시

```java
String str1;
char[] chr_arr = str1.toCharArray();
```
<br>

#### int 타입으로 변환하기
- Integer.parseInt() : 문자열을 int형 값으로 변환
- 코드 예시
```java
String str2 = "2342525";
int a = Integer.parseInt(str2);
```

#### long 타입으로변환하기
-Long.parseLong(str);

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

### 문자열 합치기 메서드 
- param1.concat(param2) : 합친 문자열을 String으로 생성해줌
- param1 + param2 : StringBuilder로 변환시킨 후 append()로 이어붙이고 toString()으로 문자열 반환

### 문자열 쪼개기 메서드
- str.split("a"): 문자열을 a라는 문자열을 기준으로 쪼갠 배열로 만들어 반환한다.
    - str.split("") 이렇게 사용하면 문자가 하나씩 쪼개진다. 문자열의 길이와 동일한 크기의 배열이 만들어 진다.

### 문자열 앞뒤 공백 제거
- s1.trim(): 문자열의 앞, 뒤 공백을 제거하여 반환한다. 문자열 중간에 있는 공백은 제거하지 않는다.

### 영어 대소문자 변환 메서드
str.toLowerCase(): 문자열을 모두 **소문자로 변환**하여 반환한다.
str.toUpperCase(): 문자열을 모두 **대문자로 변환**하여 반환한다.


### StringBuilder API 사용하기
- StringBuilder sb = new StringBuilder() : StringBuilder 객체 선언
- sb.toString() : 문자열 string으로 변환
- sb.substring(int from,int to+1) : 인덱스 이용해 문자열 추출 (반환할뿐, 저장하지 않음)
- sb.append(String param) : 문자열 마지막에 다른 문자열 연결하여 이어 붙이기
- sb.length() : 문자열의 길이
- sb.capacity() : 용량의 크기
- sb.reverse() : 문자열 역순으로 변경
* 참고로 StringBuilder는 단일 스레드용, StringBuffer는 멀티 스레드용으로 사용하는것을 권장한다.


### String 사용자 입력 받을때
- next() : 문자나 문자열을 공백 기준으로 입력받는다.
- nextLine(): 문자 또는 문자열을 한 라인씩 입력받는다. 즉 enter 마다 입력는다.
- Scanner로 int형 받은 다음 String형 받을때
    - Scanner로 int형 받은 다음 String형 받을때 주의해야 한다. nextInt는 개행을 포함하지 않지만 nextLine은 포함시키기 때문에 int입력시에 포함되었던 개행문자가 다음 nextLine에 포함된다. 그 결과 사용자 입력을 실제로 받지않고 지나친다. 그러니 이 부분을 유의해서 실수하지 않도록 하자.

- 해결방법: nextInt와 nextLine 사이에 sc.nextLine 메서드를 한번 더 써준다.
```java
Scanner sc = new Scanner(System.in);
String[] arr = new  String[3];
int num = sc.nextInt(); //1
sc.nextLine(); //2
for(int i=0 ; i<3 ; i++){
    arr[i] = sc.nextLine();
}
```