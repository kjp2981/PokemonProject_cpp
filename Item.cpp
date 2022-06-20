#include "Item.h"

bool Item::IsUseItem(int amount)
{
	return count > amount;
}
