#ifndef CONTAINER_H
#define CONTAINER_H

#include <stdio.h>
#include <iostream>



template <class T>
class Container{
    size_t dydis = 0;
    size_t maxDydis = 1;
    T *hold;
    T *temp;
public:
    Container(){}
    ~Container(){delete hold; delete temp;}

    size_t size();
    void push_back(T*);
    T getLast();
    T& operator[](const size_t &var);
    std::istream& operator>>(std::istream &is);

    class iterator;
    friend class iterator;

    class iterator {

    private:
        Container& ts;
        int index;

    public:
        iterator(Container &x) : ts(x), index(0) {}
        iterator(Container &x, bool) : ts(x), index(ts.dydis) {}

        T* operator++(int) {
            if (index >= ts.dydis)
                throw std::out_of_range("Iterator went out of bounds!");
            return &ts.hold[index++];
        }

        T* operator+(int a) {
            if (index + a > ts.dydis)
                throw std::out_of_range("Iterator went out of bounds!");
            // FIXME
            return ts.v[index+a];
        }

        bool operator!=(const iterator& r_op) const {
            return (index != r_op.index);
        }

        T* current() const {
            return &ts.hold[index];
        }

        T* operator*() const { return current(); }
    };
    iterator begin() { return iterator(*this); }
    iterator end() { return iterator(*this, true); }
};



template <class T>
void Container<T>::push_back(T *var){
    ++dydis;
    if(dydis >=maxDydis){
        temp = hold;
        hold = new T[dydis];
        for (size_t i = 0; i < dydis-1; i++) {
            hold[i] = temp[i];
        }
        hold[dydis-1] = *var;
    }
    else{
        hold[dydis-1] = *var;
    }
}

template <class T>
size_t Container<T>::size(){
    return dydis;
}

template <class T>
T& Container<T>::operator[](const size_t &var){
    return hold[var];
}



#endif /* Container_H */