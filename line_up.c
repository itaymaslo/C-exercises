# include <iostream>
# include <algorithm>
# include <vector> 
# include <functional> 
# include <numeric>

void print_vector(std::vector<int> const &v) {
	for (int c: v) { std::cout << c << " "; }
	
	std::cout << std::endl;
}

int main() {
	std::vector<int> v = {1, 2, 3, 5, 8, 8, 13, 4, 8};
	
	int more_than_four = std::count_if(v.begin(), v.end(), [](int &c) -> bool { return c > 4; });
	std::cout << more_than_four << std::endl;
	
	int equal_four = std::count_if(v.begin(), v.end(), [](int &c) -> bool { return c == 4; });
	std::cout << equal_four << std::endl;

	v.erase(remove_if(v.begin(), v.end(), [](int c) -> bool { return c == 8;}), v.end());
	print_vector(v);

	std::minus<int> m;

	print_vector(v);
	
	
	std::vector<int> differance_vector = {};

	std::adjacent_difference(v.begin(), v.end(), std::back_inserter(differance_vector));

	int sum = std::accumulate(differance_vector.begin(), differance_vector.end(), 0);
	std::cout << sum << std::endl;
	
	print_vector(differance_vector);	

	return 0;
}


