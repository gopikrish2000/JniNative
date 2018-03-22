//
// Created by Gopi on 21/03/18.
//

#include <iostream>

using namespace std;


void doFirst() {
    enum color {
        red,
        green = 5,
        blue   // by default enum starts with zero , red = 0 , green = 1 ( but assigned 5 , so 5) , blue (6)
    };
    int a[5][2] = {{0, 0},
                   {1, 2},
                   {2, 4},
                   {3, 6},
                   {4, 8}};
    color myColor = green;
    cout << blue + " \n";
}

int sum(int a, int b = 20) {  // default value not required everytime.
    return a + b;
}

void referenceVsPointer() {  // Rest reference similar to pointer
    int i;
    int &r = i;  // declare reference variables  1.  A reference must be initialized when it is created. Pointers can be initialized at any time.
    // 2. Once a reference is initialized to an object, it cannot be changed to refer to another object. Pointers can be pointed to another object at any time.  3. You cannot have NULL references. You must always be able to assume that a reference is connected to a legitimate piece of storage.
    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r << endl;  // same value
}

class Box {
public:
    static int firstStaticVar;
    double length;         // Length of a box
    double breadth;        // Breadth of a box
    double height;         // Height of a box

    double getVolume(void);  // Member functions declaration
    double area() {
        return length * breadth;
    }

    Box(); // constructor
    Box(double len, double bred);

    Box(double len, double bred, double height): length(len), breadth(bred), height(height){
    }

    ~Box() {  // destructor
        length = -1;
        double *p = &length;
        delete p;  // free memory
    }

    Box(const Box &obj) {  // copy constructor with reference.
        length = obj.length;
        breadth = obj.breadth;
//        height = obj.height;  // gives random value
        height = 1;
    }

    Box operator+(const Box &obj){  // or can create n return a new object as well.
        this->length += obj.length;
        this->breadth += obj.breadth;
        this->height += obj.height;
    }

    int compare(Box box) {
        return this->getVolume() > box.getVolume(); //this pointer
    }


private:
    double privateMethod();
};

Box::Box() {
    // do nothing
}

Box::Box(double len, double bred) {
    length = len;
    breadth = bred;
}

double Box::getVolume(void) {  //Implementations of Box function of Box defined in Box.
    return length * breadth * height;
}

int Box::firstStaticVar = 66;  // static initialization.

inline int Max(int x, int y) {  // like macro expands
    return (x > y) ? x : y;
}

// main() is where program execution begins.
int main() {
    doFirst();
    sum(10);
    Box box1;
    Box box2(1, 11);
    Box box3(box2);  // calls copy constructor
    box1.length = 20;
    box1.breadth = 30;
    box1.height = 40;
    cout << "volume " << box1.getVolume() << endl;
    cout << "volume " << box3.getVolume() << endl;

    Box box5 = box3;  // also calls copy constructor

    Box *ptrBox;                // Declare pointer to a class.
    ptrBox = &box1;
    // Now try to access a member using member access operator
    cout << "Volume of Box1: " << ptrBox->getVolume() << endl;

    Box *ptrBoxOne = new Box(33, 22, 11);
    Box *ptrBoxTwo = new Box(1, 2, 3);
    ((*ptrBoxOne) + *ptrBoxTwo);   //operator overloading.
    cout << (*ptrBoxOne).getVolume() << endl;

    Box* myBoxArray = new Box[4];
    delete [] myBoxArray; // Delete array  of n dimentional same syntax

    double *pvaluePtr  = NULL;      // Pointer initialized with null
    pvaluePtr = new double[3][4];
    return 0;
}






