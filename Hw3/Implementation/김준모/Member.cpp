#include "Shopping.h"

// Function : Member(string name, string residentNumber, string id, string password)
// Description : Member Constructor
// Return Value : void
// Created : 2022/6/1 9:48 pm
// Author : Hoseok Lee
Member::Member(string name, string residentNumber, string id, string password) : name(name), residentNumber(residentNumber), id(id), password(password) {
    buyItemList = new BuyItemList();
}

// Function : Member::getId()
// Description : return id
// Return Value : string
// Created : 2022/6/1 9:50 pm
// Author : Hoseok Lee
string Member::getId() {
    return id;
}

// Function : Member::getPassword()
// Description : return password
// Return Value : string
// Created : 2022/6/1 9:51 pm
// Author : Hoseok Lee
string Member::getPassword() {
    return password;
}

// Function : Member::getName()
// Description : return name
// Return Value : string
// Created : 2022/6/1 9:51 pm
// Author : Hoseok Lee
string Member::getName() {
    return name;
}


// Function : Member::getBuyItemList()
// Description : return BuyItemList pointer
// Return Value : BuyItemList pointer
// Created : 2022/6/2 03:07 am
// Author : ±èÁØ¸ð
BuyItemList* Member::getBuyItemList(){
    return buyItemList;
}