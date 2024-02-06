#include <iostream>
#include "fisher_yates.h"

void print_array(int ary[], int len){
    for (int i=0; i < len ; i++){
        std:: cout << ary[i] << " ";
    }
    std:: cout << std:: endl;
}

int swap(int * first, int * second){
    int temp= *first; 
    *first= *second ;
    *second= temp;
    return 0;
}

void fisher_yates(int array[], const int length, int (* random_fcn)()) {
  for (int i = 0; i < length -1; i++) {
    int rnd_location = random_fcn() % (length -i);
    swap(& array[i], & array[rnd_location + i]);
  }
}

int non_negative_prefix(int ary[],int length){
    bool result= true;
    int sum=0;
    for (int i=0;i<length;i++){
        sum+= ary[i];
        if (sum<0){
            result=false;
            break;
        }
    }
    return result;
}

int non_positive_prefix(int ary[],int length){
    bool result= true;
    int sum=0;
    for (int i=0;i<length;i++){
        sum+= ary[i];
        if (sum>0){
            result=false;
            break;
        }
    }
    return result;
} 


bool are_arrays_different(int arr1[], int arr2[], int length) {
    for (int i = 0; i < length; ++i) {
        if (arr1[i] != arr2[i]) {
            return true;
        }
    }
    return false;
}