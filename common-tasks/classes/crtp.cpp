#include <iostream>


namespace crtp
{

template<typename DerivedT>
class Base {
public: 
	void execute() {
		static_cast<DerivedT*>(this)->executeImpl();
	}

private:
	void executeImpl() {
		std::cout << "Base impl\n";	// default impl
	}
};


class Derived : public Base<Derived>
{
	friend class Base<Derived>;

private:
	void executeImpl() {
		std::cout << "Derived impl\n";
	}
};


class AnotherDerived : public Base<AnotherDerived>
{
	friend class Base<AnotherDerived>;

private:
	void executeImpl() {
		std::cout << "Another impl\n";
	}
};


class DefaultImplDerived : public Base<DefaultImplDerived>
{
	friend class Base<DefaultImplDerived>;
};

} // namespace crtp


template<typename DerivedT>
void use(crtp::Base<DerivedT>& arg)
{
	arg.execute();
}


int main()
{
	crtp::Derived d;
	use(d);

	crtp::AnotherDerived ad;
	use(ad);

	crtp::DefaultImplDerived dd;
	use(dd);
	return 0;
}