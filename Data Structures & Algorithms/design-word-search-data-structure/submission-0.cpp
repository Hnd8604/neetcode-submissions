class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;
    TrieNode(){
        endOfWord = false;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root = new TrieNode();

    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word) {
            int i = c - 'a';
            if(cur->children[i] == nullptr){
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
private: 
    bool dfs(string word, int j, TrieNode* root){
        TrieNode* cur = root;
        
        for(int i = j; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(TrieNode* child : cur->children){
                    if(child != nullptr && dfs(word, i + 1, child)){
                        return true;
                    }
                }
                return false;
            } else {
                if(cur->children[c-'a'] == nullptr){
                    return false;
                }
                cur = cur->children[c-'a'];
            }
        }
        return cur->endOfWord;
    }
};
