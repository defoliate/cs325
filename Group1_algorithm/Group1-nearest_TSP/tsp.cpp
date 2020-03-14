#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <list>

/*
   Params: 2D vector 
   Runs nearest neighbor algorithm
*/
std::vector<int> nearest_neighbor(std::vector<std::vector<int> > adj_matrix)
{
   int start = 1;
   int distance;
   int min;
   int closest;
   int num_cities = adj_matrix.size();
   std::vector<int> tour;
   std::vector<int> dist_list;
   tour.push_back(start);

   for (int i = 0; i < num_cities; i++){
      for (int j = 0; j < num_cities; j++){
            distance = adj_matrix[i][j];
            dist_list.push_back(distance);
      }
   }

   while (tour.size() < num_cities){
      min = std::numeric_limits<int>::max();
      closest = std::numeric_limits<int>::max();
      for (int i = 0; i < num_cities; i++){
         if (dist_list[start*num_cities + i] < min && !(std::find(tour.begin(), tour.end(), i) != tour.end())){
            min = dist_list[start*num_cities + i];
            closest = i;
         }
      }
      tour.push_back(closest); 
      start = closest;
   }

   return tour;
}

/*
   Params: 2D vector, 1D vector
   Run 2-opt optimization
*/
std::vector<int> two_opt(std::vector<std::vector<int> > adj_matrix, std::vector<int> tour){
   int num_cities = adj_matrix.size();
   bool improve = false;
   while(!improve) {
      for (int i = 1; i < num_cities - 2; i++) {
         for (int j = i + 1; j < num_cities - 1; j++) {
            int swap_distance = adj_matrix[tour[i]][tour[j]] + adj_matrix[tour[i + 1]][tour[j + 1]];
            int old_distance = adj_matrix[tour[i]][tour[i + 1]] +  adj_matrix[tour[j]][tour[j + 1]];
            if (old_distance > swap_distance) {
               for (int x = 0; x < (j - i) / 2; x++) {
                  int temp = tour[i + 1 + x];
                  tour[i + 1 + x] = tour[j - x];
                  tour[j - x] = temp;
               }
               improve = false;
            }
         }
      }
      improve = true;
   }
   return tour;
}
