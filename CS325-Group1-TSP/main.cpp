#include <iostream>
#include <fstream>
#include "file_handler.hpp"
#include "tsp.hpp"
#include <string>
#include <vector>
#include <cstdio>
#include <chrono>

/*
   Params: 2D vector 
   Prints out 2D vector in matrix format.  
*/
void print_arr(std::vector<std::vector<int>> arr) {
   for (int i = 0; i < arr.size(); i++) {
      for (int j = 0; j < arr[i].size(); j++) {
         std::cout << arr[i][j] << " ";
      }
      std::cout << std::endl;
   }
}

/*
   Params: 1D vector 
   Prints out 1D vector.  
*/
void print_arr(std::vector<int> arr) {
   for (int i = 0; i < arr.size(); i++) {
         std::cout << arr[i] << std::endl;
   }
}

/*
   Params: 2D vector, 1D vector, int
   Calculates cost for tour  
*/

int calc_cost(std::vector<std::vector<int> > adj_matrix, std::vector<int> tour, int num_cities) {
  int cost = 0;

  for (int i = 0; i < num_cities - 1; i++) {
      cost += adj_matrix[tour[i]][tour[i+1]]; 
      //std::cout << adj_matrix[tour[i]][tour[i+1]] << std::endl;
  }

  cost += adj_matrix[tour[num_cities-1]][tour[0]];

  return cost;
}

int main(int argc, char* argv[]) {
   auto start_time = std::chrono::high_resolution_clock::now();

   std::vector<int> tour;
   int cost;

   // convert txt file into 2D vector matrix
   std::string in_file_name  = argv[1]; 
   std::vector<std::vector<int>> adj_matrix = file_to_arr(in_file_name); 
   //print_arr(adj_matrix);
   int num_cities = adj_matrix.size();
   
   //run nearest neighbor
   tour = nearest_neighbor(adj_matrix);
   cost = calc_cost(adj_matrix, tour, num_cities);
   //std::cout << "Total cost after NN: " << cost << std::endl;

   //run 2-opt
   tour = two_opt(adj_matrix, tour);
   cost = calc_cost(adj_matrix, tour, num_cities);
   std::cout << "Total Cost: " << cost << std::endl;

   // write output vector into txt.tour file
   std::string out_file_name  = in_file_name + ".tour"; 
   arr_to_file(out_file_name, tour, cost);

   auto end_time = std::chrono::high_resolution_clock::now();
   auto time = end_time - start_time;

   std::cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(time).count() << " microseconds" << std::endl;

   return 0;
}
