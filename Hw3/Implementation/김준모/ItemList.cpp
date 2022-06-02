#include "Shopping.h"
using namespace std;

// Function : ItemList()
// Description : Itemlist Constructor
// Created : 2022/6/1 23:10 pm
// Author : ±èÁØ¸ð
ItemList::ItemList() {
    fill_n(itemList, 50, NULL);
    nowSearchItemIndex = -1;
    numberOfItem = 0;
}


// Function : ItemList::searchItem(string itemName)
// Description : searches item from itemlist and returns item
// Return Value : Item
// Parameters : string itemName
// Created : 2022/6/1 23:11 pm
// Author : ±èÁØ¸ð
Item* ItemList::searchItem(string itemName) {
    for (int i = 0; i < numberOfItem; i++) {
        if (itemList[i]->getItemName() == itemName) {
            nowSearchItemIndex = i;
            return itemList[i];
        }
    }
    return NULL;
}


// Function : ItemList::rateItem(string itemName, int myRating)
// Description : searches item from itemlist and rates and returns it
// Return Value : Item
// Parameters : string itemName, myRating
// Created : 2022/6/1 23:24 pm
// Author : ±èÁØ¸ð
Item* ItemList::rateItem(string itemName, int myRating) {
    Item* check = searchItem(itemName);
    if (check != NULL) {
        check->rateItem(myRating);
        return check;
    }
    return NULL;
}


// Function : ItemList::buyItem()
// Description : buys item, if numberOfItem == 0: delete Item, 
// Return Value : Item
// Created : 2022/6/1 23:32 pm
// Author : ±èÁØ¸ð
Item* ItemList::buyItem() {
    itemList[nowSearchItemIndex]->buyItem();
    if (itemList[nowSearchItemIndex]->getNumberOfItem() == 0) {
        delete itemList[nowSearchItemIndex];
        return NULL;
    }
    return itemList[nowSearchItemIndex];
}


// Function : ItemList::addNewItem(string sellerName, string itemName, string companyName, int price, int numberOfItem)
// Description : adds item into itemlist
// Return Value : void
// Parameters : seller's name, item's name, company name, price, numberOfitem
// Created : 2022/6/1 23:13 pm
// Author : ±èÁØ¸ð
void ItemList::addNewItem(string sellerName, string itemName, string companyName, int price, int numberOfItem) {
    itemList[numberOfItem++] = new Item(sellerName, itemName, companyName, price, numberOfItem);
}