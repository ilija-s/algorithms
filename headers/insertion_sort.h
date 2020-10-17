#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

namespace asp {
    template<typename T>
        static void insertion_sort(T *array, int n){
            int i;
            int j;
            for(i = 0; i < n; i++){
                T curr = array[i];
                j = i - 1;
                for(j = i - 1; j >= 0 && array[j] > curr; j--){
                    array[j + 1] = array[j];
                }
                array[j + 1] = curr;
            }
        }
}

#endif