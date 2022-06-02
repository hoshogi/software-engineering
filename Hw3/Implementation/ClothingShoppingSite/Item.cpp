#include "Shopping.h"
#include <string>
#include <cmath>

using namespace std;

// Function : Item(string sellerName, string itemName, string companyName, int price, int numberOfItem)
// Description : Item constructor
// Parameters : string sellerName, string itemName, string companyName, int price, int numberOfItem
// Created : 2022/6/1 21:40 pm
// Author : ���ظ�
Item::Item(string sellerId, string itemName, string companyName, int price, int numberOfItem) {
    this->sellerId = sellerId;
    this->itemName = itemName;
    this->companyName = companyName;
    this->price = price;
    this->numberOfItem = numberOfItem;
}

// Function : string Item::getSellerName()
// Description : get sellerName attribute
// Return value : string
// Created : 2022/6/1 22:05 pm
// Author : ���ظ�
string Item::getSellerId() {
    return sellerId;
}

// Function : string Item::getItemName()
// Description : get itemName attribute
// Return value : string
// Created : 2022/6/1 22:05 pm
// Author : ���ظ�
string Item::getItemName() {
    return itemName;
}

// Function : string Item::getCompanyName()
// Description : get companyName attribute
// Return value : string
// Created : 2022/6/1 22:05 pm
// Author : ���ظ�
string Item::getCompanyName() {
    return companyName;
}


// Function : int Item::getPrice()
// Description : get price attribute
// Return value : int
// Created : 2022/6/1 22:06 pm
// Author : ���ظ�
int Item::getPrice() {
    return price;
}

// Function : int Item::getNumberOfItem()
// Description : get numberOfItem attribute
// Return value : int
// Created : 2022/6/1 22:06 pm
// Author : ���ظ�
int Item::getNumberOfItem() {
    return numberOfItem;
}

// Function : int Item::getRating()
// Description : calculate rating and return
// Return value : int
// Created : 2022/6/1 22:06 pm
// Author : ���ظ�
int Item::getRating() {
    int a;
    if (numberOfRating == 0)
        return 0;
    else {
        a = round((double)totalRating / numberOfRating);
        return a;
    }
}

// Function : void Item::buyItem()
// Description : numberOfItem�� 1 ���� �����ش�.
// Return value : void
// Created : 2022/6/1 22:18 pm
// Author : ���ظ�
void Item::buyItem() {
    numberOfItem -= 1;
}


// Function : void Item::rateItem(int myRating)
// Description : ���� �Է��� ������ �����ش�.
// Return value : void
// Parameters : ���� �Է��� �������� parameter�� �޴´�.
// Created : 2022/6/1 22:18 pm
// Author : ���ظ�
void Item::rateItem(int myRating) {
    totalRating += myRating;
    numberOfRating += 1;
}