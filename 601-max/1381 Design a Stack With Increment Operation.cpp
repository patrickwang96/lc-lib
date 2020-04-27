#include "header.h"
// https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack {
private:
    int maxSize;
    int buffer[10000];
    // vector<int> buffer(10000);
    int head;
    int tail;
    int used;
    
    inline int addStep(int ptr, int step) {
        ptr += step;
        return ptr % maxSize;
    }
    inline int reduceStep(int ptr, int step) {
        ptr -= step;
        while (ptr < 0) ptr += maxSize;
        return ptr;
    }
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        this->head = 0;
        this->tail = 0;
        this->used = 0;
    }
    
    void push(int x) {
        if (used == maxSize) return ; // full stack
        this->buffer[this->head] = x;
        if (this->head == 0) {
            this->head = this->maxSize - 1;
        }else {
            this->head --;
        }
        this->used++;
        return ;
    }
    
    int pop() {
        if (used == 0) return -1;
        if (this->head == this->maxSize - 1) {
            this->head = 0;
            used--;
        }
        else {
            this->head++;
            used--;
        }
        return this->buffer[this->head];
        
    }
    
    void increment(int k, int val) {
        if (used <= k) k = used;
        for (int i = 0 ; i < k; i++) {
            this->buffer[reduceStep(this->tail, i)] += val;
        }
        
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */