class LRUCache {
public:

    class Node{
        public:
        int val,key;
        Node* prev;
        Node* next;

        Node(int k , int v){
           key =k;
           val = v;

           prev = next =NULL;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    void addnode(Node* newnode){
        Node* oldnext = head->next;
        head->next = newnode;
        oldnext->prev= newnode;
        newnode->prev = head;
        newnode->next = oldnext;
    }

    void delnode(Node* oldnode){
        Node* oldnext = oldnode->next;
        Node* oldprev = oldnode->prev;
        
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }
    unordered_map<int , Node*> m;
    int limit =0;
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    int ans =0;
    int get(int key) {          
        if(m.find(key) == m.end()){
            return -1;}
        Node* ansnode = m[key];
        ans = ansnode ->val;
        
        delnode(ansnode);
        m.erase(key);
        addnode(ansnode);
        m[key] = ansnode;
          
        
          return ans;
    }
    
    void put(int key, int value) {   //if found same key which is already in the map
        if(m.find(key) != m.end()){
            Node* oldnode = m[key];
            delnode(oldnode);
            m.erase(key);
        }

        if (m.size() == limit){
            Node* oldnode = tail->prev;
            m.erase(tail->prev->key);
            delnode(oldnode);
            
        }

        Node* newnode = new Node(key,value);
        addnode(newnode);
        m[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */