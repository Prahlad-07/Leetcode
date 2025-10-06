class Solution {
    int[] dx = {0, 1, 0, -1};
    int[] dy = {1, 0, -1, 0};

    boolean bfs(int[][] grid, int mid, int n) {
        if (grid[0][0] > mid) return false;

        boolean[][] visited = new boolean[n][n];
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        visited[0][0] = true;

        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int i = cell[0], j = cell[1];

            if (i == n - 1 && j == n - 1) return true;

            for (int dir = 0; dir < 4; dir++) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];

                if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                    !visited[ni][nj] && grid[ni][nj] <= mid) {
                    visited[ni][nj] = true;
                    q.add(new int[]{ni, nj});
                }
            }
        }
        return false;
    }

    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int left = Integer.MAX_VALUE, right = Integer.MIN_VALUE;

        for (int[] arr : grid) {
            for (int val : arr) {
                right = Math.max(right, val);
                left = Math.min(left, val);
            }
        }

        int minTime = Integer.MAX_VALUE;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (bfs(grid, mid, n)) {
                minTime = Math.min(minTime, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return minTime;
    }
}
