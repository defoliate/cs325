#include <iostream> 
#include <stdlib.h> 
#include <time.h> 
#include <vector>

using namespace std; 
  // return the max value
int max(int a, int b) { return (a > b)? a : b; } 

// Optimize the maximum value with dynamic programming method
int DP(int W, int wt[], int val[], int n) 
{ 
	int i, w; 
	int K[n+1][W+1]; 

   // Build table K[][] in bottom up manner 
	for (i = 0; i <= n; i++) 
	{ 
		for (w = 0; w <= W; w++) 
		{ 
			if (i==0 || w==0) 
				K[i][w] = 0; 
			else if (wt[i-1] <= w) 
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
			else
				K[i][w] = K[i-1][w]; 
		} 
	} 

	return K[n][W]; 
} 
// Optimize the maximum value with recursive method 
int Recursive(int W, int wt[], int val[], int n)  
{  
// Base Case  
	if (n == 0 || W == 0)  
		return 0;  

/* If weight of the nth item is more than capacity W, 
 * this item cannot be included in the optimal solution. 
 */
	if (wt[n-1] > W)  
		return Recursive(W, wt, val, n-1);  

/* Return the maximum of two cases:nth item included,
 * not included.
 */
	else return max( val[n-1] + Recursive(W-wt[n-1], wt, val, n-1),Recursive(W, wt, val, n-1) );  
}

/* Return the answer to the console.it calls recursive/dp
 * method above.
 */
void valTime(int W, int wt[], int val[], int n){
	clock_t begin = clock();
	int a=DP(W, wt, val, n);
	clock_t end = clock();
	clock_t begin1 = clock();
	int b=Recursive(W, wt, val, n);
	clock_t end1 = clock();
	//calculate the execute time of DP
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC*1000;
	//calculate the execute time of Recursive method
	double elapsed_secs1 = double(end1 - begin1) / CLOCKS_PER_SEC*1000;
	cout<< "N="<<n<<" W ="<<W<<" Rec time= " << elapsed_secs1 <<" DP time = "<< elapsed_secs<<" max Rec = "<<a<<" max DP = "<<b<<endl;
}

/*Generate random array with 10 elements val[],wt is the
 * weight,w represents the knapsack capacity,n is the number
 * of the val.
 */
void testTime1(){
	int val[10],wt[10];
	for (int i = 0; i < 10; ++i) {
		val[i] = 1 + (rand() % 99);
		wt[i] = 1 + (rand() % 30); 

	}
	// int val[10];
	// // vector<int> val[j];
	// for (int i = 0; i < 10; ++i) {
	// // srand(time(NULL));
	// 	val[i] = 1 + (rand() % 25);
	// }
	// // cout << val[i] << " ";
	// int wt[] = {10, 20,30};  
	int W = 100;  
	int n = sizeof(val)/sizeof(val[0]);  
	valTime(W, wt, val, n);
}
//Generate random array with 15 elements
void testTime2(){
	// int val[15];
	// for (int i = 0; i < 15; ++i) {
	// 	val[i] = 1 + (rand() % 25);
	// }
	// int wt[] = {10, 20,30};  
	int val[15],wt[15];
	for (int i = 0; i < 15; ++i) {
		val[i] = 1 + (rand() % 99);
		wt[i] = 1 + (rand() % 30); 

	}
	int W = 100;  
	int n = sizeof(val)/sizeof(val[0]);  
	valTime(W, wt, val, n);
}
//Generate random array with 20 elements
void testTime3(){
	// int val[20];
	// for (int i = 0; i < 20; ++i) {
	// 	val[i] = 1 + (rand() % 25);
	// }
	// int wt[] = {10, 20,30}; 
	int val[20],wt[20];
	for (int i = 0; i < 20; ++i) {
		val[i] = 1 + (rand() % 99);
		wt[i] = 1 + (rand() % 30); 

	} 
	int W = 100;  
	int n = sizeof(val)/sizeof(val[0]);  
	valTime(W, wt, val, n);

}
//Generate random array with 25 elements
void testTime4(){
	// int val[25];
	// for (int i = 0; i < 25; ++i) {
	// 	val[i] = 1 + (rand() % 25);
	// }
	// int wt[] = {10, 20,30}; 
	int val[25],wt[25];
	for (int i = 0; i < 25; ++i) {
		val[i] = 1 + (rand() % 99);
		wt[i] = 1 + (rand() % 30); 

	} 
	int W = 100;  
	int n = sizeof(val)/sizeof(val[0]);  
	valTime(W, wt, val, n);

}
//Generate random array with 30 elements
void testTime5(){
	// int val[30];
	// for (int i = 0; i < 30; ++i) {
	// 	val[i] = 1 + (rand() % 25);
	// }
	// int wt[] = {10, 20,30};  
	int val[30],wt[30];
	for (int i = 0; i < 30; ++i) {
		val[i] = 1 + (rand() % 99);
		wt[i] = 1 + (rand() % 30); 

	}
	int W = 100;  
	int n = sizeof(val)/sizeof(val[0]);  
	valTime(W, wt, val, n);

}
//Generate random array with 35 elements
void testTime6(){
	// int val[35];
	// for (int i = 0; i < 35; ++i) {
	// 	val[i] = 1 + (rand() % 25);
	// }
	// int wt[] = {10, 20,30}; 
	int val[35],wt[35];
	for (int i = 0; i < 35; ++i) {
		val[i] = 1 + (rand() % 99);
		wt[i] = 1 + (rand() % 30); 

	} 
	int W = 100;  
	int n = sizeof(val)/sizeof(val[0]);  
	valTime(W, wt, val, n);

}
//Generate random array with 40 elements
void testTime7(){
	int val[40],wt[40];
	for (int i = 0; i < 40; ++i) {
		val[i] = 1 + (rand() % 99);
		wt[i] = 1 + (rand() % 30); 
// cout<<val[i]<<" ";
	}
	// int wt[] = {10, 20,30};  
	int W = 100;  
	int n = sizeof(val)/sizeof(val[0]);  
	valTime(W, wt, val, n);
	// valTime(90, wt, val, n);
	// valTime(80, wt, val, n);
	// valTime(70, wt, val, n);
	// valTime(60, wt, val, n);
	// valTime(50, wt, val, n);
	// valTime(40, wt, val, n);




}
/* Driver code to show the test time of dynamic programming
 * and recursive method.
 */
int main()  
{
	// testTime1();
	// testTime2();
	// testTime3();
	// testTime4();
	// testTime5();
	// testTime6();
	// testTime7();
	// const int size=100;
	int val[100],wt[100];
	int n=0,W=100;
	// vector<int> val[j];
	for (int i = 20; i <= 50; i=i+5) {
	// srand(time(NULL));
		n=i;
		// cout<<"N==="<<i<<" W="<<W<<endl;

		for(int j=0;j<i;j++){
			val[j] = 1 + (rand() % 100);
			// cout<<val[j]<<endl;
			wt[j]=rand()%40+1;
		}
	valTime(W, wt, val, n);

		// cout<<"finish"<<endl;
				// int n = sizeof(val)/sizeof(val[0]); 
	}
	// cout << val[i] << " ";
	// int wt[] = {10, 20,30};  
	// int W = 100;  
	// int n = sizeof(val)/sizeof(val[0]); 
	// cout<<n;
	return 0;  
} 