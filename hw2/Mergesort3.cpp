#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;

/* Merge the sorted ranges [low, mid1), [mid1,mid2) 
 *and [mid2,high),mid1/mid2 are first/second midpoint respectively.
 */
void merge(vector<int>&vec, int low, int mid1,  
 int mid2, int high, vector<int>&aim)  
{  
    int i = low, j = mid1, k = mid2, l = low;  

    // choose smaller of the smallest in the three ranges  
    while ((i < mid1) && (j < mid2) && (k < high))  
    {  
        if(vec[i] < vec[j]) 
        { 
            if(vec[i] < vec[k]) 
            { 

                aim[l++] = vec[i++]; 
                // cout<<"aaaaaaaaaa"<<i<<endl;
            } 
            else
            { 
                aim[l++] = vec[k++]; 
            } 
        } 
        else
        { 
            if(vec[j] < vec[k]) 
            { 
                aim[l++] = vec[j++]; 
            } 
            else
            { 
                aim[l++] = vec[k++]; 
            } 
        } 
    }  

    // case where first and second ranges 
    // have remaining values  
    while ((i < mid1) && (j < mid2))  
    {  
        if(vec[i] < vec[j]) 
        { 
            aim[l++] = vec[i++]; 
        } 
        else
        { 
            aim[l++] = vec[j++]; 
        } 
    }  

    // case where second and third ranges 
    // have remaining values  
    while ((j < mid2) && (k < high))  
    {  
        if(vec[j] < vec[k]) 
        { 
            aim[l++] = vec[j++]; 
        } 
        else
        { 
            aim[l++] = vec[k++]; 
        }  
    }  

    // case where first and third ranges have  
    // remaining values  
    while ((i < mid1) && (k < high))  
    {  
         // aim[l++] std::min<int>(vec[i],vec[k],);
        if(vec[i] < vec[k]) 
        { 
            aim[l++] = vec[i++]; 
        } 
        else
        { 
            aim[l++] = vec[k++]; 
        }  
    }  

    // copy remaining values from the first range  
    while (i < mid1)  
        aim[l++] = vec[i++];  
    // copy remaining values from the second range  
    while (j < mid2)  
        aim[l++] = vec[j++];  

    // copy remaining values from the third range  
    while (k < high)  
        aim[l++] = vec[k++];  
}  

/* Split array into 3 parts and sorting them 
 * recursively
 */
void mergeSort3(vector<int>& vec, int low, 
  int high, vector<int>& aim)  
{  
    if (high - low < 2)  
        return;  

    int mid1 = low + ((high - low) / 3);  
    int mid2 = low + 2 * ((high - low) / 3) + 1;  

    mergeSort3(aim, low, mid1, vec);  
    mergeSort3(aim, mid1, mid2, vec);  
    mergeSort3(aim, mid2, high, vec);  

    // Merging the sorted vectors  
    merge(aim, low, mid1, mid2, high, vec); 
} 
 /*Read the values from data.txt,then push them into
  *arr. The first value is the number of each line,so
  *the push action will from the second one,which is 
  *the list to be arranged.
  */
int main() 
{ 
    ifstream dtIn;
    ofstream dtOut;
    dtIn.open("data.txt");
    dtOut.open("merge3.txt");

    int first = 0, value;
    while(dtIn>>first)
    {
        vector<int> vec;
        for(int i = 0; i < first; i++){
         dtIn >> value;
         vec.push_back(value);
     }
    if (vec.size() == 0)  
        return 0;   
    vector<int> aim(vec.size());
    aim=vec;
    mergeSort3(aim, 0, vec.size(), vec);  

    // output the vector vec,which stores in aim
    for (int i = 0; i < vec.size(); i++)  
        vec[i] = aim[i];

       //out data to insert.txt
    for (unsigned i = 0; i < vec.size(); i++)
    {
        dtOut << vec.at(i) << " ";
        cout << vec[i] << " ";
    }
    cout<<endl;
    dtOut << "\r\n" << endl;
}
dtIn.close();
dtOut.close();
} 