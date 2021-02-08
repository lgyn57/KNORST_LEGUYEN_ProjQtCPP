#ifndef DEF_TEST_PILE_HPP
#define DEF_TEST_PILE_HPP
#include <cstdlib>
#include <stdexcept>

namespace td2Pile
{
	class pile
	{
	protected:
		/**
         * D e f i n i t i o n
         */
		typedef struct PileElement
		{
			
		}PileElement, *Pile;


	public:
		/**
         * M e t h o d s
         */

		//CONSTRUCTOR
		pile();

		//DESTRUCTOR
		~pile();

		Pile new_pile(void);

		bool is_EmptyPile(Pile p);

		Pile push_pile(Pile p, int n);
	};
}