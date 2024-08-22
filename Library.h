// Library.h
// 전방 선언
#include "Library_P.h"

struct Book;
struct Member;
struct Library;

// 메모리 할당자
struct Book* book_new();
struct Member* member_new();
struct Library* library_new();

// 생성자
void book_ctor(struct Book*, 
               const char*,
               const char*,
               int);

void member_ctor(struct Member*,
                 const char*, 
                 const char*, 
                 int);

void library_ctor(struct Library*, 
                  char*,
                  char*, 
                  int,
                  int);

// 소멸자
void book_dtor(struct Book*);
void member_dtor(struct Member*);
void library_dtor(struct Library*);

// 행위 함수
void addBook(struct Library*, const char*, const char*);
void addMember(struct Library*, const char*);
void findBook(struct Library*, const char*);
void findMember(struct Library*, const char*);
void borrowBook(struct Library*, const char*, const char*);
void returnBook(struct Library*, const char*, const char*);
void displayBooks(struct Library*);
void displayMembers(struct Library*);