#include "Conjunction.h"

Conjunction::Conjunction(BooleanExpression* left, BooleanExpression* right) :
	Operation(left, "&", right) {}

Conjunction::Conjunction(const Conjunction& conjunction)
	: Operation(conjunction.getLeft(), "&", conjunction.getRight()) {};

Conjunction& Conjunction::operator=(const Conjunction& conjunction)
{
	if (this != &conjunction)
		copy(conjunction);
	return *this;
}

bool Conjunction::is_contingency() const
{
	return !is_tauthology() && !is_contradiction();
}

bool Conjunction::is_tauthology() const
{
	return getLeft()->is_tauthology() && getRight()->is_tauthology();
}

bool Conjunction::is_contradiction() const
{
	return getLeft()->is_contradiction() || getRight()->is_contradiction();
}