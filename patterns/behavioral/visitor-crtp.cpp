#include <iostream>

namespace visitorCrtp
{

class Square;
class Circle;

class Visitor
{
public:
	void visit(Square& s) const { std::cout << "visit square\n"; }
	void visit(Circle& c) const { std::cout << "visit circle\n"; }
};


template<typename DerivedT>
class VisitorAcceptor
{
public:
	void accept(const Visitor& v) {
		v.visit(static_cast<DerivedT&>(*this));
	}
};

class Square : public VisitorAcceptor<Square>
{
	int height = 0;
	int width = 0;
};

class Circle : public VisitorAcceptor<Circle>
{
	int x0 = 0;
	int y0 = 0;
	int r = 0;
};

template<typename DerivedT>
void use(VisitorAcceptor<DerivedT>& arg) 
{
	Visitor v;
	arg.accept(v);
}

} // visitorCrtp 


int main()
{
	using namespace visitorCrtp;

	Square s;
	use(s);

	Circle c;
	use(c);

	return 0;
}
