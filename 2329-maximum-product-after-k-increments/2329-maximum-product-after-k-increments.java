class Solution {
    static final int MOD = 1_000_000_007;
    public int maximumProduct(int[] nums, int k) {
        long prod = 1;
        PriorityQueue<Integer>minHeap = new PriorityQueue<>();
        for(int val : nums){
            minHeap.add(val);
        }
        while(k > 0){
            int val = minHeap.poll();
            minHeap.add(val + 1);
            k--;
        }
        while(!minHeap.isEmpty()){
            prod = (prod * minHeap.poll()) % MOD;
        }
        return (int)prod;
    }
}