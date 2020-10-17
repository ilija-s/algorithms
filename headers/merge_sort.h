#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

namespace asp {
    // merge function is used for merging 2 sorted arrays
    template<typename Type>
        static void merge(Type *array, int left, int mid, int right){
            // uses temporary array for storing sorted elements
            Type tempArr[right - left + 1];
            int i = 0;
            int j = left;
            int k = mid + 1;
            while(j <= mid && k <= right){
                if(array[j] < array[k]){
                    tempArr[i++] = array[j++];
                }
                else {
                    tempArr[i++] = array[k++];
                }
            }
            while(j <= mid){
                tempArr[i++] = array[j++];
            }
            while(k <= right){
                tempArr[i++] = array[k++];
            }
            // copying sorted array to the original one
            int counter;
            for(counter = 0; counter < i; counter++){
                array[counter + left] = tempArr[counter];
            }

            return;
        }

        // merge sort recursive function
    template<typename Type>
        static void merge_sort_(Type *array, int left, int right){
            /*
             * using left + (right - left) / 2 instead of (left + right)/2
             * to avoid int overflow
             */
            int mid = left + (right - left) / 2;
                
            // sorting left, then right and in the end we merge them
            if(left < right){
                merge_sort_(array, left, mid);
                merge_sort_(array, mid + 1, right);
                merge(array, left, mid, right);
            }
        }
}

#endif