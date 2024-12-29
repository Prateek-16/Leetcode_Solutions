class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int index = ch - 'a';
            if (temp->children[index] == NULL) {
                temp->children[index] = new TrieNode();
            }
            temp = temp->children[index];
        }
        temp->isWord = true;
    }

    bool search(string word) {
        TrieNode* temp = root;
        return search_helper(temp, word);
    }
    bool search_helper(TrieNode* temp, string word) {
        if (word.length() == 0) {
            return temp->isWord;
        }
        char ch = word[0];
        if (ch == '.') {
            bool ans = false;
            for(int i = 0;i<26;i++){
                if(temp->children[i] != NULL){
                    ans = ans || search_helper(temp->children[i], word.substr(1));
                } 
            }
            return ans;
        }
        int curr = ch - 'a';
        if (temp->children[curr] == NULL) {
            return false;
        }
        temp = temp->children[curr];
        return search_helper(temp, word.substr(1));
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */