class MovieRentingSystem {
    unordered_map<string, int> price;
    set<vector<int>> rented;
    unordered_map<int, set<vector<int>>> stored;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(vector<int> &entry : entries){
            int shop = entry[0];
            int movie = entry[1];
            int price_value = entry[2];
            string id = to_string(shop) + "+" + to_string(movie);
            price[id] = price_value; 
            stored[movie].insert({price_value, shop}); 
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        int count = 5;
        auto it = stored[movie].begin();
        while(count-- && it != stored[movie].end()){
            vector<int> tmp = *it;
            int price_value = tmp[0];
            int shop  = tmp[1];
            ans.push_back(shop);
            it++;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        string id = to_string(shop) + "+" + to_string(movie);
        int price_value = price[id];
        if(stored[movie].find({price_value, shop}) == stored[movie].end()){
            cout << "Rent() failed\n";
            return ;
        }
        stored[movie].erase({price_value, shop});
        rented.insert({price_value, shop, movie});
    }
    
    void drop(int shop, int movie) {
        string id = to_string(shop) + "+" + to_string(movie);
        int price_value = price[id];
        if(rented.find({price_value, shop, movie}) == rented.end()){
            cout << "DROP() failed\n";
            return ;
        }
        rented.erase({price_value, shop, movie});
        stored[movie].insert({price_value, shop});
    }
    
    vector<vector<int>> report() {
   
        vector<vector<int>> ans; 
        int count = 5;
        auto it = rented.begin();
        while(count-- && it != rented.end()){
            vector<int> tmp = *it;
            // int price = tmp[0];
            int shop = tmp[1];
            int movie = tmp[2];
            ans.push_back({shop, movie});
            it++;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */