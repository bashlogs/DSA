#include<stdio.h>
#include<string.h>

struct MyStruct{
  char title[50];
  char author[50];
  int book_id;
};

struct MyStruct2{
  char Name[50];
  int roll_no;
  int age;
  struct birthdate{
    int dd;
    int mm;
    int yyyy;
  };
};

void display(struct MyStruct a){
  printf("Book Name = %s\n",a.title);
  printf("Author Name = %u\n",&a.author);
  printf("Book No. = %d\n\n",a.book_id);
}

void display2(struct MyStruct2 b, struct birthdate b1){
  printf("Personal Info:\n");
  printf("Name: %s\n",b.Name);
  printf("Age : %d\n",b.roll_no);
  printf("BirthDate: %d-%d-%d",b1.dd,b1.mm,b1.yyyy);
}

int main(){
  struct MyStruct s1 = {"New Book", "Mayur Khadde", 1};
  struct MyStruct s2 = {"New Book1", "Mayur1 Khadde1", 2};
  struct MyStruct2 p1 = {"Mayur Khadde",194029,17};
  struct birthdate b1 = {14,6,2004};
  display(s1);
  display(s2);
  display2(p1,b1);
  return 0;
}


