//member.c
#include "Library_P.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 회원 메모리 할당
Member* member_new()
{
    return (Member*)malloc(sizeof(Member));
}

// 회원 생성자
void member_ctor(Member* member, 
                 const char* name,
                 Book* borrowedBooks[10],
                 int borrowedCount)
{
    strcpy(member->name, name);

    for(int i = 0; i < borrowedCount; i++)
    {
        member-> borrowedBooks[i] = borrowedBooks[i];
    }

    member -> borrowedCount = borrowedCount;

    for(int i = borrowedCount; i < 10; i++)
    {
        member-> borrowedBooks[i] = NULL;
    }
}

// 회원 추가 함수
void addMember(Library* lib, const char* name) {
    if (lib->memberCount >= 100) {
        printf("회원 목록이 가득 찼습니다.\n");
        return;
   }

   Member* member = &lib->members[lib->memberCount++];

   strncpy(member->name, name, 19);
   member->name[19] = '\0';

   member->borrowedCount = 0;
   for(int i = 0; i < 10; i++)
   {
        member->borrowedBooks[i]=NULL;
   }

   printf("회원 \"%s\"이 추가되었습니다.\n", name);
}

// 회원 검색 함수
Member* findMember(Library* lib, const char* name) {
    for (int i = 0; i < lib->memberCount; ++i) {
        if (strcmp(lib->members[i].name, name) == 0) {
            return &lib->members[i];
        }
    }
    return NULL;
}

// 회원 목록 출력 함수
void displayMembers(const Library* lib) 
{
    printf("회원 목록\n");
    for (int i = 0; i < lib->memberCount; ++i) {
        printf("\t회원 이름: %s\n", lib->members[i].name);
        //printf("대출 도서:\n");
        for (int j = 0; j < lib->members[i].borrowedCount; ++j) {
            printf("\t대출 중인 도서 제목: %s\n\n", lib->members[i].borrowedBooks[j]->title);
        }
    }
}