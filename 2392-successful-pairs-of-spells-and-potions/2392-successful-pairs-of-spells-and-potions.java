class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int m = potions.length;
        int[] ans = new int[n];
        Arrays.sort(potions);

        for (int i = 0; i < n; i++) {
            int left = 0, right = m - 1;
            int idx = -1;

            while (left <= right) {
                int mid = (left + right) / 2;
                long prod = (long) spells[i] * potions[mid];

                if (prod >= success) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            ans[i] = (idx == -1) ? 0 : (m - idx);
        }

        return ans;
    }
}
