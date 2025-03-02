class Solution {
public:
	struct Trie {
		unordered_map<char, Trie*> next = {};
		priority_queue<string> suggest = {};
	};

	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		Trie *root = new Trie();
		for (auto word : products) {
			Trie *ptr = root;
			for (auto c : word) {
				if (!ptr->next.count(c)) {
					ptr->next[c] = new Trie();
				}
				ptr = ptr->next[c];
				ptr->suggest.push(word);
				if (ptr->suggest.size() > 3) {
					ptr->suggest.pop();
				}
			}
		}

		vector<vector<string>> result(searchWord.length());
		for (int i = 0; i < searchWord.length() && root->next.count(searchWord[i]); ++ i) {
			root = root->next[searchWord[i]];
			vector<string> match(root->suggest.size());
			for (int i = root->suggest.size()-1; i >= 0; -- i) {
				match[i] = root->suggest.top();
				root->suggest.pop();
			}
			result[i] = match;
		}
		return result;
	}
};