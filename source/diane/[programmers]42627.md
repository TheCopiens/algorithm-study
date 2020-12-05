# Programmers 디스크 컨트롤러 문제

- 디스크 컨트롤러
    - https://programmers.co.kr/learn/courses/30/lessons/42627

### 문제 이해하기
디스크 컨트롤러는 한 번에 하나의 작업만 할 수 있다.
작업은 그 작업이 요청되는 시간과 이를 수행하는데 걸리는 시간이 주어진다.
특정 작업에 대해 작업이 요청된 시간부터 디스크 컨트롤러가 그 작업을 끝낸 시간까지가 작업 처리에 걸린 시간이다.
디스크 컨트롤러가 모든 작업을 끝냈을 때, 각 작업의 처리 시간의 평균이 가장 작도록 하여 그 평균값을 구하여라.

#### 입력
- int[][] jobs : 작업의 목록
    - 각 작업은 요청 시간과 처리에 걸리는 시간을 가지는 크기 2의 정수 배열로 주어짐

#### 출력
- int : 모든 작업의 요청부터 처리까지의 걸린 시간의 평균값

### 문제 접근 방법
1. 요청이 들어온 순서대로 작업을 정리한다.
2. 더 이상 남은 작업이 없을 때까지 아래 과정을 반복한다.
    1. 현재 처리할 수 있는 작업들을 선별한다.
    2. 위에서 선별한 작업 중에 처리시간이 가장 짧은 작업을 처리한다.
    3. 이번에 처리한 작업의 요청에서 처리시간까지의 값을 계산하고, 처리시간만큼 시간을 증가시킨다.
3. 모든 작업을 처리했다면 모든 작업의 요청에서 처리까지 걸린 시간의 합을 작업의 총 갯수로 나누어 평균값을 구한다.

2번 과정에서, 작업들을 처리시간이 가장 짧은 작업을 선택해야 한다.
이 때 이를 위해 정렬을 쓸 수도 있지만, 모든 작업을 처리 시간 순서로 정렬할 필요 없이 최소값만 구하면 되는 것이기에,
굳이 정렬을 사용하지 않고 min heap을 사용하는 것만으로도 충분하다.

### 구현 배경 지식
MinHeap

### 문제를 해결한 코드
~~~java
public class Solution {

    private HashMap<Integer, ArrayList<Integer[]>> disks;
    private MinHeap remainings;

    public Solution() {
        disks = new HashMap<>();
        remainings = new MinHeap();
    }

    public int solution(int[][] jobs) {
        int time = 0;
        int runtime = 0;
        int number = jobs.length;

        for (int[] disk : jobs) {
            ArrayList<Integer[]> list = new ArrayList<>();
            if (disks.containsKey(disk[0])) {
                list = disks.get(disk[0]);
            }
            list.add(Arrays.stream(disk).boxed().toArray(Integer[]::new));
            disks.put(disk[0], list);
        }

        ArrayList<Integer> times = new ArrayList<>(disks.keySet());
        Collections.sort(times);
        while (times.size() > 0 || remainings.size() > 0) {
            // 이 시간에 사용할 수 있는 disk 넣
            while (times.size() > 0 && times.get(0) <= time) {
                for (Integer[] item : disks.get(times.get(0))) {
                    remainings.insert(item);
                }
                times.remove(0);
                if (times.size() < 1) break;
            }

            // 만약 이 시간에 할 수 있는 것이 없다면
            if (remainings.size()<1) {
                time++;
                continue;
            }

            Integer[] item = remainings.delete();
            time = time + item[1];
            runtime = runtime + (time-item[0]);
        }

        System.out.println("Total Time : "+time);
        runtime = runtime / number;

        return runtime;
    }
}

class MinHeap {
    private ArrayList<Integer[]> heap;

    public MinHeap() {
        heap = new ArrayList<>();
        heap.add(new Integer[] {0,0}); // index 0 added (not use index 0)
    }

    public void insert(Integer[] v) {
//        Integer[] value = Arrays.stream(v).boxed().toArray(Integer[]::new);
        heap.add(v);

        int p = heap.size()-1;
        while (p>1 && heap.get(p/2)[1]>heap.get(p)[1]) {
            Integer[] temp = heap.get(p/2);
            heap.set(p/2, heap.get(p));
            heap.set(p, temp);
            p = p/2;
        }
    }

    public Integer[] delete() {
        if (heap.size() < 2) {
            return new Integer[] {0,0};
        }

        Integer[] deleteItem = heap.get(1);
        heap.set(1, heap.get(heap.size()-1));
        heap.remove(heap.size()-1);

        int p = 1;
        while ((p*2) < heap.size()) {
            Integer[] min = heap.get(p*2);
            int minp = p*2;
            if ((minp+1 < heap.size()) && (min[1] > heap.get(minp+1)[1])) {
                min = heap.get(minp+1);
                minp = minp+1;
            }
            if (heap.get(p)[1] < min[1]) break;

            heap.set(minp, heap.get(p));
            heap.set(p, min);
            p = minp;
        }

        return deleteItem;
    }

    public int size() {
        return heap.size()-1;
    }

    public String toString() {
        String line = "";
        return line;
    }
}
~~~

