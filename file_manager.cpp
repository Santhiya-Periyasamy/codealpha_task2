#include<iostream>
#include<string>
#include<algorithm>
#include<direct.h>
#include<windows.h>
#include<fstream>
using namespace std;

fstream file;
fstream file1;
fstream file2;

class file_manager{
  public:
  void view(string file_name)
  {
    file.open(file_name,ios::in);
    if(!file)
    {
      cout<<"Error : File not found"<<endl;
    }
    else{
      string temp;
      cout<<"File opened"<<endl;
      while(getline(file,temp)){
        cout<<temp<<endl; 
      }
    }
  }

  void move(string file_name1,string file_name2)
  {
    copy(file_name1,file_name2);
    remove(file_name1.c_str());      
    cout<<"File is moved successfully"<<endl;
  }
  void copy(string file_name1,string file_name2)
  {
   file1.open(file_name1,ios::in);
   file2.open(file_name2,ios::out);
   
   if(file2.is_open() && file1.is_open()){
    string temp;
    while(getline(file1,temp))
    {
      file2<<temp<<endl;
    }
    cout<<"File copied successfully"<<endl;
   }
   else {
    cout<<"Error : File1 not found"; }
  }
  void create_directories()
  {
     cout<<"\n\n>>Enter the name of the directory you want to create: ";
    string dir_name;
    cin>>dir_name;
    if(_mkdir(dir_name.c_str())==0){
        cout<<"\n\n>>Directory created successfully"<<endl;
    }
    else{
        perror(">>Error creating directory");
    }
  }
  void navigate_directories()
  {
     cout<<"\n\n>>Enter the name of the directory you want to navigate: ";
    string dir;
    cin>>dir;
    if(_chdir(dir.c_str())==0){
        cout<<"\n\n>> Successfully navigated to directory: "<<dir<<endl;
    }
    else{
        perror(">>Error Navigating to directory");
    }
  }
};

int main()
{
  string file_name1,file_name2,ch;
  int opt;
  file_manager f1;
  cout<<"*****FILE MANAGER*****"<<endl;
  do{
    cout<<"\n1.View file\n2.copy (or) move file\n3.Create directory\n4.Navigate directory\n5.Exit"<<endl;
    cout<<"Enter your option number : ";
    cin>>opt;
    switch(opt)
    {
      case 1:
         cout<<"Enter file name/path :";
         cin.ignore();
         getline(cin,file_name1);
         file_name1.erase(std::remove(file_name1.begin(), file_name1.end(), '"'), file_name1.end());
         f1.view(file_name1);
         break;
      case 2:
         cout<<"Do you want to copy or move :";
         cin>>ch;
         cout<<"Enter 1st file name/path : ";
         cin.ignore();
         getline(cin,file_name1);
         file_name1.erase(std::remove(file_name1.begin(), file_name1.end(), '"'), file_name1.end());
         cout<<"Enter 2nd file name/path : ";
         cin.ignore();
         getline(cin,file_name2);
         file_name2.erase(std::remove(file_name2.begin(), file_name2.end(), '"'), file_name2.end());
         if(ch=="copy")
         { f1.copy(file_name1,file_name2); }
         else
           f1.move(file_name1,file_name2);
        break;
      case 3:
          f1.create_directories();
          break;
      case 4:
          f1. navigate_directories();
          break;
      case 5:
         exit(0);
    }
  }while(1);
  
  return 0;
}