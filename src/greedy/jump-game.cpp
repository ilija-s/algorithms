#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canJump(vector<int>& nums){
    if(nums.size() == 1)
        return true;
    for(int i = 0; i < nums.size();){
        if(nums[i] == 0)
            return false;
        int cnt = nums[i];
        int highestJump = 0;
        int index = 0;
        cout << "while\n";
        while(cnt){
            if(nums[i+cnt] > highestJump){
                highestJump = nums[i+cnt];
                index = cnt;
            }
            cnt--;
        }
        i += index;
    }
    return true;
}

int main(){
    vector<int> nums = {3,2,1,0,4};

    if(canJump(nums))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    

    return 0;
}