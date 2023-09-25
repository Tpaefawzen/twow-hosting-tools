using namespace std;

class DataStorer{
  protected:
		unsigned pnum;  //How many colums must be made?
		vector<string> head;  //Label
		vector<unsigned> option_number; //Option num

		vector<vector<string>> submission_list; //Submission List

    //Check input num and opn
		inline void check_number(unsigned i){
			if(i>=pnum)
				throw "TOO MANY COLUMNS!";
		}
	public:
    //constructer (also store header labels)
		DataStorer(string s){
			pnum=0;
			string to_Vec="";
			for(unsigned it=0; it<s.size(); ++it){
				if(s[it]=='\t'){
					head.push_back(to_Vec);
					to_Vec="";
					pnum++;
				}else if(it+1==s.size()){
					to_Vec=to_Vec+s[it];
					head.push_back(to_Vec);
					pnum++;
				}else
					toVec=to_Vec+s[it];
			}

			//debug below
			cout << "I received " << pnum << " head(s). Here are contents below:" << endl;
			for(unsigned it=0; it<head.size(); ++it){
				cout << '\t' << head[it] << endl;
			}
		}
    //store option nums
		void option_value(string s){
			enum valival{
				noAccess=0,
				vsOnly=1,
				resOnly=2,
				sboth=3
			};

			if(s.length()!=pnum*2-1)
				throw "WTF that 2nd line is! Its length is terrible!";

			unsigned i=0;
			while(i<s.length()){
				if(i%2==0){
					switch(s[i]){
						case '0':
							opn.push_back(noAccess);
							break;
						case '1':
							opn.push_back(vsOnly);
							break;
						case '2':
							opn.push_back(resOnly);
							break;
						case '3':
							opn.push_back(sboth);
							break;
						default:
							throw "WTF THAT 2nd line is! Not available num!";
					}
				}else{
					if(s[i]!='\t')
						throw "WTF THAT 2nd line is! Y U NO SEPARATE w/ TAB?!";
				}
				i++;
			}

			//debug below
      cout << "Thanks, I received these options: ";
			for(unsigned i=0; i<opn.size(); i++){
        //cout << i << ' ';
				cout << opn[i] << ' ';
			}
			cout << endl;
		}

    //store subs
		void input(string inp, unsigned line_number){
			unsigned cont=0;
			string sto="";
			unsigned at=sub.size();
      sub.resize(at+1);
      //cout << "sub.size():" << at << endl << inp.length() << endl;
			for(unsigned i=0; i<inp.length(); i++){
        //cout << i;
				if(inp[i]=='\t'){
					sub[at].push_back(sto);
					sto="";
					cont++;
				}else if(i+1==inp.length()){
					sto=sto+inp[i];
					sub[at].push_back(sto);
					cont++;
				}else{
					sto=sto+inp[i];
				}
        //cout << i;
			}
      //cout << "\n";
      //cout << "LineNo:" << line_number << '\t';
			if(cont!=pnum){
        string errs="input error! @line: ";
        errs+=to_string(line_number);
        errs+=" (fix its 4mat.)";
				throw errs;
			}

      //cout << "hi.\n";

			//debug below
			for(unsigned j=0; j<sub[at].size(); j++){
				cout << sub[at][j] << '\t';
			}
			cout << endl;
		}
    inline unsigned get_subnum(){
      return sub.size();
    }
};
