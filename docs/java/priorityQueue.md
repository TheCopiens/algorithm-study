## 우선순위 큐(Priority Queue) 요약 정리
- BIFO(Best-in,First out)형 자료구조
- 우선순위가 가장 높은 데이터가 먼저 나온다.
- 데이터에 근거해 우선순위를 판단한다.
    - 어떤 데이터를 기준으로 우선순위를 부여할지 프로그래머의 판단이 필요하다.
- 우선순위가 같을수도 있다.
- 자바에서 Priority queue API를 지원한다.

### 선언 및 기본 연산
- PriorityQueue q = new PriorityQueue<>();
- q.offer()
- q.poll()
- q.toString(): 요소 모두 출력
- PriorityQueue 객체 선언시 제네릭 타입을 지정해야 한다. 
    - 클래스 지정시엔 해당 클래스에 Comparable 인터페이스를 보수하여 compareTo메서드를 오버라이드 해야한다. compareTo 메서드에서 우선순위 지정이 가능하다.
    - 객체를 비교해야 하므로 compareTo 메서드는 반드시 **객체의 클래스 내부**에 작성한다.

### 예시 코드 1
```java
package priorityQueue;
public class Graduate implements Comparable<Graduate>{
	String name;
	int grade;
	public Graduate(String name,int grade) {
		this.name= name;
		this.grade = grade;
	}

	@Override
	public int compareTo(Graduate gr) {
		if(this.grade < gr.grade)
			return 1;
		else if(this.grade > gr.grade)
			return -1;
		return 0;
	}
}
```

```java
package priorityQueue;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		PriorityQueue<Graduate> graduates = new PriorityQueue<Graduate>();
		graduates.offer(new Graduate("harry",6));
		graduates.offer(new Graduate("ron",6));
		graduates.offer(new Graduate("chalie",7));
		graduates.offer(new Graduate("genie",5));
		graduates.offer(new Graduate("kozi",2));
		
		int len = graduates.size();
		for(int i=0 ; i<len; i++)
			System.out.println(graduates.poll().name);
	}
}
```
