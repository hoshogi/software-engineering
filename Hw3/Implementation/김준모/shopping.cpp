#include <iostream>
#include <string>
#include <list>
#include "shopping.h"

using namespace std;

#define MAX_STRING 32

// Function : string getSellerName()
// Description : function gets sellerName
// Return Value : string
// Created : 2022/5/31 21:03 pm
// Author : ±èÁØ¸ð
string Item::getSellerName()
{
	return sellerName;
}

// Function : string getitemName()
// Description : function gets itemName
// Return Value : string
// Created : 2022/5/31 21:04 pm
// Author : ±èÁØ¸ð
string Item::getItemName()
{
	return itemName;
}

// Function : string getcompanyName()
// Description : function gets companyName
// Return Value : string
// Created : 2022/5/31 21:05 pm
// Author : ±èÁØ¸ð
string Item::getCompanyName()
{
	return companyName;
}

// Function : int getPrice()
// Description : function gets sellerName
// Return Value : int
// Created : 2022/5/31 21:06 pm
// Author : ±èÁØ¸ð
int Item::getPrice()
{
	return price;
}

// Function : int getNumberOfItem()
// Description : function gets numberOfItem
// Return Value : int
// Created : 2022/5/31 21:06 pm
// Author : ±èÁØ¸ð
int Item::getNumberOfItem()
{
	return numbuerOfItem;
}

// Function : double getRating()
// Description : function gets rating
// Return Value : double
// Created : 2022/5/31 21:07 pm
// Author : ±èÁØ¸ð
double Item::getRating()
{
	return (rating/ratingNumberCount);
}

// Function : Item showItemInfo(string itemName)
// Description : searches item from itemList and returns item object
// Parameters : string itemName (item's name)
// Return Value : Item (Item object)
// Created : 2022/5/31 21:33 pm
// Author : ±èÁØ¸ð
Item SearchItem::showItemInfo(string itemName)
{

}
