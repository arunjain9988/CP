#include <stdio.h>    
#include <stdlib.h>
#include<iostream>

using namespace std;
int main () {
    char str[] = "314.14 29.53";
    char* ptr;
    double v1, v2;
    v1 = strtod(str, &ptr);
    cout<<v1<<endl;
    v2 = strtod(ptr, NULL);
    printf("%.2f\n", v1/v2);
    return 0;
}