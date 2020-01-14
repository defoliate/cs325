#include <iostream>
#include <vector>
using namespace std;
using std::endl;
/*execute merge action devide-conquer.the function has 2
 *key points. First,limit the left/right bound. 
 *Second,compare the smaller one recursively.
 *Meanwhile,output the sorted vector to "aim".
 */
void merge(vector<int>&orgin,vector<int>&aim,int left_bgin,int right_bgin,int end){
    int i_left=left_bgin,i_right=right_bgin;
    //control each bound
    for(int i=left_bgin;i<end;i++){
        if(i_left>=right_bgin){
            aim[i]=orgin[i_right++];
        }else if(i_right>=end){
            aim[i]=orgin[i_left++];
        }
        //constructure the smaller one to aim
        else if (orgin[i_left] <= orgin[i_right]) {
            aim[i] = orgin[i_left++];
        } else {
            aim[i] = orgin[i_right++];
        }
    }
}

/*The function has 2 actions.First,slide the vector into groups.Second,order each of them by calling the merge function.
 *parameters:The new vector "aim" will be used for store 
 *the sorted value.i is the left one,i+len is the right,
 *the rest min is to limit the right range or the whole *vector.
 */
void merge_sort(vector<int>& vec) {
    vector<int> aim(vec.size());
    //2*n is the length of each group:1,2,4..
    for (int len = 1; len < vec.size(); len *= 2) {
        //track each elements:1,3,5..
        for (int i = 0; i < vec.size(); i += 2 * len)
        {   // cout<<"x="<<i<<endl;
    merge(vec, aim, i, std::min<int>(vec.size(), i + len),std::min<int>(vec.size(), i + 2 * len));}
    vec = aim;
}
}

//create vSize numbers from [0,1000) randomly.
void loadVector(vector<int>& vectorToLoad, int vSize){
    for(int i = 0; i < vSize; i++){
        vectorToLoad.push_back(1 + rand() % 1000);
    }
}


//using insertionSort and outputs time to the console.
void timeMergeSort(vector<int>& vectorToSort, int datapoint){
    clock_t begin = clock();
    merge_sort(vectorToSort);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << datapoint << ": " << elapsed_secs << endl;
}

int main(){
    vector<int> vectors[10];
    cout << "Merge Sort:" << endl;
    //test 10 times,from 5,000,000 to 15,000,000
    for(int i = 0, vSize = 5000000; i < 10; i++){
        loadVector(vectors[i], vSize);
        timeMergeSort(vectors[i], i + 1);
        vSize += 1000000;
    }
}