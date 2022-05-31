#include <iostream>
#include <string>
#include <list>

using namespace std;


typedef struct {
	string sellerName;
	string itemName;
	float averageRating;
} RatingInfo;


// Class : Item
// Description : item class
// Created : 2022/5/29 00:23 am
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class Item
{
private:
	string sellerName;
	string itemName;
	string companyName;
	int price;
	int numbuerOfItem;
	int rating = 0;
	int ratingNumberCount = 0;

public:
	void addNewItem();
	Item getItemInfo(string itemName);
	void buyItem(string itemName);
	RatingInfo saveRate(int rating);
	string getSellerName();
	string getItemName();
	string getCompanyName();
	int getPrice();
	int getNumberOfItem();
	double getRating();
};


// Class : ItemList
// Description : list that contiains items
// Created : 2022/5/31 20:15 pm
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class ItemList
{
private:
	list<Item> items;
public:
	Item searchList(string itemName);
};


// Class : BuyItemList
// Description : list that saves buy item names
// Created : 2022/5/29 02:23 am
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class BuyItemList
{
private:
	string buyItemNames[50] = {"",};
public:
	BuyItemList();
	void addBuyItemList(string itemName);
	int* getBuyItemList();
	~BuyItemList();
}; 


// Class : SearchItemUI
// Description : boundary class when user searches item
// Created : 2022/5/30 00:00 am
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class SearchItemUI
{
public:
	void searchItemByName();
};


// Class : SearchItem
// Description : control class that searches item
// Created : 2022/5/30 00:01 am
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class SearchItem
{
public:
	Item showItemInfo(string itemName);
};


// Class : BuyItemUI
// Description : boundary class when user buys item
// Created : 2022/5/30 00:03 am
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class BuyItemUI
{
public:
	void buyItem();
};


// Class : BuyItem
// Description : control class that buys item
// Created : 2022/5/30 00:07 am
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class BuyItem
{
public:
	void buyItem(string itemName);
};


// Class : BuyItemCheckUI
// Description : boundary class when user views buyitemlist
// Created : 2022/5/31 21:53 pm
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class BuyItemCheckUI
{
public:
	void checkBuyItemList();
};


// Class : RateItemUI
// Description : boundary class when user rates item
// Created : 2022/5/31 21:55 pm
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class RateItemUI
{
public:
	void rateItem();
};