#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

//get the max value
int max(int a, int b) { return (a > b)? a : b; } 

/*  W = weight of each item in the shopping bag
 *  P = price of each item in the shopping bag
 *  N = number of items in the shopping bag
 *  M = max weight of all the items in the shopping bag
 */
int knapsack(int W[], int P[], int N, int M, vector<int> &v) {
// cout<<"N="<<N;
    int K[N + 1][M + 1];

    //2 nested for loops build a table of the total number of items and the max weight
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= M; j++) {
            if(i == 0 || j == 0) {
                K[i][j] = 0;
            }

            else if(W[i - 1] <= j) {
                K[i][j] = max(P[i - 1] + K[i - 1][j - W[i - 1]], K[i - 1][j]);
            }

            else {
                K[i][j] = K[i - 1][j];
            }

        }
    }

    //stores the result of knapsack
    int result = K[N][M];
    int m = M;

    for(int n = N; n > 0 && result > 0; n--) {
        if(result == K[n - 1][m]) {
            continue;
        }

        else {
            v.push_back(n);
            result -= P[n - 1];
            m -= W[n - 1];
        }
    }
    return K[N][M];
}

int main()
{
    //ifstream and ofstream to read the file, and output the array to a file
	ifstream readFile;
	ofstream outputFile("results.txt");

	readFile.open("shopping.txt");
		/*T is the number of test cases given on line one of
		 *the inputfile,N is the number of items in each test 
		 *case,P is an integer that corresponds to the price 
		 *of each item,W is an integer corresponds to the 
		 *weight of the item,F is the number of people in 
		 *each family,M is the maximum weight each person in 
		 *the family can carry.
		 */
        int T; 
        int N; 
        int P[100]; 
        int W[100]; 
        int F; 
        int M; 
        int x = 1; //the number of test cases
        vector<vector<int> >vec(100);

		//readFile returns the number of test cases from the input file
        readFile >> T;
        // cout<<T<<" ";
		//for loop, loops through the number of test cases (i < T)
        for (int i = 0; i < T; i++) {
            // cout<<"i====="<<i<<endl;
		    //readFile returns the number of items from the input file
            readFile >> N;
            // cout<<"N="<<N<<" ";
            //nested for loop, loops through the number of items
            //returns the price and weight of each item and places them into arrays
            for(int j = 0; j < N; j++) {
                readFile >> P[j];
                readFile >> W[j];
                // cout<<"P[j]="<<P[j]<<" ";
                // cout<<"W[j]="<<W[j]<<" ";

            }

            //totalPrice is the total price of ALL items the family carries
            int totalPrice = 0;

            // //readFile returns the number of family members in the family from the input file
            readFile >> F;
            // cout<<"FFFFFFF="<<F;
            //nested for loop, loops through the number of family members
            //returns the maximum weight each family member can carry
            for (int k = 0; k < F; k++) {
                //readFile returns the maximum weight each family member can carry
                readFile >> M;
                // cout<<"M/p="<<M<<endl;
            /*totalPrice variable initialized as the maximum 
             *price of items that can be carried by the 
             *current family member. Putting each family in a *vector and call knapsack to maximum the result.
             */
                totalPrice += knapsack(W, P, N, M, vec[k]);
            }


            //prints the required result to the output file
            outputFile << "Test Case " << x << endl;
            x++;
            cout << "Total Price " << totalPrice << endl;
            outputFile << "Total Price " << totalPrice << endl;

  			//prints the items each family member should take (ex. 1:1) to the output file
            outputFile << "Member Items" << endl;
            for(int n = 0; n < F; n++) {
                sort(vec[n].begin(), vec[n].end());
                //cout << n + 1 << ": ";
                outputFile << n + 1 << ": ";

                for(int m = 0; m < vec[n].size(); m++) {
                    outputFile << vec[n][m] << " ";
                }
                outputFile << endl;
            }
        }

	//close the file streams
	readFile.close();
	outputFile.close();

        return 0;
    }