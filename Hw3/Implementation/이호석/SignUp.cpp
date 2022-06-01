#include "Shopping.h"
#include <string>
using namespace std;

SignUp::SignUp() {
	SignUpUI signUpUI;
	signUpUI.createNewMember(this);
}