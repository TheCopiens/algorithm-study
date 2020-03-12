import java.util.ArrayList;
import java.util.List;

public class Main {
	public static class MinHeap{
		private List<Integer> heap;
		
		public MinHeap() {
			this.heap = new ArrayList<>();
			heap.add(0); //인덱스1부터 사용하기 위해
		}
		//요소 삽입 
		public void insert(int val) {
			heap.add(val); //일단넣고
			int p = heap.size() -1; //마지막 요소의 인덱스. 즉 바로 위에 담은 요소의 인덱스. 즉  p=신입
			
			while(p>1 && (heap.get(p/2)>heap.get(p))){ //반복하는 조건 : p보다 p의 부모가 값 더 크다, p는 1보다 크다
				int tmp = heap.get(p/2);
				heap.set(p/2,heap.get(p));
				heap.set(p,tmp);
				p=p/2; //신입이 부모위치로 올라간다!
			}
		}
		//노드 삭제. (루트 노드부터)
		public int delete() {
			if(heap.size()<=1) return 0;
			int deleteValue = heap.get(1);
			
			heap.set(1,heap.get(heap.size()-1));
			heap.remove(heap.size()-1);
			
			int pos=1;
			while(pos*2 < heap.size()) { 
				int minPos = pos*2; //자식 위치
				int minValue = heap.get(pos*2); //자식 값
				if((minPos+1)<heap.size() && (heap.get(minPos+1)<minValue)) {
					minPos = minPos +1;
					minValue = heap.get(minPos+1);
				}
				if(heap.get(pos) < minValue)
					break;
				int tmp = heap.get(pos);
				heap.set(pos, minValue);
				heap.set(minPos, tmp);
				pos = minPos;
			}
			return deleteValue;	
		}
	}
	public static void main(String[] args) {
		MinHeap heap = new MinHeap();
		int[] data = {10,6,8,4,5,3,4,2,1};
		for(int i=0 ; i<data.length; i++)
			heap.insert(data[i]);
		for(int i=1 ; i<heap.heap.size(); i++ )
			System.out.print(heap.heap.get(i)+" ");
	}
}
