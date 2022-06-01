
#include <string>

using namespace std;

// Class : Item
// Description : item class
// Created : 2022/6/1 21:36 pm
// Author : ±èÁØ¸ð
// mail : a00700c@g.hongik.ac.kr
class Item
{
private:
	string sellerName;
	string itemName;
	string companyName;
	int price;
	int numberOfItem;
	int totalRating = 0;
	int numberOfRating = 0;
public:
	Item(string sellerName, string itemName, string companyName, int price, int numberOfItem);
	string getSellerName();
	string getItemName();
	string getCompanyName();
	int getPrice();
	int getNumberOfItem();
	int getRating();
	Item buyItem();
	void rateItem(int myRating);
};
