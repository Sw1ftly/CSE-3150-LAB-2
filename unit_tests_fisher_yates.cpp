#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fisher_yates.h"
#include <cstdlib>


int ary_0[]={};
int ary_1[]={1,-1};

int first1 = -99 ; 
int second1 = -4 ;
int save_first1=first1;
int save_second1=second1;

int i= swap(&first1, &second1);


TEST_CASE("FISHER_YATES"){
    SUBCASE("swap"){
        CHECK_EQ(save_first1,second1);
        CHECK_EQ(first1,save_second1);
    } 
    SUBCASE("fisher_yates random array") {
    const int n = 1000;
        int arrayvalues[2*n];
        int arraycopy[2*n];

        for (int i = 0; i < n; ++i) {
            arrayvalues[i] = 1;
            arrayvalues[i + n] = -1;
        }

        memcpy(arraycopy, arrayvalues, sizeof(arrayvalues)); 
        fisher_yates(arrayvalues, 2*n, rand); 
        CHECK(are_arrays_different(arrayvalues, arraycopy, 2*n));
    }
    

    SUBCASE("fisher_yates array length stays same") {
        int arr[] = {1,2,3,4,5,6,7,8,9,10};
        int original_length = sizeof(arr) / sizeof(arr[0]);
        fisher_yates(arr, original_length, rand);
        CHECK_EQ(original_length, sizeof(arr) / sizeof(arr[0]));
    }
};


