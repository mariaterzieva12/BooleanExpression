#include "BooleanExpression.h"

class Operation : public BooleanExpression
{
public:
	Operation(BooleanExpression*, const char*, BooleanExpression*);
	Operation(const Operation&);
	Operation& operator=(const Operation&);
	~Operation();
	const char* getSymbol() const;
	void setSymbol(const char*);
	BooleanExpression* getLeft() const;
	BooleanExpression* getRight() const;
	void setLeft(BooleanExpression*);
	void setRight(BooleanExpression*);
	void print() const;
	int getNumberOfVars() const;
protected:
	void copy(const Operation&);
private:
	const char* symbol;
	BooleanExpression* left;
	BooleanExpression* right;
};

bool operator==(const Operation&, const Operation&);

