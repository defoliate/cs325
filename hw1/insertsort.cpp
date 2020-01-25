#include <iostream>
#include <fstream>
#include <vector>
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

int main(){
    ifstream dtIn;
    ofstream dtOut;
    dtIn.open("data.txt");
    dtOut.open("insert.txt");
    int first = 0, value;
    while(dtIn>>first)
    {
        vector<int> arr;
        // cout<<first<<endl;
        // dtIn.clear();
        // dtIn.seekg(0);
        /*read the values from data.txt,then push them into 
         *arr. The first value is the number of each line,so
         * the push action will from the second one,which is *the list to be arranged.
         */
        for(int i = 0; i < first; i++){
           dtIn >> value;
           arr.push_back(value);
       }
       insert_sort(arr);
       //out data to insert.txt
       for (unsigned i = 0; i < arr.size(); i++)
       {
        dtOut << arr.at(i) << " ";
        cout << arr[i] << " ";
    }
    cout<<endl;
    dtOut << "\r\n" << endl;
}
dtIn.close();
dtOut.close();
}