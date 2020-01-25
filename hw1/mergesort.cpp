#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;

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
/*the function has 2 actions.First,slide the vector into groups.Second,order each of them by calling the merge function.
 *parameters:The new vector "aim" will be used for store the sorted value.i is the left one,i+len is the right,
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

int main(){
    ifstream dtIn;
    ofstream dtOut;
    dtIn.open("data.txt");
    dtOut.open("merge.txt");
    int first = 0, value;
    while(dtIn>>first)
    {
        vector<int> arr;
        /*Read the values from data.txt,then push them into 
         *arr. The first value is the number of each line,so
         * the push action will from the second one,which is 
         * the list to be arranged.
         */
        for(int i = 0; i < first; i++){
           dtIn >> value;
           arr.push_back(value);
       }
       merge_sort(arr);
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