#include<vector>

struct Subset{
	unsigned keyword;
	std::vector<unsigned> sublist;
};

class VSset{
	std::vector<Subset> subs;
	VSset(unsigned nums){
		subs.reserve(nums);
		//If 16 bits, follow following two lines:
		//If 8 or less, all pathern can be memoried, I guess.
		//If 9 or more, I think this is gonna be completely random.
		//If 32 bits? Below.
		//If 12 or less,
		//If 13 or more,

		//Also up to 26 subs can be stored in each vs logically, but who would like such the long screen?
	}
};
