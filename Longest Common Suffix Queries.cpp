class TrieNode {
public:

    vector<pair<char, TrieNode*>> child;
    int idx;

    TrieNode() {
        idx = -1;
    }
};

class Solution {
public:

    vector<string>* words;

    void update(TrieNode* node, int i) {

        if(node->idx == -1 ||
           (*words)[i].size() < (*words)[node->idx].size()) {

            node->idx = i;
        }
    }

    TrieNode* getChild(TrieNode* node, char ch) {

        for(auto &p : node->child) {

            if(p.first == ch)
                return p.second;
        }

        return NULL;
    }

    void insert(TrieNode* root, string &s, int idx) {

        TrieNode* node = root;

        update(node, idx);

        for(int i = s.size()-1; i >= 0; i--) {

            char ch = s[i];

            TrieNode* nxt = getChild(node, ch);

            if(nxt == NULL) {

                nxt = new TrieNode();

                node->child.push_back({ch, nxt});
            }

            node = nxt;

            update(node, idx);
        }
    }

    int search(TrieNode* root, string &q) {

        TrieNode* node = root;

        for(int i = q.size()-1; i >= 0; i--) {

            TrieNode* nxt = getChild(node, q[i]);

            if(nxt == NULL)
                break;

            node = nxt;
        }

        return node->idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        words = &wordsContainer;

        TrieNode* root = new TrieNode();

        for(int i = 0; i < wordsContainer.size(); i++) {

            insert(root, wordsContainer[i], i);
        }

        vector<int> ans;

        for(string &q : wordsQuery) {

            ans.push_back(search(root, q));
        }

        return ans;
    }
};