#ifndef tsp_hpp
#define tsp_hpp
#include <iostream>
#include <vector>

std::vector<int> tsp(std::vector<std::vector<int>>);
std::vector<int> nearest_neighbor(std::vector<std::vector<int> > adj_matrix);
std::vector<int> two_opt(std::vector<std::vector<int> > adj_matrix, std::vector<int> tour);

#endif /* tsp_hpp */
