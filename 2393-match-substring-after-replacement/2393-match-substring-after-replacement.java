class Solution {
    public boolean matchReplacement(String s, String sub, char[][] mappings) {
        Map<Character, Set<Character>> mp = new HashMap<>();
        for (char[] p : mappings) {
            mp.putIfAbsent(p[0], new HashSet<>());
            mp.get(p[0]).add(p[1]);
        }
        int n = s.length(), m = sub.length();
        for (int i = 0; i <= n - m; i++) {
            boolean ok = true;
            for (int j = 0; j < m; j++) {
                if (s.charAt(i + j) == sub.charAt(j)) continue;
                if (mp.containsKey(sub.charAt(j)) && mp.get(sub.charAt(j)).contains(s.charAt(i + j))) continue;
                ok = false;
                break;
            }
            if (ok) return true;
        }
        return false;
    }
}
