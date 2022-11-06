#include<stdio.h>
struct MyStruct{
  char title[50];
  char author[50];
  int book_id;
};

void display(struct MyStruct a){
  printf("Book Name = %s\n",a.title);
  printf("Author Name = %s\n",a.author);
  printf("Book No. = %d\n",a.book_id);
}

int main(){
  struct MyStruct s1 = {"New Book", "Mayur Khadde", 1};
  struct MyStruct s2 = {"New Book1", "Mayur1 Khadde1", 2};
  display(s1);
  display(s2);
  return 0;
}
