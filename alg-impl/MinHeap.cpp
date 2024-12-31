#include <vector>
#include <algorithm>
using namespace std;

class MinHeap{
    public:
        MinHeap(vector<int>& input){
            heap.insert(heap.begin()+1, input.begin(), input.end());
            r = input.size();
            bottom_up_heapify(1);
        }
        int peek(){
            return heap[1];
        }
        int pop(){
            int min = heap[1];
            heap[1] = heap[r--];
            bubble_down(1);
            return min;
        }
        void insert(int key){
            if(r >= heap.size()-1){
                heap.resize((r+1)*2);
            }
            heap[++r] = key;
            bubble_up(r);
        }
    private:
        vector<int> heap = {0};
        int r;
        void bubble_down(int l){
            if(l*2 > r) return;
            if(l*2+1 > r || heap[l*2] < heap[l*2+1]){
                if(heap[l*2] < heap[l]){
                    swap(heap[l*2], heap[l]);
                    bubble_down(l*2);
                }else{
                    return;
                }
            }else{
                if(heap[l*2+1] < heap[l]){
                    swap(heap[l*2+1], heap[l]);
                    bubble_down(l*2+1);
                }else{
                    return;
                }
            }
        }
        void bubble_up(int loc){
            while(loc > 1){
                if(heap[loc] < heap[loc/2]){
                    swap(heap[loc], heap[loc/2]);
                    loc /= 2;
                }
                else break;
            }
        }
        void bottom_up_heapify(int l){
            if(l*2 > r) return;
            bottom_up_heapify(l*2);
            bottom_up_heapify(l*2+1);
            bubble_down(l);
        }

};