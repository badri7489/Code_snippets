//Problem link : https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
         node* prev,*next;
        node(int k,int v){
            key = k;
            val = v;
            prev = next = NULL;
        }
    };
    int cap;
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    unordered_map<int,node*>mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void add(node* resnode){
       node* temp = head->next;
        resnode->next =temp;
        resnode->prev = head;
        head->next = resnode;
        temp->prev = resnode; 
    }
    void deletenode(node* resnode){
        node* delprev = resnode->prev;
        node* delnext = resnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* temp = mp[key];
            mp.erase(key);
            int res = temp->val;
            deletenode(temp);
            add(temp);
            mp[key] = head->next;
            return res;
        }
        else
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* temp =mp[key];
            mp.erase(key);
            deletenode(temp);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
            
        }
        node* newnode = new node(key,value);
        add(newnode);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */