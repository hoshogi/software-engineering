#include <string>
using namespace std;

// Class : Member
// Description : store member info
// Created : 2022/6/1 9:42 pm
// Author : Hoseok Lee
// mail : hoshogi@gmail.com
class Member {
private:
    string name;
    string residentNumber;
    string id;
    string password;
public: 
    
    Member(string name, string residentNumber, string id, string password);
    string getId();
    string getPassword();  
    string getName();
};