// Here are some basic pointer programs using *structures* in C:

// ---

// ### *Basic Questions on Pointers with Structures*








// 1. *Access and Modify Structure Members Using a Pointer*
//    c
   #include <stdio.h>
   struct Student {
       int id;
       char name[50];
       float marks;
   };

   int main() {
       struct Student s = {1, "John", 85.5};
       struct Student *ptr = &s;

       // Accessing structure members using pointer
       printf("Student ID: %d\n", ptr->id);
       printf("Student Name: %s\n", ptr->name);
       printf("Student Marks: %.2f\n", ptr->marks);

       // Modifying structure members using pointer
       ptr->marks = 90.0;
       printf("Updated Marks: %.2f\n", ptr->marks);

       return 0;
   }
   

// ---

// 2. *Swap Two Structures Using Pointers*
//    c
//    #include <stdio.h>
//    struct Point {
//        int x, y;
//    };

//    void swap(struct Point *p1, struct Point *p2) {
//        struct Point temp = *p1;
//        *p1 = *p2;
//        *p2 = temp;
//    }

//    int main() {
//        struct Point p1 = {1, 2};
//        struct Point p2 = {3, 4};

//        printf("Before Swap: p1(%d, %d), p2(%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
//        swap(&p1, &p2);
//        printf("After Swap: p1(%d, %d), p2(%d, %d)\n", p1.x, p1.y, p2.x, p2.y);

//        return 0;
//    }
   

// ---

// 3. *Dynamic Memory Allocation for Structures*
   
   #include <stdio.h>
   #include <stdlib.h>
   struct Employee {
       int id;//4
       char name[50];
       float salary;
   };

   int main() {
       struct Employee *emp = (struct Employee *)malloc(sizeof(struct Employee));


       // Input employee details
       printf("Enter Employee ID: ");
       scanf("%d", &emp->id);
       printf("Enter Employee Name: ");
       scanf("%s", emp->name);
       printf("Enter Employee Salary: ");
       scanf("%f", &emp->salary);

       // Display employee details
       printf("\nEmployee Details:\n");
       printf("ID: %d\n", emp->id);
       printf("Name: %s\n", emp->name);
       printf("Salary: %.2f\n", emp->salary);

       free(emp); // Free allocated memory
       return 0;
   }
   

// ---

// 4. *Array of Structures Using Pointers*
//    c
//    #include <stdio.h>
//    struct Student {
//        int id;
//        char name[50];
//        float marks;
//    };

//    void displayStudents(struct Student *students, int n) {
//        for (int i = 0; i < n; i++) {
//            printf("Student %d:\n", i + 1);
//            printf("ID: %d\n", (students + i)->id);
//            printf("Name: %s\n", (students + i)->name);
//            printf("Marks: %.2f\n", (students + i)->marks);
//        }
//    }

//    int main() {
//        int n = 3;
//        struct Student students[] = {
//            {1, "Alice", 88.5},
//            {2, "Bob", 92.3},
//            {3, "Charlie", 79.0}
//        };

//        displayStudents(students, n);
//        return 0;
//    }
   

// ---

// 5. *Pointer to Structure and Structure Within Structure*
//    c
//    #include <stdio.h>
//    struct Address {
//        char city[50];
//        int pincode;
//    };

//    struct Employee {
//        int id;
//        char name[50];
//        struct Address address;
//    };

//    int main() {
//        struct Employee emp = {1, "John Doe", {"New York", 12345}};
//        struct Employee *ptr = &emp;

//        // Access members of nested structure using pointer
//        printf("Employee ID: %d\n", ptr->id);
//        printf("Employee Name: %s\n", ptr->name);
//        printf("City: %s\n", ptr->address.city);
//        printf("Pincode: %d\n", ptr->address.pincode);

//        return 0;
//    }
   //
//
// ---

// 6. *Pass Structure to a Function Using Pointer*
//    c
//    #include <stdio.h>
//    struct Rectangle {
//        int length;
//        int width;
//    };

//    void calculateArea(struct Rectangle *rect) {
//        int area = rect->length * rect->width;
//        printf("Area of Rectangle: %d\n", area);
//    }

//    int main() {
//        struct Rectangle rect = {10, 5};
//        calculateArea(&rect);
//        return 0;
//    }
   

// ---

// 7. *Modify Structure Members Using Function*
//    c
//    #include <stdio.h>
//    struct Account {
//        int accountNumber;
//        float balance;
//    };

//    void deposit(struct Account *acc, float amount) {
//        acc->balance += amount;
//    }

//    int main() {
//        struct Account acc = {101, 5000.0};

//        printf("Before Deposit:\n");
//        printf("Account Number: %d\n", acc.accountNumber);
//        printf("Balance: %.2f\n", acc.balance);

//        deposit(&acc, 1500.0);

//        printf("\nAfter Deposit:\n");
//        printf("Account Number: %d\n", acc.accountNumber);
//        printf("Balance: %.2f\n", acc.balance);

//        return 0;
//    }
   

// ---

// Would you like further explanations or examples on any specific topic?