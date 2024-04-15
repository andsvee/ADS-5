// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    T* stackArray;
    int topper;
 public:
    TStack() : topper(-1) {
      stackArray = new T[size];
    }
    void pop() {
      if (topper >= 0)
        topper--;
    }
    void push(T item) {
      if (topper < size - 1)
        stackArray[++topper] = item;
    }
    T get() const {
      return stackArray[topper];
    }
    bool checkEmpty() const {
      return topper == -1;
    }
};

#endif  // INCLUDE_TSTACK_H_
