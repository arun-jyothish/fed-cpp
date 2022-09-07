#include <iostream>
#include <vector>
#include <string>

using namespace std; 
bool ispal(string);
vector<string> getPalSq(string& line);
template <typename T>
ostream& operator<<(ostream& co,const vector<T>& data){
	for (auto val: data){
		co<<val<<'\t';
	}
	return co;
}
template<typename T>
string largest_element(vector<T>& v);
int main(int argc, char *argv[])
{
	vector<string> sq;	
	/* string line = "large sequence of code"; */
	string line = "malayalam";
	/* string line = "annamma"; */
	/* cin>>line; */
	sq = getPalSq(line);
	cout<<sq;
	cout<<endl;
	cout<< (ispal(line)?"palindrome":"not palindrome");
	cout<<endl<<"largest palindrome sq: "<<largest_element(sq)<<endl;
	cout<<endl;
	return 0;
}
template<typename T>
string largest_element(vector<T>& v){
	string str="";	
	for (auto val: v){
		if(str.length()<val.length()){
			str = val;
		}
	}
	return str;
}
vector<string> getPalSq(string& line){
	int sz = line.length();
	cout<<sz<<endl;
	vector<string> sq;	
	for (int i=0;i<sz;i++){
		for (int j=0;j<sz;j++){
			if ( line[i]==line[j] )	{
				string sub = line.substr(i,sz-(i+j));
				if(ispal(sub)){
					sq.push_back(sub);
					/* cout<<sub<<endl; */
				}
			}
		}
	}
	return sq;
}

bool ispal(string s){
	int sz = s.length();	
	int i=0,j=sz-1 ;
	for(; i<sz; ++i,--j){
		if (s[i] != s[j]){
			return 0;
		}
	}
	return 1;
}
