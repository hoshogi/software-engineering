#include <string>
#include "Item.h"
using namespace std;

// Class : ItemList
// Description : list contains item
// Created : 2022/6/1 23:07 pm
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class ItemList {
private:
    Item* itemList[50];
    int nowSearchItemIndex;
    int numberOfItem;
public: 
    ItemList();
    Item* searchItem(string itemName);
    Item* rateItem(string itemName, int myRating);
    Item* buyItem();
    void addNewItem(string sellerName, string itemName, string companyName, int price, int numberOfItem);
};