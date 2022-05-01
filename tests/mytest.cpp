#include "SharedPtr.hpp"
template class cs540::SharedPtr<int>;
template class cs540::SharedPtr<long>;

void forMovePassVal(cs540::SharedPtr<int> sPtr);
cs540::SharedPtr<int> forMoveReturn();

int main(){

	//cs540::SharedPtr<int> sp2(new int(1));
	cs540::SharedPtr<int> sp1(new int(1));
	cs540::SharedPtr<int> sp2 = sp1;
	cs540::SharedPtr<int> sp3 = std::move(sp1);
	//forMovePassVal(std::move(sp1));
	//cs540::SharedPtr<int> sp4 = forMoveReturn();
	//sp4 = forMoveReturn();
	//cs540::SharedPtr<long> sp5(sp2);



	cs540::SharedPtr<int> a(new int(3));
	std::cout << *a << std::endl;	
	*a = 100;
	std::cout << *a << std::endl;
	a = std::move(a); 
	std::cout << *a << std::endl;

	cs540::SharedPtr<int> b(new int(3));
	std::cout << *b << std::endl;	
	b = cs540::SharedPtr<int>(b);
	std::cout << *b << std::endl;
	std::cout << "self assign" << std::endl;	
	b = b;
	std::cout << *b << std::endl;

	cs540::SharedPtr<int> c(std::move(b));
	std::cout << *c << std::endl;
	//std::cout << *b << std::endl; // throws error as it should
	
	cs540::SharedPtr<float> d(new float(3.14));
	std::cout << *d << std::endl;
	cs540::SharedPtr<float> e(d);
	std::cout << *e << std::endl;

	int *z = new int(22);
	cs540::SharedPtr<int> f(z);
	//cs540::SharedPtr<float> g(f);
	
	std::cout << "Test Complete" << std::endl;
}













//void forMovePassVal(cs540::SharedPtr<int> sPtr){
	// just a test
//}


cs540::SharedPtr<int> forMoveReturn() {
    cs540::SharedPtr<int> sPtr(new int(99));
    return sPtr; 
}
