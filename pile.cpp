#include <cstdio>
#include <cstdlib>

#include "pile.hpp"

Pile new_pile(void)
{
	return NULL;
}

/**
 * ---------------------------------------------------------------------
 */

bool is_EmptyPile(Pile p)
{
	if (p == NULL)
		return true;
	
	return false;
}