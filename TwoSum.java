import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/*
 * @Author: zero
 * @Date:   2021-07-09 08:40:04
 * @Description: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 */
class TwoSum {
    public static void main(String[] args) {
        System.out.println(Arrays.toString(solution(new int[]{1, 2, 3}, 3)));
    }

    public static int[] solution(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int i = 0;
        while (i < nums.length) {
            if (map.containsKey(target - nums[i]))
                return new int[]{map.get(target - nums[i]), i};
            map.put(nums[i], i++);
        }
        return new int[]{0};
    }
}