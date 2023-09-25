#include<ctime>
#include<random>
#include"vsset.hpp"

uint32_t xor32(void) {
  //static uint32_t y = 2463534242;
  static uint32_t y = time(NULL);	//時刻を種にしてみた
  //static uint32_t y = 2;	//変えてみた
  y = y ^ (y << 13); y = y ^ (y >> 17);
  return y = y ^ (y << 15);
}

unsigned long xor128(){
    static unsigned long x=123456789,y=362436069,z=521288629,w=88675123;
    unsigned long t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}
unsigned rndint(){
  return unsigned int result = rng();
}

Subset MakeSubset(unsigned subs, unssigned picks){
	unsigned array[subs];
	for(unsigned i=0; i<subs; i++)	array[i]=i;
	Subset subset;
	vsset.keyword=rndint();
	for(unsigned i=0; i<picks; i++){
		unsigned chosen = rndint()%(picks-i)+i;
		vsset.sublist.push_back(array[chosen]);
		array[chosen]=array[i];
	}
	return subset;
}
