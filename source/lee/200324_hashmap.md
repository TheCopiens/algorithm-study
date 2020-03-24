# Two Sum
https://leetcode.com/problems/two-sum/

## 문제 접근 방법
Map에 key=nums[i], value=i를 저장함
1. nums를 하나씩 돌면서 target-nums[i]가 map에 저장되어있는지 확인.
2. 만약 있으면 바로 그 값이 키로 value를 구함.
3. 없으면 map에 저장

### 문제점
처음에 map에 어떤 값을 key로, 어떤 값을 value로 저장해야했었는지 많이 헷갈렸다. `(k,v) = (idx,nums[idx])`, `(k,v) = (nums[idx], target-nums[idx])`등 저장하는 자료구조를 잘못 선택해서 시간을 많이 낭비했다.

## 코드 구현
```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();

        int[] result = new int[2];
        for(int i=0;i<nums.length;i++){
            if(map.containsKey(target-nums[i])) {
                result[0] = map.get(target-nums[i]);
                result[1] = i;
                return result;
            } else {
                map.put(nums[i],i);
            }
        }
        return result;
    }
}
```

### Time complexity
O(n) n=nums.length

### Space complexity
O(n) n=nums.length
