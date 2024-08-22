//main.c
#include "Library.h"
#include <stdio.h>

int main() {
    Library library = {0};

    // 도서 및 회원 추가
    addBook(&library, "1984", "George Orwell");
    addBook(&library, "To Kill a Mockingbird", "Harper Lee");

    addMember(&library, "suwan");
    addMember(&library, "jaehoon");
    addMember(&library, "nohyeon");
    printf("\n\n");
    
    // 도서 대출 및 반납
    borrowBook(&library, "suwan", "1984");
    borrowBook(&library, "jaehoon", "To Kill a Mockingbird");
    borrowBook(&library, "nohyeon", "To Kill a Mockingbird");
    borrowBook(&library, "suwan", "To Kill a Mockingbird");
    printf("\n\n");
    
    // 정보 출력
    displayBooks(&library);
    printf("\n\n");
    displayMembers(&library);

    return 0;
}