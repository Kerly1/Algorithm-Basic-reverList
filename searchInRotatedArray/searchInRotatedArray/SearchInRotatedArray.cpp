#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    cout << "Please input the roated array seperated with enter and end with 'end'." << endl;
    vector<int> roatedArray;
    vector<int>::iterator iter = roatedArray.begin();
    string inputStr;

    while (cin >> inputStr){
        *iter = inputStr;
    }
    
    
    
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
        if (target > *minIndex && target < nums[len - 1]){
            //binary search   (minIndex,len-1) target
            binarySearch(nums, minIndex, nums.begin()+(len - 1), target);
        }
        else{
            //binary search (begin,minIndex-1) target
            binarySearch(nums, nums.begin(), minIndex - 1, target);
        }
    }
    else{
        //binary search (begin ,end) target
        binarySearch(nums, nums.begin(), nums.end()-1, target);
    }
}

int binarySearch(vector<int>& nums, vector<int>::iterator left, vector<int>::iterator rignt, int target){
    if (right - left == 0){
        if (target != *left){
            return -1;
        }
        else{
            return left-nums.begin();
        }
    }
    else{
        vector<int>::iterator mid = left +(right - left)/2;
        if (target == *mid){
            return mid - nums.begin();
        }
        else if (target > *mid){
            binarySearch(nums, mid, right, target);
        }
        else(target < *mid){
            binarySearch(nums, left, mid, target);
        }
    }   
}