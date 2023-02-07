template<typename T>
class vector {

    T *storage;
    unsigned int length, cap;

    void resizeStorage() {
        int *copy = new T[cap];
        for (unsigned int i = 0 ; i < length, ++i) {
            copy[i] = storage[i]; 
        }
        delete [] storage;
        storage = copy
    }

    public:
    vector(unsigned int cap = 1): length(0), cap(cap), storage(new T[cap]) { 
        if (!cap)
            cap = 1;
    }

    unsigned int size() {
        return this.length;
    }

    unsigned int capacity() {
        return this.cap;
    }

    T& operator[](int index) {
        return storage[index];
    }

    const T& operator[](int index) const { 
        return storage[index];
    }

    void push_back(T element) {
        reserve(++length);
        storage[length] = element;
    }

    void reserve(int capacity) { 
        if(cap >= capacity) {
            return;
        }
        while(cap < capacity) { 
            cap *= 2;
        }
        resizeStorage();
    }

    virtual ~vector() { 
        delete[] storage;
    }

}
