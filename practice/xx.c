#include <stdio.h> 
int main() 
{ 
  char *s[] = { "knowledge","is","power"}; // array of pointers to strings
  char **p; 
  p = s;
  printf("%s\n", *p+2);
  // printf("%s\n", p+1);
  // printf("%s\n", p+2);
  // printf("%s ", ++*p); // prints 
  // printf("%s ", *p++); 
  // printf("%s ", ++*p); 
  
  return 0; 
}