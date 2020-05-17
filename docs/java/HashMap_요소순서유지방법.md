# HashMap 클래스의 요소 순서 유지방법

### 관련된 알고리즘 문제

- [캐시](https://github.com/TheCopiens/algorithm-study/blob/ohhako/source/ohhako/coding%20test/kakao/%EC%BA%90%EC%8B%9C.md#%EC%BA%90%EC%8B%9C)

## HashMap를 통한 순서 유지

HashMap은 데이터의 입력 순서와 상관없이 요소를 **key 오름정렬** 순서대로 유지합니다. HashMap 요소를 조회하기 위해 keySet(), values() 메서드를 사용했을때 결과가 **key 오름정렬** 순서로 나옵니다.

```java
HashMap<Integer,String> m = new HashMap<>();
m.put(3,"b");
m.put(1,"a");
m.put(2,"c");

for(int key : m.keySet()) {
	System.out.print(m.get(key));
}
System.out.println();

for(String value : m.values()) {
	System.out.print(value);
}
```

**결과**
<code> a c b </code>
<code> a c b </code>

## LinkedHashMap를 통한 순서 유지

LinkedHashMap은 HashMap을 확장한 인터페이스 입니다. HashMap의 모든 기능을 사용하되, Doubly-Linked List (이중연결 리스트) 를 내부에 유지해 입력된 자료의 순서를 보관하는 특징이 있습니다. **key를 중복으로 입력한** 경우에는 value는 덮어 씌이지만 데이터 순서에는 변동이 없습니다.

```java
HashMap<Integer,String> m = new LinkedHashMap<>();
m.put(3,"b");
m.put(1,"a");
m.put(2,"c");
m.put(3,"d");

for(Integer key : m.keySet()){
	System.out.print(m.get(key));
}
```

**결과**
<code>
d a c
</code>

### LinkedHashMap의 removeEldestEntry() 메서드 재정의하여 사용하기

**removeEldestEntry()** : Map에서 가장 오래된 엔트리를 삭제하며 성공시 true를 반환한다
<br>

removeEldestEntry() 메서드를 사용하려면 무조건 오버라이드를 해야합니다. removeEldestEntry()는 직접 호출하는 메서드가 아니므로 **재정의 하지않으면 LinkedHashMap의 put()이 HashMap의 메서드와 동일하게** 동작합니다.

- 데이터가 최대개수로 존재하는 해쉬맵이 있다고 가정한다. 이 해쉬맵에 새로운 데이터를 put할때 가장 오래된 요소를 삭제하고 새로운 데이터를 삽입한다. 새로운 데이터란 key가 중복되지 않는 데이터를 의미한다.

```java
HashMap<String,Integer> hm = new LinkedHashMap<String,Integer>() {
	@Override
	protected boolean removeEldestEntry(Map.Entry<String,Integer> eld) {
		return size() > MAXSIZE;
	}
		};

```

---

글 참고하기

- [LinkedHashMap 상속받은 클래스 구현하기](https://cornswrold.tistory.com/380)
