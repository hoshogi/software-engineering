#include "Shopping.h"
#include <string>
using namespace std;

// Function : SignUp::SignUp()
// Description : SignUp Constructor
// Return Value : void
// Created : 2022/6/2 2:40 pm
// Author : Hoseok Lee
SignUp::SignUp() {
	SignUpUI signUpUI;
	signUpUI.createNewMember(this);
}