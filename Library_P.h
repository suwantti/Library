//Library_P.h
typedef struct{
    char title[100];
    char author[50];
    int isAvailable;
} Book;

typedef struct {
    char name[20];
    Book* borrowedBooks[10];
    int borrowedCount;
} Member;

typedef struct {
    Book books[100];
    Member members[100];
    int bookCount;
    int memberCount;
} Library;

