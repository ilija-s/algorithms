/*
 * Quick Select algorithm for finding k-th smallest element
 * in an unordered list. Uses same approach as quicksort but
 * only sorts one half of the array.
 *
 * Time complexity O(n)
 * Space complexity O(n)
 */ 

#include <iostream>
#include <vector>

using namespace std;

int quickselect(int left, int right, int k, vector<int>& nums){
    // j is the position of last element that is less or equal than pivot
    int j = left;
    for(int i = left + 1; i <= right; i++)
        if(nums[i] <= nums[left])
            swap(nums[++j], nums[i]);

    swap(nums[left], nums[j]);

    /* if the element we are looking for is less than pivot
     * we call quickselect on left part
     * else we call it for the right part
    */
     if(k < j)
        return quickselect(left, j-1, k, nums);
    if(k > j)
        return quickselect(j+1, right, k, nums);
    return nums[k];
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << quickselect(0, n-1, k, nums) << '\n';

    return 0;
}
