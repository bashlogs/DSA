#include<stdio.h>
#include<string.h>

union test1{
  int x;
  int y;
};

union test2{
  int x;
  float y;
  char name[50];
};

int main(){
  union test1 t1;
  t1.x = 10;
  printf("Value of X = %d and Y = %d \n",t1.x,t1.y);
  t1.y = 20;
  printf("Value of X = %d and Y = %d \n\n",t1.x,t1.y);

  union test2 t2;
  t2.x = 10;
  printf("Value of X = %d, Y = %f and Name = %s",t2.x,t2.y,t2.name);
  t2.y = 20.5;
  printf("Value of X = %d, Y = %f and Name = %s \n",t2.x,t2.y,t2.name);
  //t2.name = "Mayur Khadde";
  strcpy(t2.name, "Mayur Khadde");
  printf("Value of X = %d, Y = %f and Name = %s \n\n",t2.x,t2.y,t2.name);

  t2.x = 10;
  t2.y = 20.5;
  strcpy(t2.name, "Mayur Khadde");

  printf("After Displaying all at once");
  printf("\nValue of x = %d",t2.x);
  printf("\nValue of y = %f",t2.y);
  printf("\nValue of Name = %s",t2.name);
  return 0;
}
