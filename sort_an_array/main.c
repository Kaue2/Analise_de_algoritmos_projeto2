#include <stdlib.h>

void merge(int* nums, int left, int mid, int right, int* temp) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    
    for (int p = left; p <= right; p++) {
        nums[p] = temp[p];
    }
}

void merge_sort(int* nums, int left, int right, int* temp) {
    if (left >= right) {
        return;
    }
    
    int mid = left + (right - left) / 2;
    
    merge_sort(nums, left, mid, temp);
    merge_sort(nums, mid + 1, right, temp);
    
    merge(nums, left, mid, right, temp);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    
    if (numsSize <= 1) {
        return nums;
    }
    
    int* temp = (int*)malloc(numsSize * sizeof(int));
    if (temp != NULL) {
        merge_sort(nums, 0, numsSize - 1, temp);
        free(temp); 
    }
    
    return nums;
}
