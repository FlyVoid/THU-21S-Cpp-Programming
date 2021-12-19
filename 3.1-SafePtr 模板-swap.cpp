//作业3.1：安全指针类SafePtr 

#include<iostream>
#include<cstring>

namespace THU{
using std::cout;
using std::endl;
using std::string;

/*
虽然RL算个程序猿，可他经常忘记释放动态申请的内存，众所周知，这会
造成内存泄漏。 为避免内存泄漏
请以题目1.1中的ComicBook类为基础，设计一个安全指针类SafePtr，
用来管理一个ComicBook对象的指针
与常规指针不同的是当SafePtr类析构的时候， 应确保释放拥有的ComicBook对象。
*/
template<class T> class SafePtr;
template<class T> void swap(SafePtr<T> & a, SafePtr<T> & b);


template<class T>
class SafePtr{
private:
	T* ptr;
public:
	SafePtr(T *pt){     //构造函数：把T对象pt交由SafePtr管理
		ptr=pt;
	}
	~SafePtr(){}  
	T * get() const{     //返回拥有的T对象指针
		return ptr; 
	} 
	void reset(T *pt){    //重置自身指向另一个T对象pt；应释放原有对象
		this->ptr = NULL;
		this->ptr = pt;	
	}      
    T * revoke(){  //释放原有对象的所有权，返回其指针，并清空自身。
	    T * pp=this->ptr;
		this->ptr=NULL;
		return pp;
	} 	
	T & operator*() const{  //返回所管理的T对象的引用。
		T *pppp=this->get();
		return *pppp;
	} 
    T * operator->() const{  //返回所管理的T对象的指针。
		T *ppp=this->get();
		return ppp;
	}
	friend  void swap<T>(SafePtr<T> & a, SafePtr<T> & b);  
};

 
//交换两个SafePtr的值
template<class T>
void swap(SafePtr<T> & a, SafePtr<T> & b){  
	T* temp= a.ptr;
	a.ptr=b.ptr;
	b.ptr= temp;
}



class ComicBook{
protected:	
	string name ;   //漫画书名 
	int num ;       //类别号 
	ComicBook* cb;
public: 
	ComicBook( string name, int num)  {
		this->name = name;
		this->num = num;
		this->cb=NULL;
	}    
     ~ComicBook(){} 
	void set(int num){        //设置类别号
		this->num=num;
		cout<<"设置类别号为"<<this->num<<endl;          	
	} 
	void setName(string name){
    	this->name =  name;
    	cout<<"设置书名为"<<this->name<<endl;
	}          
	int getnum() {
		cout<<"类别号为："<<num<<endl; 
		return num;
	}
	string getName(){
		cout<<"书名为："<<this->name<<endl; 
		return this->name;
	}
 };
 


}


using namespace THU;

int main(){
	SafePtr<ComicBook> p1 =new ComicBook("漫画1",111);
	SafePtr<ComicBook> p2 =new ComicBook("漫画2",222);
	SafePtr<ComicBook> p3 =new ComicBook("漫画3",333);
	SafePtr<ComicBook> p4 =new ComicBook("漫画4",444);
	SafePtr<ComicBook> p5 =new ComicBook("漫画5",555);
	
	cout<<"测试get()     p1的";
	p1.get()->getnum();	 
	cout<<"测试重载*     p1的";
	(*p1).getnum();      
	cout<<"测试重载->    p1的"; 
	p1->getnum(); 
	cout<<endl;    
	
	cout<<"p2的";
	p2->getnum();
	cout<<"p3的"; 
	p3->getnum(); 
	p2.reset(p3.revoke());	  
	cout<<"使用revoke()和reset()把p3交给p2"<<endl;
	cout<<"p2的";
	p2->getnum();           
	cout<<endl; 
	
	cout<<"p4的";
	p4->getnum();
	cout<<"p5的"; 
	p5->getnum(); 
	swap(p4, p5);
	cout<<"使用swap()交换p4和p5"<<endl;
	cout<<"p4的";
	p4->getnum();
	cout<<"p5的"; 
	p5->getnum();            
		
	return 0;	  
}







