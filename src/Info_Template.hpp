InfoBase::~InfoBase(){
	//printf("\t~InfoBase()\n");

}





template<typename D>
Info<D>::
Info(const D* dPtr) : count(1), dPtr(dPtr) {
	//printf("\tInfo(const D* dPtr)\n");
}


template<typename D>
Info<D>::
~Info() {
	//printf("\t~Info()\n");	
	this->deleteData();
}


template<typename D>
void
Info<D>::
inc(){
	//printf("\tinc()\n");	
	++count;
}


template<typename D>
bool
Info<D>::
dec(){
	//printf("\tdec()\n");	
	unsigned long long num_before; 
	num_before = count.fetch_sub(1, std::memory_order_relaxed);
	//std::cout << "num_before: " << num_before << std::endl;	
	if(num_before == 1) return true;
	return false;
}


template<typename D>
bool
Info<D>::
isNull(){
	//printf("\tisNull()\n");	
	return !dPtr;
}



template<typename D>
void
Info<D>::
deleteData(){
	//printf("\tdeleteData()\n");	
	delete this->dPtr;
}
