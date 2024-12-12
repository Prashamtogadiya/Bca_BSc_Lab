#include <stdio.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    char publication[50];
    float price;
};

int main() {
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);
    //review
    struct Book books[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter details for book %d:\n", i + 1);
        printf("Title: ");
        scanf("%s", books[i].title);
        printf("Author: ");
        scanf("%s", books[i].author);
        printf("Publication: ");
        scanf(" %s", books[i].publication);
        printf("Price: ");
        scanf("%f", &books[i].price);
    }

    printf("\nDisplaying book details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nBook %d\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Publication: %s\n", books[i].publication);
        printf("Price: %.2f\n", books[i].price);
    }

    return 0;
}
