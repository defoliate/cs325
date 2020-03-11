#ifndef file_handler_hpp
#define file_handler_hpp
#include <string>
#include <vector>

std::vector<std::vector<int>> file_to_arr(std::string ifile);
void arr_to_file(std::string out_file_name, std::vector<int> tour, int cost);

struct City {
   int id, x, y;
};

#endif /* file_handler_hpp */
