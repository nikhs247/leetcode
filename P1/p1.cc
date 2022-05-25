/**
 * @file p1.cc
 * @author Nick
 * @brief Find the area of container with maximum water capacity, given the height of pillars that can be used to create containers of varying size
 * @version 0.1
 * @date 2022-05-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int maxArea(std::vector<int>& height) { // O(n) complexity, where n = number of elements in height array
    int max_index = 0, max_area = 0, max_height = height[0];
    int len = height.size();

    // find maximum height in the given input array and the corresponding index
    for(int i = 0; i < len; i++){ // O(n)
        if(max_height < height[i]){
            max_index = i;
            max_height = height[i];
        }
    }

    // Find the area of container with maximum water
    for(int i = 1; i < len; i++){ // O(n)
        int area = abs(i - max_index) * std::min(max_height, height[i]);
        if(area > max_area){
            max_area = area;
        }
    }
    
    return max_area;
}

int main(){
    std::vector<int> c1 = {1,8,6,2,5,4,8,3,7};
    std::cout << "C1: "<< maxArea(c1) << std::endl;

    std::vector<int> c2 = {1,1};
    std::cout << "C2: "<< maxArea(c2) << std::endl;

    std::vector<int> c3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "C3: "<< maxArea(c3) << std::endl;

    std::vector<int> c4 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::cout << "C4: "<< maxArea(c4) << std::endl;

    std::vector<int> c5 = {1, 2, 3, 2, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
    std::cout << "C5: "<< maxArea(c5) << std::endl;
    return 0;
}