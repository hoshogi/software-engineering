#include "Shopping.h"
#include <string>
#include <algorithm>
using namespace std;

// Function : BuyItemList()
// Description : BuyItemlist Constructor
// Created : 2022/6/1 23:51 pm
// Author : ���ظ�
BuyItemList::BuyItemList() {
    fill_n(buyItemNames, 50, "");
    numberOfBuyItem = 0;
}

// Function : BuyItemList::addBuyItemList(string itemName)
// Description : adds itemName into BuyItemList
// Return Value : void
// Parameters : buy item's name
// Created : 2022/6/1 23:52 pm
// Author : ���ظ�
void BuyItemList::addBuyItemList(string itemName) {
    buyItemNames[numberOfBuyItem++] = itemName;
}

// Function : BuyItemList::getBuyItemList()
// Description : returns buyitemlist array and sort it
// Return Value : buy item's name array
// Created : 2022/6/1 23:54 pm
// Author : ���ظ�
string* BuyItemList::getBuyItemList() {
    return buyItemNames;
}