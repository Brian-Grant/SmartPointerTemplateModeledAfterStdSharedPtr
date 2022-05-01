//#include "SharedPtr.hpp"


template <typename T>
SharedPtr<T>::
SharedPtr() : obj(nullptr), objInfo(nullptr) {
	//printf("\tAAA SharedPtr()\n");
}


template <typename T>
template <typename U> // explicit 
SharedPtr<T>::
SharedPtr(U *obj) : obj(obj), objInfo(new Info<U>(obj)) {
	//printf("\tBBB SharedPtr(U *obj)\n");
}

template <typename T>
SharedPtr<T>:: // just to be safe
SharedPtr(std::nullptr_t nullObj) : obj(nullObj), objInfo(nullObj) {
	//printf("\tCCC SharedPtr(null)\n");
}


template <typename T>
SharedPtr<T>::
SharedPtr(const SharedPtr &p) : obj(p.obj), objInfo(p.objInfo) {
	//printf("\tDDD SharedPtr(const SharedPtr &p)\n");
	if(p) this->obtain();
}



template <typename T>
template <typename U>
SharedPtr<T>:: 								
SharedPtr(const SharedPtr<U> &p) : obj(p.obj), objInfo(p.objInfo) {
	//printf("\tEEE SharedPtr(const SharedPtr<U> &p)\n");
	if(p) this->obtain();
}


template <typename T>
SharedPtr<T>::
SharedPtr(SharedPtr &&p) : obj(p.obj), objInfo(p.objInfo) {
	//printf("\tFFF SharedPtr(SharedPtr &&p)\n");	
	p.obj = nullptr;
	p.objInfo = nullptr;

}


template <typename T>
template <typename U> 
SharedPtr<T>::
SharedPtr(SharedPtr<U> &&p) : obj(p.obj), objInfo(p.objInfo) {
	//printf("\tGGG SharedPtr(SharedPtr<U> &&p)\n");	
	p.obj = nullptr;
	p.objInfo = nullptr;


}


template <typename T>
SharedPtr<T>& 
SharedPtr<T>::
operator=(const SharedPtr & sPtr){
	//printf("\tHHH operator=(const SharedPtr & sPtr)\n");	
	if(this == &sPtr) return *this;
	SharedPtr second(sPtr);
	//if(*this) this->discard();
	using std::swap;
	swap(this->obj, second.obj);
	swap(this->objInfo, second.objInfo);
	//if(sPtr) this->obtain();
	return *this;

}


template <typename T>
template <typename U>
SharedPtr<T>&
SharedPtr<T>::
operator=(const SharedPtr<U> &sPtr){
	//printf("\tIII operator=(const SharedPtr<U> &sPtr)");
	//if(this == static_cast<T*>(&sPtr)) return *this;
	SharedPtr second(sPtr);
	//if(*this) this->discard();
	using std::swap;
	swap(this->obj, second.obj);
	swap(this->objInfo, second.objInfo);
	//if(sPtr) this->obtain();
	return *this;
}



template <typename T>
SharedPtr<T>&
SharedPtr<T>::
operator=(SharedPtr &&p){
	//printf("\tJJJ operator=(SharedPtr &&p)\n");	
	if(this == &p){
		//std::cout << "self" << std::endl;
		return *this;
	}		
	if(*this) this->discard();
	this->obj = p.obj;
	this->objInfo = p.objInfo;
	p.obj = nullptr;
	p.objInfo = nullptr;
	return *this;
}



template <typename T>
template <typename U>
SharedPtr<T>&
SharedPtr<T>::
operator=(SharedPtr<U> &&p){
	//printf("\tKKK operator=(SharedPtr<U> &&p)\n");	
	if(*this) this->discard();
	this->obj = p.obj;
	this->objInfo = p.objInfo;
	p.obj = nullptr;
	p.objInfo = nullptr;
	return *this;
}



template <typename T>
SharedPtr<T>::
~SharedPtr(){
	//printf("\t~SharedPtr()\n");	
	if(*this) this->discard();
	//if(*this){
	//	printf("XXX found the problem\n");
	//}
	
}

template <typename T>
void
SharedPtr<T>::
reset(){
	//printf("\treset()\n");
	if(*this) this->discard();
	this->obj = nullptr;

}

template <typename T>
template <typename U>
void 
SharedPtr<T>:: 
reset(U *p){
	//printf("\treset(U *p)\n");	
	if(*this) this->discard();
	this->obj = p;
	this->objInfo = new Info<U>(p);
}


template <typename T>
T*
SharedPtr<T>::
get() const {
	//printf("\tget()\n");	
	if(*this) return this->obj;
	else {	
		throw "Dereferenced a nullptr\n";	
	}
	
}

template <typename T>
T&
SharedPtr<T>::
operator*() const{
	//printf("\toperator*()\n");	
	if(*this) return *(this->obj);
	else {	
		throw "Dereferenced a nullptr\n";	
	}
}

template <typename T>
T*
SharedPtr<T>::
operator->() const {
	//printf("\toperator->()\n");	
	if(*this) return this->obj;
	else {	
		throw "Dereferenced a nullptr\n";	
	}

}


template <typename T>
SharedPtr<T>::
operator bool() const {
	//printf("\toperator bool()\n");	
	return(this->obj);

}




template <typename T>
void
SharedPtr<T>::
obtain(){
	//printf("\tobtain()\n");	
	this->objInfo->inc();
}



template <typename T>
void
SharedPtr<T>::
discard(){
	//printf("\tdiscard()\n");	
	
	if(this->objInfo->dec()){
		delete this->objInfo;
		this->objInfo = nullptr;
	}
	
}












