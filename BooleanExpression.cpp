#include "BooleanExpression.h"
using namespace std;

void BooleanExpression::print_all() const
{
	cout << boolalpha << "Is "; print(); cout << " tauthology?     " << is_tauthology() << endl;
	cout << boolalpha << "Is "; print(); cout << " contradiction?  " << is_contradiction() << endl;
	cout << boolalpha << "Is "; print(); cout << " contingency?    " << is_contingency() << endl;
}

