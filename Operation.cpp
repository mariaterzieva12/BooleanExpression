#include "Operation.h"

using namespace std;

Operation::Operation(BooleanExpression* left, const char* symbol, BooleanExpression* right)
	: BooleanExpression(), left(left), right(right), symbol(symbol) {}

Operation::Operation(const Operation& operation) : BooleanExpression()
{
	copy(operation);
}

Operation& Operation::operator=(const Operation& operation)
{
	if (this != &operation)
		copy(operation);
	return *this;
}

Operation::~Operation()
{
	delete left;
	delete right;
}

const char* Operation::getSymbol() const
{
	return this->symbol;
}

void Operation::setSymbol(const char* symbol)
{
	this->symbol = symbol;
}

BooleanExpression* Operation::getLeft() const
{
	return this->left;
}

BooleanExpression* Operation::getRight() const
{
	return this->right;
}

void Operation::setLeft(BooleanExpression* left)
{
	delete this->left;
	this->left = left;
}

void Operation::setRight(BooleanExpression* right)
{
	delete this->right;
	this->right = right;
}

void Operation::print() const
{
	cout << "(";
	left->print();
	cout << " " << symbol << " ";
	right->print();
	cout << ")";
}

int Operation::getNumberOfVars() const
{
	return left->getNumberOfVars + right;
}

void Operation::copy(const Operation& operation)
{
	setSymbol(operation.symbol);
	setLeft(operation.left);
	setRight(operation.right);
}

bool operator==(const Operation& left, const Operation& right)
{
	return left.getLeft() == right.getLeft()
		&& left.getRight() == right.getRight()
		&& strcmp(left.getSymbol(), right.getSymbol());
}