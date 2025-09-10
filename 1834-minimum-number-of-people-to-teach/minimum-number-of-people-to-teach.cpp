class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // Step 1: Identify users who are in friendships but cannot communicate.
        // We use a set to avoid duplicates.
        unordered_set<int> needs_help_set; 
        
        for (auto& friendship : friendships) {
            int u = friendship[0];
            int v = friendship[1];
            
            // Check if users u and v can communicate.
            bool can_communicate = false;
            // A hash set for quick O(1) average time lookups.
            unordered_set<int> u_langs(languages[u - 1].begin(), languages[u - 1].end());
            
            for (int lang : languages[v - 1]) {
                if (u_langs.count(lang)) {
                    can_communicate = true;
                    break;
                }
            }
            
            // If they can't communicate, add both to our set of people who need help.
            if (!can_communicate) {
                needs_help_set.insert(u);
                needs_help_set.insert(v);
            }
        }

        // Step 2: If the set is empty, everyone is connected.
        if (needs_help_set.empty()) {
            return 0;
        }

        // Step 3: Find the most common language among the people in the "needs_help_set".
        // A frequency map for languages.
        vector<int> lang_counts(n + 1, 0);
        for (int person : needs_help_set) {
            for (int lang : languages[person - 1]) {
                lang_counts[lang]++;
            }
        }

        // Find the language that the most people in our set already know.
        int max_freq = 0;
        for (int i = 1; i <= n; i++) {
            max_freq = max(max_freq, lang_counts[i]);
        }

        // Step 4: Calculate the minimum teachings.
        // The number of people to teach is the total number of people needing help
        // minus those who already know the most popular language.
        return needs_help_set.size() - max_freq;
    }
};

