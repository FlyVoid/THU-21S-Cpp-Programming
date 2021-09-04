//作业1：安全指针类SafePtr 

#include<iostream>
#include<cstring>
using namespace std;

class ComicBook{
protected:	
	string name ;   //漫画书名 
	int num ;       //类别号 
	int* p;
public: 
	 ComicBook(){}
     ComicBook( string name, int num) ;    
     ~ComicBook();
     void set(int num);        //设置类别号 
     void setName(string name); //设置书名            
	 int getnum() ;                //获取类别号
	 string getName() ;         //获取书名
 };
 
ComicBook::ComicBook( string name,  int num)  {
	this->name = name;
	this->num = num;
	this->p=NULL;
}

ComicBook::~ComicBook(){
	delete p;
} 

void ComicBook::set(int num){
	this->num=num;
	cout<<"设置类别号为"<<this->num<<endl;     
}

void ComicBook::setName(string name){
    this->name =  name;
    cout<<"设置书名为"<<this->name<<endl;
}

int ComicBook::getnum() {
	cout<<"类别号为："<<num<<endl; 
	return num;
}

string ComicBook::getName(){
	cout<<"书名为："<<this->name<<endl; 
	return this->name;
}



/*
虽然RL算个程序猿，可他经常忘记释放动态申请的内存，众所周知，这会
造成内存泄漏。 为避免内存泄漏
请以题目1.1中的ComicBook类为基础，设计一个安全指针类SafePtr，
用来管理一个ComicBook对象的指针
与常规指针不同的是当SafePtr类析构的时候， 应确保释放拥有的ComicBook对象。
*/
class SafePtr{
private:
	ComicBook* ptr;
public:
	SafePtr(ComicBook *cb);  //构造函数：把ComicBook对象cb交由SafePtr管理
	void reset(ComicBook *cb);
           //重置自身指向另一个ComicBook对象cb。（提示： 应释放原有对象）
    ComicBook * revoke();
         //释放原有对象的所有权，返回其指针，并清空自身。
	ComicBook * get() const;
		 //返回拥有的ComicBook对象指针。
	ComicBook & operator*() const;   //返回所管理的ComicBook对象的引用。
    ComicBook * operator->() const;  //返回所管理的ComicBook对象的指针。
    ~SafePtr(){delete ptr;} 
};

SafePtr::SafePtr(ComicBook *cb){
	ptr=cb;
}

//返回所管理的ComicBook对象的指针。
ComicBook * SafePtr::get() const{	
	return ptr; 
} 

//返回拥有的ComicBook对象指针
void SafePtr::reset(ComicBook *cb){
	ptr = NULL;
	ptr = cb;	
}

//返回所管理的ComicBook对象的指针
ComicBook * SafePtr::revoke(){
	ComicBook * pp=this->ptr;
	this->ptr=NULL;
	return pp;
}



//重载->：返回所管理的ComicBook对象的指针
ComicBook * SafePtr::operator->() const{
	ComicBook *ppp=this->get();
	return ppp;
}


//重载：返回所管理的ComicBook对象的引用。
ComicBook & SafePtr::operator*() const{
	ComicBook *pppp=this->get();
	return *pppp;
	
} 

/* 原来的main函数 
int main(){
	ComicBook *p1 =new ComicBook;
	ComicBook *p2 =new ComicBook;
	delete p1;    //p1.reset
	p1=p2;       //p1.reset 
	p2=NULL;    //revoke释放后，返回一个指针交给reset 	
	p1->getnum();  //get	
	delete p1;	
	return 0;	 
}
*/

int main(){
	SafePtr p1 =new ComicBook("漫画A",111);
	SafePtr p2 =new ComicBook("漫画B",222);
	SafePtr p3 =new ComicBook("漫画C",333);
	
	p3.get()->getnum();	  //测试get() 
	(*p3).getnum();       //测试重载* 
	p3->getnum();         //测试重载->
	
	p1.reset(p2.revoke());	//测试revoke,reset
	p1->getnum();     //交换结果  
	p2->getnum(); 
	
	return 0;	  
}







