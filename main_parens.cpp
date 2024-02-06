#include <cstdlib>
#include <iostream>
#include "fisher_yates.h"

using namespace std;

int main(){
    

    int n=100 ;  // the larger n the less likely a well balanced list
    

    int arrayvalues[2*n];

    for (int i=0; i<n; i++){
        arrayvalues[i]= 1;
    }
    for (int i=0; i<n; i++){
        arrayvalues[i+n]= -1;
    }

    int balanced=0;
    int total=0;
    srand(time(NULL));
    for (int i=0; i<10000; i++ ){
        fisher_yates(arrayvalues,2*n,rand);
        total++;
        
        if (non_negative_prefix(arrayvalues,sizeof(arrayvalues)/sizeof(arrayvalues[0])) == true 
            || non_positive_prefix(arrayvalues,sizeof(arrayvalues)/sizeof(arrayvalues[0])) == true)
            {
            balanced++;
            }
    }
    std:: cout << "balanced: " << balanced << std:: endl;
    std:: cout << "total: " << total << std:: endl;
    
}