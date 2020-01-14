#include <iostream>
// #include <fstream>
#include <vector>
#include <ctime>

using namespace std;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
/*partially sorted recursively,exchange to the relative smaller one.
 *2 loops,the complexity is big O(n^2).
 *the best case is O(n),just the outer loop.
 */
void insert_sort(vector<int>& vec){
    for (int i = 1; i < vec.size(); i++) {
      int j = i;
      while (j > 0 && vec[j] < vec[j-1]) {
         swap(vec[j], vec[j-1]);
         j--;
     }
 }
}

//create vSize numbers from [0,1000) randomly.
void loadVector(vector<int>& vectorToLoad, int vSize){
    for(int i = 0; i < vSize; i++){
        vectorToLoad.push_back(1 + rand() % 1000);
    }
}

//using insertionSort and outputs time to the console.
void timeInsertSort(vector<int>& vectorToSort, int datapoint){
    clock_t begin = clock();
    insert_sort(vectorToSort);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << datapoint << ": " << elapsed_secs << endl;
}

int main(){
      vector<int> vectors[10];
          cout << "Insert Sort:" << endl;
   //test 10 times,from 10,000 to 100,000
   for(int i = 0, vSize = 10000; i < 10; i++){
        loadVector(vectors[i], vSize);
        timeInsertSort(vectors[i], i + 1);
        vSize += 10000;
    }
}