# include <iostream>
# include <string> 
# include <algorithm>
# include <vector>
# include <numeric>


void print(std::vector<int> const &v) {
		for ( int c: v) { std::cout << c << " "; }
		
		std::cout << std::endl;
}

int main() {
	
	auto xor_string = [](std::string &s, int num) -> void { 
		//std::transform(s.begin(), s.end(), s.begin(),
		//	[=](char &c) -> char { return c ^ num; });
		for (char &c: s) { c = c ^ num; }
	};
	
	auto flip = [](std:: string &s) -> void {
		reverse(s.begin(), s.end());
	};
	
	auto all_upper = [](const std::vector<std::string> &names) -> bool {
		return std::all_of(names.begin(), names.end(), [](const std::string &name) {
		return std::all_of(name.begin(), name.end(), ::isupper);
		});

	};
 
	auto flatten = [](const std::vector<std::vector<int>> &v_v) -> std::vector<int> {
		
		std::vector<int> flatten_v = {};
	    std::for_each(v_v.begin(), v_v.end(), [&](const std::vector<int> v) {
			flatten_v.insert(flatten_v.end(), v.begin(), v.end());
		}); 	
		return flatten_v;
	};


	// Tests
	std::string s;

	s  = "Yeh baby :)"; 	
	xor_string(s, 4);
	std::cout << s << std::endl;

	s = "Yeh baby :)"; 
	flip(s);
	std::cout << s << std::endl;	

	std::vector<std::string> names;

	names  = {"MASALO", "ITAYMAS"};
	std::cout << all_upper(names) << std::endl;

	names = {"MAsALO", "ITAYMAS"};
	std::cout << all_upper(names) << std::endl;

	std::vector<std::vector<int>> v = {{1,2}, {3,4}};
	print(flatten({{1,2,3}, {4}}));
	
	
	return 0;
}
