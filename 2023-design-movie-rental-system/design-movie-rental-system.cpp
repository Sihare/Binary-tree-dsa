class MovieRentingSystem {
    struct Entry {
        int shop, movie, price;
        bool operator<(const Entry& other) const {
            if (price != other.price) return price < other.price;
            if (shop != other.shop) return shop < other.shop;
            return movie < other.movie;
        }
    };

    unordered_map<int, set<Entry>> available; 
    set<Entry> rented; 
    unordered_map<int, unordered_map<int, int>> priceMap; 
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            Entry entry{shop, movie, price};
            available[movie].insert(entry);
            priceMap[shop][movie] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        for (const auto& entry : available[movie]) {
            result.push_back(entry.shop);
            if (result.size() == 5) break;
        }
        return result;
    }

    void rent(int shop, int movie) {
        int price = priceMap[shop][movie];
        Entry entry{shop, movie, price};
        available[movie].erase(entry);
        rented.insert(entry);
    }

    void drop(int shop, int movie) {
        int price = priceMap[shop][movie];
        Entry entry{shop, movie, price};
        rented.erase(entry);
        available[movie].insert(entry);
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        for (const auto& entry : rented) {
            result.push_back({entry.shop, entry.movie});
            if (result.size() == 5) break;
        }
        return result;
    }
};