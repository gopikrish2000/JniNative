//
// Created by Gopi on 22/03/18.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template<class T>
class Stack {
private:
    vector<T> elems;    // elements

public:
    void push(T const &);  // push element
    void pop();               // pop element
    T top() const;            // return top element

    bool empty() const {      // return true if empty.
        return elems.empty();
    }
};

template<class T>
void Stack<T>::push(T const &elem) {
    // append copy of passed element
    elems.push_back(elem);
}

template<class T>
void Stack<T>::pop() {
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }

    // remove last element
    elems.pop_back();
}

template<class T>
T Stack<T>::top() const {
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }

    // return copy of last element
    return elems.back();
}

void my_int_func(int x) {
    printf("%d\n", x);
}

// A sample comparator function that is used
// for sorting an integer array in ascending order.
// To sort any array for any other data type and/or
// criteria, all we need to do is write more compare
// functions.  And we can use the same qsort()
int compare(const void *a, const void *b) {  // void* can be typecasted to any type object.
    return (*(int *) a - *(int *) b);
}

void wrapperFunctionPointer(void (*foo)(int)){
    (*foo)(2);
}

int main() {
    try {
        Stack<int> intStack;  // stack of ints
        Stack<string> stringStack;    // stack of strings

        // manipulate int stack
        intStack.push(7);
        cout << intStack.top() << endl;

        // manipulate string stack
        stringStack.push("hello");
        cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();

        // Vector
        vector<int> vec;
        int i;
        cout << "vector size = " << vec.size() << endl;  // display the original size of vec
        for (i = 0; i < 5; i++) {
            vec.push_back(i); // push 5 values into the vector
        }
        cout << "extended vector size = " << vec.size() << endl;  // display extended size of vec

        for (i = 0; i < 5; i++) {  // access 5 values from the vector
            cout << "value of vec [" << i << "] = " << vec[i] << endl;
        }

        // use iterator to access the values
        vector<int>::iterator v = vec.begin();
        while (v != vec.end()) {
            cout << "value of v = " << *v << endl;
            v++;
        }
    } catch (exception const &ex) {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }

    void (*foo)(int);  // foo is pointer which takes int as parameter & returns void.
    foo = &my_int_func;
//    (*foo)(2); // prints value 2
    wrapperFunctionPointer(foo);


    int arr[] = {10, 5, 15, 12, 90, 80};
    int n = sizeof(arr) / sizeof(arr[0]), i;
    qsort(arr, n, sizeof(int), compare);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
