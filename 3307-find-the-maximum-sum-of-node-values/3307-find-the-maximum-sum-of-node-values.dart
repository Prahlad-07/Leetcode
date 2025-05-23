// ============================================================================ //
// ||                                                                        || //
// ||                                                                        || //
// ||                               **PRAHLAD YADAV**                        || //
// ||           --------------EMERGING GRANDMASTER OF INDIA--------------    || //
// ||                                                                        || //
// ||                                                                        || //
// ============================================================================ //

class Solution {
  int maximumValueSum(List<int> nums, int k, List<List<int>> edges) {
    int n = nums.length;
    List<int> prof = [];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      prof.add((nums[i] ^ k)-nums[i]);
    }
     n = prof.length;
     prof.sort((a, b) => b.compareTo(a));
     for(int i=0;i<n;i++)
     {
        print(prof[i]);
     }
    for (int i = 0; i < n - 1; i+=2) {
      if (prof[i] + prof[i + 1] > 0) {
        sum += prof[i] + prof[i + 1];
      }
    }

    return sum;
  }
}