// criado por Marco Aurélio
// 10/2016


#ifndef MY_PTR_H
#define MY_PTR_H

template<class T>
class my_ptr{
public:
    my_ptr(int s);
    my_ptr();

    void del();

    T *ptr;
    int size;
};

template<class T> my_ptr<T>::my_ptr(int s){
    ptr = new T[s];
    size = s;
}

template<class T> my_ptr<T>::my_ptr(){
    ptr = 0;
    size = 0;
}

template<class T> void my_ptr<T>::del(){
    delete[] ptr;
    ptr = 0;
    size = 0;
}

typedef my_ptr<double> double_ptr;

#endif
