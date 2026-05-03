class Solution {
public:
    string foreignDictionary(vector<string>& words) {
       
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

      
        for (const string& w : words) {
            for (char c : w) {
                inDegree[c] = 0;
            }
        }

      
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min(w1.length(), w2.length());

           
            if (w1.length() > w2.length() && w1.substr(0, len) == w2.substr(0, len)) {
                return "";
            }

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end()) {
                        adj[w1[j]].insert(w2[j]);
                        inDegree[w2[j]]++;
                    }
                    break; 
                }
            }
        }

     
        queue<char> q;
        for (auto const& [node, degree] : inDegree) {
            if (degree == 0) q.push(node);
        }

        string result = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            if (adj.count(curr)) {
                for (char neighbor : adj[curr]) {
                    inDegree[neighbor]--;
                    if (inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
        }

      
        return result.length() == inDegree.size() ? result : "";
    }
};