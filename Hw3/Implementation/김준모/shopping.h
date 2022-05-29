#include <iostream>
#include <string>
using namespace std;


typedef struct {
	string sellerName;
	string itemName;
	string companyName;
	int price;
	int numberOfItem;
	float rating;
} ItemInfo;

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
	ItemInfo getItemInfo(string itemName);
	void buyItem(string itemName);
	RatingInfo saveRate(int rating);
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
	void searchItemByName(string itemName);
};


// Class : SearchItem
// Description : control class that searches item
// Created : 2022/5/30 00:01 am
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class SearchItem
{
public:
	ItemInfo showItemInfo(string itemName);
};


// Class : BuyItemUI
// Description : boundary class when user buys item
// Created : 2022/5/30 00:03 am
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class BuyItemUI
{
public:
	void buyItem(string itemName);
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