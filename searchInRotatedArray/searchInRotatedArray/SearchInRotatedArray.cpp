#include<iostream>
#include<vector>
#include<string>
#include<array>
using namespace std;

//int search(vector<int>& nums, int target);
//int binarySearch(vector<int>& nums, vector<int>::iterator left, vector<int>::iterator rignt, int target);
int search(vector<int> A, int n, int target);

int main(){
    

    cout << "Please input the roated array seperated with enter and end with 'end'." << endl;
    vector<int> nums1, nums2;
    nums1 = {4, 5, 6, 7, 1, 2, 3};
    nums2 = { 7, 1, 2, 3, 4, 5, 6 };
    cout << search(nums1, 6, 1) << endl;
    cout << search(nums1, 6, 2) << endl;
    cout << search(nums1, 6, 3) << endl;
    cout << search(nums1, 6, 4) << endl;
    cout << search(nums1, 6, 5) << endl;
    cout << search(nums1, 6, 6) << endl;

    cout << search(nums2, 6, 2) << endl;

    return 0;
}
int search(vector<int> A, int n, int target) {
        int first = 0, last = n;
        while (first != last) {
                const int mid = (first + last) / 2;
                if (A[mid] == target)
                    return mid;
                if (A[first] <= A[mid]) {
                        if (A[first] <= target && target < A[mid])
                            last = mid;
                        else
                        first = mid + 1;
                }
                else {
                        if (A[mid] < target && target <= A[last - 1])
                            first = mid + 1;
                        else
                        last = mid;
                }
        }
        if (target == A[first]){
            return first;
        }
        return -1;
}

//int search(vector<int>& nums, int target) {
//    int len = nums.end() - nums.begin();
//    int min = nums[0];
//    vector<int>::iterator minIndex = nums.begin();
//
//    for (vector<int>::iterator iter = nums.begin(); iter < nums.end(); iter++){
//        if (min > *iter){
//            min = *iter;
//            minIndex = iter;
//        }
//    }
//
//    if (minIndex != nums.begin()){
//        if (target >= *minIndex && target < nums[len - 1]){
//            //binary search   (minIndex,len-1) target
//            return binarySearch(nums, minIndex, nums.begin() + (len - 1), target);
//        }
//        else{
//            //binary search (begin,minIndex-1) target
//            return binarySearch(nums, nums.begin(), minIndex - 1, target);
//        }
//    }
//    else{
//        //binary search (begin ,end) target
//        return binarySearch(nums, nums.begin(), nums.end() - 1, target);
//    }
//}
//
//int binarySearch(vector<int>& nums, vector<int>::iterator left, vector<int>::iterator rignt, int target){
//    if ((right - nums.begin()) == (left - nums.begin())){
//        if (target != *left){
//            return -1;
//        }
//        else{
//            return left - nums.begin();
//        }
//    }
//    else{
//        vector<int>::iterator mid = left + (right - left) / 2;
//        if (target == *mid){
//            return mid - nums.begin();
//        }
//        else if (target > *mid){
//            return binarySearch(nums, mid, right, target);
//        }
//        else(target < *mid){
//            return binarySearch(nums, left, mid, target);
//        }
//    }
//}