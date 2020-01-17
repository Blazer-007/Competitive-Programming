#include <bits/stdc++.h>
using namespace std;
// Max Heap Implementation
void upheapify(vector<int> &heap,int idx){
    if(idx==0){
        return;
    }
    int parentIdx = (idx-1)/2;
    if(heap[parentIdx]<heap[idx]){
        int temp = heap[parentIdx];
        heap[parentIdx] = heap[idx];
        heap[idx] = temp;
        upheapify(heap,parentIdx);
    }else{
        return;
    }
}

void insert(vector<int> &heap,int key){
    heap.push_back(key);
    upheapify(heap,heap.size()-1);
}

void downHeapify(vector<int> &heap,int idx){

    int leftIdx = 2*idx + 1;
    int rightIdx = 2*idx + 2;
    if(leftIdx >= heap.size() and rightIdx>=heap.size()){
        return;
    }
    int largestIdx = idx;
    if(leftIdx < heap.size() and heap[leftIdx] > heap[largestIdx]){
        largestIdx = leftIdx;
    }
    if(rightIdx<largestIdx and heap[rightIdx]>heap[largestIdx]){
        largestIdx = rightIdx;
    }
    if(largestIdx==idx)return;
    swap(heap[idx],heap[largestIdx]);
    downHeapify(heap,largestIdx);

}

void deletePeak(vector<int> &heap){
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    downHeapify(heap,0);
}


void display(vector<int> &heap){
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> heap;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        insert(heap,x);
    }
    display(heap);
    return 0;
}
