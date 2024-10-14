#include "utility.h"

using namespace std;

template<typename TYPE>


class Bubble {
  public:
    Bubble() {}
    Bubble(vector<TYPE> v) : vec(v){}

    void outputResults() {
        cout << "The bubble sort took " << swapCount << " swaps to sort.\n";
        cout << "The vector now looks like this:\n";
        cout << "{";
        for(size_t i = 0; i < vec.size()-1; i++) {
            cout << vec[i] << ", ";
        }
        cout << vec[vec.size()-1] <<"}\n";
    }
    void bubbleSort() {
      bool swapped = true;
      size_t n = vec.size();
    
      while(swapped) {
        swapped = false;
        for(size_t i = 1; i < n; i++) {
          if (vec[i - 1] > vec[i]) {
            swap(vec[i - 1], vec[i]);
            swapped = true;
            swapCount++;
          }
        }
        n--;
      }
    }

  private:
    vector<TYPE> vec;
    int swapCount = 0;
};