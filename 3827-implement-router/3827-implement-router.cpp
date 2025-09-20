class Router {
    int m;
    deque<tuple<int, int, int>> q;
    unordered_set<string> s;
    unordered_map<int, vector<int>> mp;

    string k(int a, int b, int c) {
        return to_string(a) + "_" + to_string(b) + "_" + to_string(c);
    }

public:
    Router(int _m) : m(_m) {}

    bool addPacket(int a, int b, int c) {
        string id = k(a, b, c);
        if (s.count(id)) return 0;
        if (q.size() == m) {
            auto [x, y, z] = q.front(); q.pop_front();
            s.erase(k(x, y, z));
            auto& v = mp[y];
            v.erase(lower_bound(v.begin(), v.end(), z));
        }
        q.emplace_back(a, b, c);
        s.insert(id);
        mp[b].insert(upper_bound(mp[b].begin(), mp[b].end(), c), c);
        return 1;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto [a, b, c] = q.front(); q.pop_front();
        s.erase(k(a, b, c));
        auto& v = mp[b];
        v.erase(lower_bound(v.begin(), v.end(), c));
        return {a, b, c};
    }

    int getCount(int b, int l, int r) {
        if (!mp.count(b)) return 0;
        auto& v = mp[b];
        return upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
    }
};