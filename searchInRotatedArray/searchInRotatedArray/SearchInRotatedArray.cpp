#include<iostream>
#include<vector>
#include<string>
using namespace std;

int search(vector<int>& nums, int target);
int binarySearch(vector<int>& nums, vector<int>::iterator left, vector<int>::iterator rignt, int target);

int main(){
    

    cout << "Please input the roated array seperated with enter and end with 'end'." << endl;
    vector<int> nums1, nums2;

    nums1 = {4, 5, 6, 7, 1, 2, 3};
    nums1 = { 7, 1, 2, 3, 4, 5, 6 };
    cout << search(nums1, 1) << search(nums2, 2) << endl;

    return 0;
}

int search(vector<int>& nums, int target) {
    int len = nums.end() - nums.begin();
    int min = nums[0];
    vector<int>::iterator minIndex = nums.begin();

    for (vector<int>::iterator iter = nums.begin(); iter < nums.end(); iter++){
        if (min > *iter){
            min = *iter;
            minIndex = iter;
        }
    }

    if (minIndex != nums.begin()){
        if (target >= *minIndex && target < nums[len - 1]){
            //binary search   (minIndex,len-1) target
            return binarySearch(nums, minIndex, nums.begin() + (len - 1), target);
        }
        else{
            //binary search (begin,minIndex-1) target
            return binarySearch(nums, nums.begin(), minIndex - 1, target);
        }
    }
    else{
        //binary search (begin ,end) target
        return binarySearch(nums, nums.begin(), nums.end() - 1, target);
    }
}

int binarySearch(vector<int>& nums, vector<int>::iterator left, vector<int>::iterator rignt, int target){
    if ((right - nums.begin()) == (left - nums.begin())){
        if (target != *left){
            return -1;
        }
        else{
            return left - nums.begin();
        }
    }
    else{
        vector<int>::iterator mid = left + (right - left) / 2;
        if (target == *mid){
            return mid - nums.begin();
        }
        else if (target > *mid){
            return binarySearch(nums, mid, right, target);
        }
        else(target < *mid){
            return binarySearch(nums, left, mid, target);
        }
    }
}