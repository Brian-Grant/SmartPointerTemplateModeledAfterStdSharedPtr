template <typename T1, typename T2>
bool operator==(const SharedPtr<T1> &one, const SharedPtr<T2> &two){
	//printf("\toperator==(const SharedPtr<T1> &one, const SharedPtr<T2> &two\n");
	if((!one) && (!two)) return true;
	else if((!one) || (!two)) return false;
	return one.get() == two.get();
}

template <typename T>
bool operator==(const SharedPtr<T> &one, std::nullptr_t){
	//printf("\toperator==(const SharedPtr<T> &one, std::nullptr_t)\n");
	return (!one);

}
template <typename T>
bool operator==(std::nullptr_t, const SharedPtr<T> &two){
	//printf("\toperator==(std::nullptr_t, const SharedPtr<T> &two)\n");
	return(!two);
}

template <typename T1, typename T2>
bool operator!=(const SharedPtr<T1>& one, const SharedPtr<T2> & two){
	//printf("\toperator!=(const SharedPtr<T1>& one, const SharedPtr<T2> & two)\n");
	return !(one == two);
}

template <typename T>
bool operator!=(const SharedPtr<T> &one, std::nullptr_t){
	//printf("\toperator!=(const SharedPtr<T> &one, std::nullptr_t)\n");
	return one;
}

template <typename T>
bool operator!=(std::nullptr_t, const SharedPtr<T> &two){
	//printf("\toperator!=(std::nullptr_t, const SharedPtr<T> &two)\n");	
	return two;
}
/*
template <typename T, typename U>
SharedPtr<T> static_pointer_cast(const SharedPtr<U> &sp){
	SharedPtr<T> ret(static_cast<SharedPtr<T>>(sp));
	return ret;

}

template <typename T, typename U>
SharedPtr<T> dynamic_pointer_cast(const SharedPtr<U> &sp){
	//const auto tmp = 	dynamic_cast<const SharedPtr<T>>(sp);
	auto tmp = dynamic
	SharedPtr<T> ret(dynamic_cast<SharedPtr<T&>>(sp));
	return ret;

}
*/

template <typename X, typename Y>
SharedPtr<X> static_pointer_cast(const SharedPtr<Y> &sp){
	//printf("\tstatic_pointer_cast(const SharedPtr<Y> &sp)\n");	
	//SharedPtr<T> ret(static_cast<SharedPtr<T>>(sp));
	//return ret;
	auto tmp = static_cast<X*>(sp.get());
	SharedPtr<X> ret;
	ret.objInfo = sp.objInfo;
	ret.obj = tmp;
	ret.obtain();
	return ret;

}

template <typename X, typename Y>
SharedPtr<X> dynamic_pointer_cast(const SharedPtr<Y> &sp){
	//printf("\tdynamic_pointer_cast(const SharedPtr<Y> &sp)\n");	
	//const auto tmp = 	dynamic_cast<const SharedPtr<T>>(sp);
	SharedPtr<X> ret;	
	auto tmp = dynamic_cast<X*>(sp.get());
	if(tmp) {
		ret.objInfo = sp.objInfo;
		ret.obtain();
	} else{
		ret.objInfo = nullptr;
	}
	ret.obj = tmp;
	
	return ret;

}
