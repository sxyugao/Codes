class LRUCache {
  private:
#define N 10000
#define head cache[N + 1]
#define tail cache[N + 2]

    int capacity, siz;
    struct Node {
        int pre = -1, nxt = -1, val = -1;
    } cache[N + 5];

    void remove(int key) {
        if (cache[key].val == -1)
            return;
        cache[cache[key].pre].nxt = cache[key].nxt;
        cache[cache[key].nxt].pre = cache[key].pre;
        cache[key].pre = cache[key].nxt = cache[key].val = -1;
    }

    void add(const int &key, const int &val) {
        cache[key].nxt = head.nxt;
        cache[key].pre = N + 1;
        cache[key].val = val;
        cache[head.nxt].pre = key;
        head.nxt = key;
    }

  public:
    LRUCache(const int &capacity) {
        this->capacity = capacity;
        siz = 0;
        head.nxt = N + 2;
        tail.pre = N + 1;
    }

    int get(const int &key) {
        int res = cache[key].val;
        if (res != -1) {
            remove(key);
            add(key, res);
        }
        return res;
    }

    void put(const int &key, const int &value) {
        if (cache[key].val == -1) {
            if (siz < capacity) {
                add(key, value);
                siz += 1;
                return;
            }
            remove(tail.pre);
            add(key, value);
            return;
        }
        remove(key);
        add(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */