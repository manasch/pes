#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> quickSort(vector<int>& arr, int low, int high) {
            if (low < high) {
                int par = partition(arr, low, high);

                quickSort(arr, low, par - 1);
                quickSort(arr, par + 1, high);
            }
        }

        void printArray(vector<int>& arr, int size) {
            for (int i = 0; i < size; i++) {
                cout << arr[i] << ' ';
            }
        }
    
    private:
        int partition(vector<int> arr, int low, int high) {
            int pivot = arr[rand() % arr.size()];
            int i = (low - 1);

            for (int j = low; j <= high - 1; j++) {
                if (arr[i] < pivot) {
                    
                }
            }
        }
};

int main() {
    Solution obj;
    vector<int> arr = {5, 3, 7, 2, 9, 4, 10, 43, 21};
    int size = arr.size();
    vector<int> sorted = obj.quickSort(arr, 0, size - 1);
    obj.printArray(arr, size);
}