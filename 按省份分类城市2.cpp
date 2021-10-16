#include<iostream>
#include<fstream>
#include<string>
using namespace std;
 
 int main(int argc,char *argv[])
 {
 	for(int i=0;i<argc;i++)
 	{
 		cin>>argv[i];
 	}
 	string province[100],city[100];
 	int num[100];
 	
    ifstream srcFile(argv[1]);
 	if(!srcFile)
	 {
	 	cout<<"error opening source file."<<endl;
	 	return 0;
	 }
	 
	 ofstream getFile(argv[2]); 
	 if(!getFile)
	 {
	 	srcFile.close();
	 	cout<<"error opening destination file."<<endl;
	 	return 0;
	 }
	 //用for循环将文件内容读入数组 
	for(int i = 0 ; i < 100 ; i++)
	{
		srcFile >> province[i] >> city[i] >> num[i];
	}
	//判断是否有指定的省份输入 
	if(argc==4)
	{
	    getFile << argv[3]<<endl;
		for(int i = 0 ; i < 100 ; i++)	
		{
			if(province[i]==argv[3])
			{
				getFile << city[i] << "	" << num[i] <<endl;
			}
		}
	} 
	else
	{
		string s = province[0];
	    int flog = 0;
	    for(int i = 0 ; i < 100 ; i++)
	    {
		    if(province[i] == s && flog == 0){
			    getFile << province[i] <<endl;
			    flog = 1;
			    getFile << city[i] << "	" << num[i] <<endl;
		}
		else if(province[i] == s && flog == 1){
			getFile << city[i] << "	" << num[i] <<endl;
		}
		else if(province[i] != s){
			s = province[i];
			getFile << endl;
			getFile << province[i] <<endl;
			getFile << city[i] << "	" << num[i] <<endl;
		}
	}
		 
	}
		 getFile.close();
		 srcFile.close();
		 return 0;
 	
 }

