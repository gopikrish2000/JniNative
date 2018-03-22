//
// Created by Gopi on 22/03/18.
//

#include <iostream>

using namespace std;

const int SIZE = 10;

// Base class Shape
class Shape {
   public:
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }
    Shape(){}
    Shape(int wid, int hei = 1): width(wid), height(hei){
    }
    virtual int getDifferentArea() = 0; // pure virtual method so must subclass.  acts like interface.

   protected:
      int width;
      int height;
};

// Base class PaintCost
class PaintCost {
   public:
      virtual int getCost(int area) {  // to get child implementation
         return area * 70;
      }
};

// Derived class
class Rectangle: public Shape, public PaintCost {
   public:
    Rectangle(){}
    Rectangle(int wid, int hei) : Shape(wid, hei) {}

    int getArea() {
         return (width * height);
      }
    int getCost(int area) {
         return area * 70;
      }

    int getDifferentArea(){  // pure virtul function must be implemented.
        return 10 * 100;
    }
};


class safearay {
   private:
      int arr[SIZE];

   public:
      safearay() {
         register int i;
         for(i = 0; i < SIZE; i++) {
           arr[i] = i;
         }
      }

      int &operator[](int i) {
         if( i > SIZE ) {
            cout << "Index out of bounds" <<endl;
            return arr[0]; // return first element.
         }
         return arr[i];
      }
};

namespace first_space {
   void func() {
      cout << "Inside first_space" << endl;
   }
}

// second name space
namespace second_space {
   void func() {
      cout << "Inside second_space" << endl;
   }
}

template <typename T>  // Generics
inline T const& Max (T const& a, T const& b) {
   return a < b ? b:a;
}

int main(void) {
   Rectangle Rect;
   int area;

   Rect.setWidth(5);
   Rect.setHeight(7);

   area = Rect.getArea();

   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   // Print the total cost of painting
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;
    Rect.getDifferentArea();

    safearay A;

   cout << "Value of A[2] : " << A[2] <<endl; // correct val.
    try {
        cout << "Value of A[12] : " << A[12] << endl;  // Index out of bounds
    }catch(std::exception& e) {  // super exception
    }

    first_space::func();
    second_space::func();

    int i = 39;
   int j = 20;
   cout << "Max(i, j): " << Max(i, j) << endl;

   double f1 = 13.5;
   double f2 = 20.7;
   cout << "Max(f1, f2): " << Max(f1, f2) << endl;
   return 0;
}
