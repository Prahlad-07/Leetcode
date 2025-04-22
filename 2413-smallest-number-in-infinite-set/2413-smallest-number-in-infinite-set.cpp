class SmallestInfiniteSet {
    set<int> st;
    int curr;
public:
    SmallestInfiniteSet() {
        curr = 1;
    }

    int popSmallest() {
        if (!st.empty()) {
            int val = *st.begin();
            st.erase(st.begin());
            return val;
        }
        return curr++;
    }

    void addBack(int num) {
        if (num < curr) {
            st.insert(num);
        }
    }
};
