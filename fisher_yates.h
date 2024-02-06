#ifndef _FISHER_YATES_H_
#define _FISHER_YATES_H_

void print_array(int ary[], int len);
int swap(int * first, int * second);
void fisher_yates(int array[], const int length, int (* random_fcn)());
int non_positive_prefix(int ary[],int length);
int non_negative_prefix(int ary[],int length);
bool are_arrays_different(int arr1[], int arr2[], int length);
#endif