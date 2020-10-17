#ifndef __COMMON_FUNC_H__
#define __COMMON_FUNC_H__

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define max_(a, b) ((a > b) ? a : b)
#define MAX 10
namespace asp {
    // function that prints the elements of the array
    template<typename Type>
        static void print_array(Type *array, int n){
            int i;
            for(i = 0; i < n; i++)
                printf("%d ", array[i]);
        }
}


#endif