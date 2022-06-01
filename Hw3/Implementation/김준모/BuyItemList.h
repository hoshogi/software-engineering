#include <string>
using namespace std;

// Class : ItemList
// Description : list contains item
// Created : 2022/6/1 23:07 pm
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class BuyItemList {
private:
    string* buyItemNames[50];
    int numberOfBuyItem;
public: 
    BuyItemList();
    void addBuyItemList(string itemName);
    string* getBuyItemList();
};