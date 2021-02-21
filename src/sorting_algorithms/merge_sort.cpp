#include "../headers/merge_sort.h"
#include "../headers/common_functions.h"

using namespace asp;

int main(){
    int arr[MAX];

    int i = 0;
    for (i = 0; i < MAX; i++){
        arr[i] = rand()%100;
    }

    printf("Before sorting: ");
    print_array(arr, MAX);
    putchar('\n');

    merge_sort_<int>(arr, 0, MAX - 1);

    printf("After sorting: ");
    print_array(arr, MAX);
    putchar('\n');

    return 0;
}
