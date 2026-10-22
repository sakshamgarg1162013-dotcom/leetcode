class trienode{
public:
    char data;
    trienode* children[26];
    bool isterminal;

    trienode(char ch){
        data =ch;
        for (int i = 0; i < 26; i++)
        {
            /* code */
            children[i] = NULL;

        }
        isterminal = false;

    }
};

class WordDictionary {
public:
    trienode* root;
    WordDictionary() {
        root =  new trienode('\0');
    }
    void insertutil(trienode* root,string word){
        if(word.length()==0){
            root->isterminal = true;
            return ;

        }
        int index = word[0]-'a';
        trienode* child;

        if(root->children[index]!=NULL){
            child = root ->children[index];
        }
        else{
            child = new trienode(word[0]);
            root ->children[index]  = child;
        }
        insertutil(child,word.substr(1));

    }
    void addWord(string word) {
        insertutil(root,word);
    }
    
    bool searchutil(trienode* root, string word) {
    if (word.length() == 0) {
        return root->isterminal;
    }

    // If current character is '.'
    if (word[0] == '.') {
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                if (searchutil(root->children[i], word.substr(1))) {
                    return true;
                }
            }
        }

        return false;
    }
    int index = word[0] - 'a';

    if (root->children[index] == NULL) {
        return false;
    }

    return searchutil(root->children[index], word.substr(1));
}

bool search(string word) {
    return searchutil(root, word);
}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */