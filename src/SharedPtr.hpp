#ifndef CS540_SHAREDP_H
#define CS540_SHAREDP_H

#include <iostream>
#include <assert.h>
#include <atomic>
#include <string>
namespace cs540 {
	
	class InfoBase {
	public:
		virtual ~InfoBase() = 0;
		virtual void inc() = 0;
		virtual bool dec() = 0;
		virtual bool isNull() = 0; // dont need
		virtual void deleteData() = 0;
	};

	template<typename D>
	class Info : public InfoBase {
	public:
		//friend class SharedPtr<T>;		
		Info(const D* dPtr);
		~Info();
		void inc();
		bool dec();
		bool isNull();
		void deleteData();
	
	private:
	public:
		std::atomic<unsigned long long> count;
		const D* dPtr;
	// Deleted fns
		Info() = delete;
		Info(const Info&) = delete;		
		Info& operator=(const Info&) = delete;
		

	};


	template <typename T> 
	class SharedPtr {
	public:
		
		
		SharedPtr(); 										
		
		template <typename U> explicit 						
		SharedPtr(U *);

		explicit 						
		SharedPtr(std::nullptr_t);		// just to be safe
		
		SharedPtr(const SharedPtr &p);						
		
		template <typename U> 								
		SharedPtr(const SharedPtr<U> &p);

		
		SharedPtr(SharedPtr &&p);					
		
		template <typename U> 
		SharedPtr(SharedPtr<U> &&p);


		SharedPtr& operator=(const SharedPtr &);

		template <typename U>
		SharedPtr<T>& operator=(const SharedPtr<U> &);
	

		SharedPtr &operator=(SharedPtr &&p);

		template <typename U> 
		SharedPtr &operator=(SharedPtr<U> &&p);

		~SharedPtr();

		void reset();
		
		template <typename U> 
		void reset(U *p);

		T *get() const;

		T &operator*() const;

		T *operator->() const;

		explicit 
		operator bool() const;
/*
		template <typename X, typename Y> friend
		SharedPtr<X> static_pointer_cast(const SharedPtr<Y> &sp){
			SharedPtr<X> ret(static_cast<typename X>(*sp);
			//ret.obj = static_cast<typename X>(*sp);
			//ret.objInfo = sp.objInfo			
			return ret;
		}
*/		
		template <typename X, typename Y>
		friend SharedPtr<X> dynamic_pointer_cast(const SharedPtr<Y> &sp);//{
			//const auto tmp = 	dynamic_cast<const SharedPtr<T>>(sp);
			//auto tmp = dynamic_cast<X>(sp.get());
		//	SharedPtr<X> ret(dynamic_cast<SharedPtr<X&>>(sp));
		//	return ret;

		//}
		template <typename X, typename Y>
		friend SharedPtr<X> static_pointer_cast(const SharedPtr<Y> &sp);


	private:
		void obtain();
		void discard();		


	public: // XXX HUH
		T* obj;		
		InfoBase* objInfo;


	

	};
	
	
	

	#include "Info_Template.hpp"
	#include "SharedPtr_Template.hpp"
	#include "free_functions.hpp"
	
}












































#endif
