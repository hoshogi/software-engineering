#include "Shopping.h"

// Function : RegisterItem::RegisterItem()
// Description : RegisterItem Constructor
// Return Value : void
// Created : 2022/6/2 4:02 pm
// Author : Hoseok Lee
RegisterItem::RegisterItem() {
	RegisterItemUI registerItemUI;
	registerItemUI.registerNewItem(this);
}