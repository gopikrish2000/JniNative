//
// Created by Gopi on 21/03/18.
//

#include <stdio.h>
#include <string.h>

struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
    char oneChar;
};

/* function declaration */
void printBook(struct Books *book);

int main() {

    struct Books Book1;        /* Declare Book1 of type Book */
    struct Books Book2;        /* Declare Book2 of type Book */

    /* book 1 specification */
    strcpy(Book1.title, "C Programming");
//   Book1.title = "GOPI PROGRAMMING";  // is wrong bcoz its like final variables
    strcpy(Book1.author, "Nuha Ali");
    strcpy(Book1.subject, "C Programming Tutorial");
    Book1.book_id = 6495407;
    Book1.oneChar = 'f';
    Book1.oneChar = 'g';


    /* book 2 specification */
    strcpy(Book2.title, "Telecom Billing");
    strcpy(Book2.author, "Zara Ali");
    strcpy(Book2.subject, "Telecom Billing Tutorial");
    Book2.book_id = 6495700;

    Book2.book_id = 222;

    /* print Book1 info by passing address of Book1 */
    printBook(&Book1);

    /* print Book2 info by passing address of Book2 */
    printBook(&Book2);

    return 0;
}

void bothPointersSame(){
    int a = 10;
    int ary[] = {4,5,6};

    int *aP = &a;
    int *aryP = ary;

    printf("ap %d \n", *aP);
    printf("aryP first %d \n", *aryP);

    printf("ap1 %d \n", *(++aP));
    printf("aryP1 first %d \n", *(++aryP));
}

void differenceBtwArrayNPointer(){
    int MAX = 3;
    int  var[MAX] = {10, 100, 200};
    *var = 2;
    int *p = var;
   for (int i = 0; i < MAX; i++) {
       if( i == 0){
           *p = 400;
       }
       printf("%d", *(p++));    // This is a correct syntax
      //var++;                  // This is incorrect.  Array pointer cannot be changed from start of array.
       *(var + 2) = 500;        // valid statement
   }
}

void printBook(struct Books *book) {

    printf("Book title : %s\n", book->title);
    printf("Book author : %s\n", book->author);
    printf("Book subject : %s\n", book->subject);
    printf("Book book_id : %d\n", book->book_id);
}

