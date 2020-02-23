// Programming II - Department of Bioengineering at Imperial College London
// 2015 Exam
// Question q5.c


#include<iostream>
#include<fstream>
#include<stdlib.h> 
#include<algorithm>

using namespace std;

void count_basepairs(int *p_base,const string& str_in);

int main()
{
	ifstream inFile;
	
	string file_name = "q5in.txt";
	inFile.open(file_name.c_str());
	
	if(!inFile){
		cerr<<"Unable to oopen file "<<	file_name;
		exit(1);
	}
	
	int base_pairs[4] = {0,0,0,0};
	char base_name[4] = {'A','C','G','T'};
	
	while(!inFile.eof()){
		int INPUT1;
		string INPUT2, INPUT3;
		
		inFile >> INPUT1 >> INPUT2 >> INPUT3;
		
		cout<< INPUT1 << ' ' << INPUT2 << ' ' << INPUT3;
	
		count_basepairs(base_pairs,INPUT3);
		for(int i = 0;i < sizeof(base_name); i++){
			cout << ' ' << base_name[i] << ":" << base_pairs[i];
		}
		cout <<'\n';
	}
	inFile.close();
	
	
	// write code here
	
	return 0;	
}

void count_basepairs(int *p_base,const string& str_in){
	char base_name[4] = {'A','C','G','T'};
	for(int i = 0; i < 4; i++){
		p_base[i] = count(str_in.begin(),str_in.end(),base_name[i]);
	}
}