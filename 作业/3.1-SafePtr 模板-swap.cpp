//��ҵ3.1����ȫָ����SafePtr 

#include<iostream>
#include<cstring>

namespace THU{
using std::cout;
using std::endl;
using std::string;

/*
��ȻRL�������Գ���������������ͷŶ�̬������ڴ棬������֪�����
����ڴ�й©�� Ϊ�����ڴ�й©
������Ŀ1.1�е�ComicBook��Ϊ���������һ����ȫָ����SafePtr��
��������һ��ComicBook�����ָ��
�볣��ָ�벻ͬ���ǵ�SafePtr��������ʱ�� Ӧȷ���ͷ�ӵ�е�ComicBook����
*/
template<class T> class SafePtr;
template<class T> void swap(SafePtr<T> & a, SafePtr<T> & b);


template<class T>
class SafePtr{
private:
	T* ptr;
public:
	SafePtr(T *pt){     //���캯������T����pt����SafePtr����
		ptr=pt;
	}
	~SafePtr(){}  
	T * get() const{     //����ӵ�е�T����ָ��
		return ptr; 
	} 
	void reset(T *pt){    //��������ָ����һ��T����pt��Ӧ�ͷ�ԭ�ж���
		this->ptr = NULL;
		this->ptr = pt;	
	}      
    T * revoke(){  //�ͷ�ԭ�ж��������Ȩ��������ָ�룬���������
	    T * pp=this->ptr;
		this->ptr=NULL;
		return pp;
	} 	
	T & operator*() const{  //�����������T��������á�
		T *pppp=this->get();
		return *pppp;
	} 
    T * operator->() const{  //�����������T�����ָ�롣
		T *ppp=this->get();
		return ppp;
	}
	friend  void swap<T>(SafePtr<T> & a, SafePtr<T> & b);  
};

 
//��������SafePtr��ֵ
template<class T>
void swap(SafePtr<T> & a, SafePtr<T> & b){  
	T* temp= a.ptr;
	a.ptr=b.ptr;
	b.ptr= temp;
}



class ComicBook{
protected:	
	string name ;   //�������� 
	int num ;       //���� 
	ComicBook* cb;
public: 
	ComicBook( string name, int num)  {
		this->name = name;
		this->num = num;
		this->cb=NULL;
	}    
     ~ComicBook(){} 
	void set(int num){        //��������
		this->num=num;
		cout<<"��������Ϊ"<<this->num<<endl;          	
	} 
	void setName(string name){
    	this->name =  name;
    	cout<<"��������Ϊ"<<this->name<<endl;
	}          
	int getnum() {
		cout<<"����Ϊ��"<<num<<endl; 
		return num;
	}
	string getName(){
		cout<<"����Ϊ��"<<this->name<<endl; 
		return this->name;
	}
 };
 


}


using namespace THU;

int main(){
	SafePtr<ComicBook> p1 =new ComicBook("����1",111);
	SafePtr<ComicBook> p2 =new ComicBook("����2",222);
	SafePtr<ComicBook> p3 =new ComicBook("����3",333);
	SafePtr<ComicBook> p4 =new ComicBook("����4",444);
	SafePtr<ComicBook> p5 =new ComicBook("����5",555);
	
	cout<<"����get()     p1��";
	p1.get()->getnum();	 
	cout<<"��������*     p1��";
	(*p1).getnum();      
	cout<<"��������->    p1��"; 
	p1->getnum(); 
	cout<<endl;    
	
	cout<<"p2��";
	p2->getnum();
	cout<<"p3��"; 
	p3->getnum(); 
	p2.reset(p3.revoke());	  
	cout<<"ʹ��revoke()��reset()��p3����p2"<<endl;
	cout<<"p2��";
	p2->getnum();           
	cout<<endl; 
	
	cout<<"p4��";
	p4->getnum();
	cout<<"p5��"; 
	p5->getnum(); 
	swap(p4, p5);
	cout<<"ʹ��swap()����p4��p5"<<endl;
	cout<<"p4��";
	p4->getnum();
	cout<<"p5��"; 
	p5->getnum();            
		
	return 0;	  
}







