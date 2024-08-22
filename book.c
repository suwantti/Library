//book.c
#include "Library_P.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Book* findBook(Library* lib, const char* title);
Member* findMember(Library* lib, const char* name);

Book* book_new(){
    return (Book*)malloc(sizeof(Book));
}

void book_ctor(Book* book,
               const char* title,
               const char* author,
               int isAvailable)
{
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->isAvailable = isAvailable; // 1 = 대출 가능, 0 = 대출 불가능
}

void addBook(Library* lib, const char* title, const char* author) {
   if (findBook(lib, title) != NULL) {
         printf("도서 \"%s\"는 이미 목록에 존재합니다.\n", title);
         return;
   }
    if (lib->bookCount >= 100) {
        printf("도서 목록이 가득 찼습니다.\n");
        return;
    }
    Book* book = &lib->books[lib->bookCount++];

    strncpy(book->title, title, 99);
    book->title[99] = '\0';

    strncpy(book->author, author, 49);
    book->author[49] = '\0';

    book->isAvailable = 1;
    printf("도서 \"%s\"가 추가되었습니다.\n", title);
}

// 도서 검색 함수
Book* findBook(Library* lib, const char* title) {
    for (int i = 0; i < lib->bookCount; ++i) {
        if (strcmp(lib->books[i].title, title) == 0) {
            return &lib->books[i];
        }
    }
    return NULL;
}

// 도서 대출 함수
void borrowBook(Library* lib, const char* memberName, const char* bookTitle) {
    Member* member = findMember(lib, memberName);
    Book* book = findBook(lib, bookTitle);

    if (member == NULL) {
        printf("회원 \"%s\"이 존재하지 않습니다.\n", memberName);
        return;
    }
    if (book == NULL) {
        printf("도서 \"%s\"이 존재하지 않습니다.\n", bookTitle);
        return;
    }
    if (!book->isAvailable) {
        printf("%s님 도서 \"%s\"은 현재 대출 중입니다.\n", memberName,bookTitle);
        return;
    }

    member->borrowedBooks[member->borrowedCount++] = book;
    book->isAvailable = 0;
    printf("회원 \"%s\"님이 도서 \"%s\"을 대출했습니다.\n", memberName, bookTitle);
}

// 도서 반납 함수
void returnBook(Library* lib, const char* memberName, const char* bookTitle) {
    Member* member = findMember(lib, memberName);
    Book* book = findBook(lib, bookTitle);

    if (member == NULL) {
        printf("회원 \"%s\"님이 존재하지 않습니다.\n", memberName);
        return;
    }
    if (book == NULL) {
        printf("도서 \"%s\"님이 존재하지 않습니다.\n", bookTitle);
        return;
    }

    for (int i = 0; i < member->borrowedCount; ++i) {
        if (member->borrowedBooks[i] == book) {
            member->borrowedBooks[i] = member->borrowedBooks[--member->borrowedCount];
            book->isAvailable = 1;
            printf("회원 \"%s\"님이 도서 \"%s\"을 반납했습니다.\n", memberName, bookTitle);
            return;
        }
    }
    printf("회원 \"%s\"님이 도서 \"%s\"을 대출하지 않았습니다.\n", memberName, bookTitle);
}

void displayBooks(const Library* lib) {
    printf("도서 목록\n");
    for (int i = 0; i < lib->bookCount; ++i) {
        printf("제목: %s, 저자: %s, %s\n",
               lib->books[i].title,
               lib->books[i].author,
               lib->books[i].isAvailable ? "대출 가능" : "대출 중");
    }
}

