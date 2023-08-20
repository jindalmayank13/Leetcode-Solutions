class StreamChecker {
public:
    struct Node{
        Node* links[26];
        bool flag=false;
        bool isContains(char ch)
        {
            return links[ch-'a']!=NULL;
        }
        void put(char ch,Node* node)
        {
            links[ch-'a']=node;
        }
        Node* get(char ch)
        {
            return links[ch-'a'];
        }
        void setEnd()
        {
          flag=true;
        }
        bool isEnd()
        {
            return flag;
        }
    };
    class Trie
    {
        public:
        Node* root;
        Trie()
        {
           root=new Node();
        }
        void insert(string &str)
        {
         Node* node=root;
         for (int i=str.size()-1;i>=0;i--)
         {
             if (!node->isContains(str[i]))
             {
                 node->put(str[i],new Node());
             }
             node=node->get(str[i]);
         }
         node->setEnd();
        }
        bool check(string &str)
        {
            Node* node=root;
            for (int i=str.size()-1;i>=0;i--)
            {
              if (node->isContains(str[i]))
              {
                  node=node->get(str[i]);
                  if (node->isEnd()) return true;
              }
              else return false;
            }
            return false;
        }
    };
    Trie * trie;
    string str;
    StreamChecker(vector<string>& words) 
    {
        trie=new Trie();
        for (int i=0;i<words.size();i++)
        {
            trie->insert(words[i]);
        }
        str="";
    }
    
    bool query(char letter) {
        str+=letter;
        if(trie->check(str)) return true;
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */