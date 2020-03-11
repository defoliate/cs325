#include <iostream>
#include <fstream>
#include "file_handler.hpp"
#include "tsp.hpp"
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <math.h>

/*
   Params:
      x and y coordinates for two cities
   Returns:
      euclidean distance between cities
*/

int compute_distance(int x1, int y1, int x2, int y2) {
   double dx = x2 - x1;
   double dy = y2 - y1;
   double dist = sqrt(dx*dx + dy*dy);
   return (int) round(dist);
}

/*
   Params:
      ifile: string, name of file to input into an array.
   Returns:
      a 2D vector of vectors of ints 
*/
std::vector<std::vector<int>> file_to_arr(std::string ifile) {
   std::string line;
   std::ifstream file;
   std::vector<City> cities;
   std::vector<std::vector<int> > adj_matrix;
   file.open(ifile.c_str());

   while(getline(file, line)) {
      std::istringstream iss(line);
      City input_city;
      iss >> input_city.id;
      iss >> input_city.x;
      iss >> input_city.y;

      cities.push_back(input_city);
   }

   file.close();
   int num_cities = cities.size();
   adj_matrix.resize(num_cities, std::vector<int>(num_cities, -1));

   for(int i = 0; i < num_cities; i++) {
      for(int j = 0; j < num_cities; j++) {
         adj_matrix[i][j] = compute_distance(cities[i].x, cities[i].y, cities[j].x, cities[j].y);
      }
   }

   return adj_matrix;
}


/*
   Params:
      ofile: string, name of file to output array to. 
      arr:  1D vector to be converted. 
      cost: int, cost of tour
   Writes vector into a file.
*/
void arr_to_file(std::string out_file_name, std::vector<int> tour, int cost) {
   int num_cities = tour.size();
   std::ofstream out_file;
   out_file.open(out_file_name.c_str());
   out_file << cost << std::endl;
   for(int i = 0; i < num_cities; i++) {
      out_file << tour[i] << '\n';
   }
   out_file.close();
}
