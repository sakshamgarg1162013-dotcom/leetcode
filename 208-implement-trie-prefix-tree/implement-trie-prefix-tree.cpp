class trienode{
    public:
    char data;
    trienode* children[26];
    bool isterminal;

    trienode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal = false;
    }
};

class Trie {
public:
    trienode* root;
    Trie() {
        root =  new trienode('\0');
    }

    void insertutil(trienode* root,string word){
        if(word.length()==0){
            root->isterminal = true;
            return;
        }
        int index = word[0]-'a';
        trienode* child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new trienode(word[0]);
            root->children[index] = child;
        }
        insertutil(child,word.substr(1));
    }
    
    void insert(string word) {
        insertutil(root,word);
    }
    
    bool searchutil(trienode* root,string word){
        if(word.length()==0){
            return root->isterminal;
        }
        int index = word[0]-'a';
        trienode* child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchutil(child,word.substr(1));
    }

    bool search(string word){
        return searchutil(root,word);
    }

    bool startsWithutil(trienode* root, string prefix) {
    if (prefix.length() == 0) {
        return true;
    }

    int index = prefix[0] - 'a';

    if (root->children[index] == NULL) {
        return false;
    }

    return startsWithutil(root->children[index], prefix.substr(1));
}
    
    bool startsWith(string prefix) {
        return startsWithutil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */