#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdio>

#include "data-storer.hpp"

using namespace std;

int main(int argc, char* argv[]){
	try{
		//argc check
		if(argc==1){
			string str="wrong usage.\nUsage: ";
			str = str + argv[0] + " FILENAME";
			throw str;
			/*
			string err("wrong usage.\nUsage: ");
			err = err + argv[0] + " FILENAME";
			throw err;
			*/
		}

		//Existence Check
		ifstream ifs(argv[1]);
		if(!ifs.is_open()){
			ifs.close();
			throw "The file didn't exist!";
		}

		//Check content of file
		string input;
		if(!getline(ifs,input)){
			ifs.close();
			throw "WTF! EMPTY!";
		}

		//Store header
		DataStorer data_storer(input);

		//Next line?
		if(!getline(ifs,input)){
			ifs.close();
			throw "WTF! ONLY A LINE?!";
		}

		//Store option nums
		data_storer.opvalue(input);

		//3 or more lines?
		if(!getline(ifs,input)){
			ifs.close();
			throw "WTF! STILL NOT ENOUGH DATA!";
		}

		//store sub
		unsigned linenum=3;
		do{
			ds.input(input, linenum++);
		}while(getline(ifs,input));

		//do an exception if only a sub got submitted
		if(linenum==4){
			ifs.close();
			throw "Wut? only a sub in a round?";
		}

		//make file for output
		string ofname = argv[1];
		ofname+=".vs";
		ofstream ofs(ofname,ofstream::trunc);
		if(!ofs.is_open()){
			ifs.close();
			ofs.close();
			throw "why... output file couldn't be made... why...";
		}

		//copy ifs to ofs
		ifs.clear();
		ifs.seekg(0, ifs.beg);
		vector<char> buffer(1024*1024);
		while( !ifs.eof() )
    {
        size_t size = ifs.read( &buffer[0], buffer.size() ).gcount();
        ofs.write( &buffer[0], size );
    }

		//close ifs
		ifs.close();

		//add random nums to ofs
		unsigned datas = ds.get_subnum();
		ofs << ds.make();

		//close ofs
		ofs.close();

	}catch(const string e){
		cerr << e << endl;
		return -1;
	}catch(const char* e){
		cerr << e << endl;
		return -2;
	}
	return 0;
}
