#include <iostream>
#include<vector>
#define  forv(a,b) for(int i = (a); i<(b); ++i)
#define pivot(left,right) ((left+right)/2)

typedef vector<int> v;

using namespace std;

void swap(v victor, int left, int right) {
    int temp = victor[right];
    victor[right] = victor[left];
    victor[left] = temp;
}

v mergeVector(v victor1, v victor2){
    v megaVictor;
    for(int i = 0; i < victor1.size(); ++i){
        megaVictor[i] = victor1[i];
    }
    for(int i = 0; i < victor2.size(); ++i){
        megaVictor[i] = victor2[i];
    }
    return megaVictor;
}
v splitLeftVector(v victor, int pivot_value, int left, int right) {
    v left_victor;
    for (int i = left; i < pivot_value; ++i) {
        if (victor[i] < victor[pivot_value]) {
            left_victor[i] = victor[i];
        }
        return left_victor;
    }
}
v splitRightVector(v victor, int pivot_value, int left, int right) {
    v right_victor;
    for (int i = pivot_value; i < right; ++i) {
        if (victor[i] > victor[pivot_value]) {
            right_victor[i] = victor[i];
        }
        return right_victor;
    }
}
v quicksort(v victor, int left, int right) {
    v leftv;
    v rightv;
    forv(left,victor.size()){
        if(victor[left]>victor[left+1]){
            if(victor[left]>victor[left+1] && left <= pivot(left,right)) {
                leftv = splitLeftVector(victor, pivot(left, right), left, right);
                quicksort(leftv, left, right);
            }
            if(victor[left]>victor[left+1] && left > pivot(left,right)){
                 rightv = splitLeftVector(victor, pivot(left, right), left, right);
                quicksort(rightv, left, right);
            }
            
        }
        
    }
    return mergeVector(leftv,rightv);
}

int main() {
    vector<int>myvect ={9,3,6,2};
    quicksort(myvect,0,4);
    return 0;
}

