#include<iostream>
#include<filesystem>
using namespace std;
namespace fs=std::filesystem; // we can using fs instead of std::filesystem:: ...
string name;
int main(){
    string path="D:/Games";
    for(const auto& entry:fs::directory_iterator(path)){  //const auto& entry is important as it holds directory of each file/folder
        cout<<entry.path().filename()<<endl;  //.path is for printing the full path of the entry which contains a single file 
        name=entry.path().filename().string(); // To copy the name of the file/folder we need to add .string() in the end.
    }

    cout<<endl<<name; //prints the last folder in the directory
    return 0;
}