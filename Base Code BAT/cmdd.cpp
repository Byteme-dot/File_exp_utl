#include<iostream>
#include <windows.h>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

WCHAR username[256];
int asadmin=0;

void helpf(){
    cout<<endl<<"- - - - - - Commands - - - - - -"<<endl;
    cout<<"Delete - rm <filedirectory> (This is permanent)"<<endl;
    cout<<"Copy and Paste - cp <filedirectory> <pastingdirectory>"<<endl;
    cout<<"Open File - op <filedirectory>"<<endl;
    cout<<"To exit program - EXIT"<<endl;
    cout<<"Display all files in the directory - list"<<endl;
    cout<<"Go to a directory - goto <directory>"<<endl;
    cout<<"Go to Desktop directory - DESKTOP"<<endl;
    cout<<"Go to Download directory - DOWNLOAD"<<endl;
    cout<<"Go to Document directory - DOCUMENT"<<endl;
    cout<<"Go to Picture directory - PICTURE"<<endl;
    cout<<"Go to Video directory - VIDEO"<<endl;
    cout<<endl<<"- - - - - - - - - - - - - - - - -"<<endl;
}

int verifyadmin() {
    string password, ipassword,repassword;
    ifstream file("pas.dat", ios::binary);

    if (file.is_open()) {
        getline(file, password);
        file.close();
        cout << "Enter Password: ";
        cin.ignore();
        getline(cin, ipassword);
        if (ipassword==password){
            cout<<"Welcome Admin !"<<endl;
            return 1;
        }else{
            cerr<<"Incorrect Password!"<<endl;
            return 0;
        }
    }else{
        cerr<<"You need to create a new password"<<endl;
        ofstream file("pas.dat", ios::binary);
        if (file.is_open()){
            cout<< "Enter New Password: ";
            cin.ignore();
            getline(cin, repassword);
            file<<repassword; 
            file.close();
            cout<<"Password Saved Successfully!"<<endl;
            return 1;
        }else{
            cerr<<"Error: Could not create file!"<<endl;
            return 0;
        }
    }
}


void runasadmin(){
    string adinput;
    while(true){
        cout<<"Type !help for commands"<<endl;
        cout<<"BAT C:/Users/admin>> ";
        cin.ignore();
        getline(cin,adinput);
        if(adinput=="!help"){
            helpf();
        }else if (adinput=="EXIT"){
            break;
            exit(1);
        }
        
    }
}

void runasuser(){
    string usinput;
    while(true){
        cout<<"Type !help for commands"<<endl;
        cout<<"BAT C:/Users/admin>> ";
        cin.ignore();
        getline(cin,usinput);
        if(usinput=="!help"){
            helpf();
        }else if (usinput=="EXIT"){
            break;
            exit(1);
        }
    }
}

void startingterminal() {
    DWORD username_len = 256;

    if (GetUserNameW(username, &username_len)){
    }else{
        wcscpy(username, L"user"); // Assign default username
    }

    cout<<"Loading File Explorer CLI";
    for (int i = 0; i < 3; i++) {
        Sleep(1000);
        cout<<".";
    }
    cout<<endl<<"Copyright (C) ByteArch Terminal (BAT). All rights reserved."<<endl;
    cout<<endl<<"A File Explorer CLI Project by ByteArch!"<<endl;
    wcout<<endl << L"Welcome " << username << L" !" <<endl;
    
}


int main(){
    int a;
    startingterminal();
    while(true){
        cout<<"Run As Admin?(1-true,0-false)>>";
        cin>>asadmin;
        if(asadmin!=1 && asadmin!=0){
            cout<<"Enter a valid input!!"<<endl;
        }else{
            break;
        }
    }
    if(asadmin==1){
        a=verifyadmin();
        if(a==1){
            runasadmin();
        }else{
            runasuser();
        }
    }else{
        runasuser();
    }
    
    
    exit(0);
    return 0;
}