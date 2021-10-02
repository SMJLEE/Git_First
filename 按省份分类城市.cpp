#include<iostream>
#include<fstream>
#include<string>
using namespace std;

 
 int main()
 {
 	int num[100];
 	string province[100],city[100];
 	
 	ifstream srcFile("D:\\ศํนค1901\\yq_in.txt",ios::in);
 	if(!srcFile)
	 {
	 	cout<<"error opening source file."<<endl;
	 	return 0;
	 }
	 
	 ofstream destFile("D:\\ศํนค1901\\yq_out.txt",ios::trunc);
	 if(!destFile)
	 {
	 	srcFile.close();
	 	cout<<"error opening destination file."<<endl;
	 	return 0;
	 }
	 
	for(int i = 0 ; i < 100 ; i++)
	{
		srcFile >> province[i] >> city[i] >> num[i];
	}
	string s = province[0];
	int flog = 0;
	for(int i = 0 ; i < 100 ; i++)
	{
		if(province[i] == s && flog == 0){
			destFile << province[i] <<endl;
			flog = 1;
			destFile << city[i] << "	" << num[i] <<endl;
		}
		else if(province[i] == s && flog == 1){
			destFile << city[i] << "	" << num[i] <<endl;
		}
		else if(province[i] != s){
			s = province[i];
			destFile << endl;
			destFile << province[i] <<endl;
			destFile << city[i] << "	" << num[i] <<endl;
		}
	}
		 
		 destFile.close();
		 srcFile.close();
		 return 0;
 	
 }

