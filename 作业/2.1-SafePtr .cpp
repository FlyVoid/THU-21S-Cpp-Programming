//��ҵ1����ȫָ����SafePtr 

#include<iostream>
#include<cstring>
using namespace std;

class ComicBook{
protected:	
	string name ;   //�������� 
	int num ;       //���� 
	int* p;
public: 
	 ComicBook(){}
     ComicBook( string name, int num) ;    
     ~ComicBook();
     void set(int num);        //�������� 
     void setName(string name); //��������            
	 int getnum() ;                //��ȡ����
	 string getName() ;         //��ȡ����
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
	cout<<"��������Ϊ"<<this->num<<endl;     
}

void ComicBook::setName(string name){
    this->name =  name;
    cout<<"��������Ϊ"<<this->name<<endl;
}

int ComicBook::getnum() {
	cout<<"����Ϊ��"<<num<<endl; 
	return num;
}

string ComicBook::getName(){
	cout<<"����Ϊ��"<<this->name<<endl; 
	return this->name;
}



/*
��ȻRL�������Գ���������������ͷŶ�̬������ڴ棬������֪�����
����ڴ�й©�� Ϊ�����ڴ�й©
������Ŀ1.1�е�ComicBook��Ϊ���������һ����ȫָ����SafePtr��
��������һ��ComicBook�����ָ��
�볣��ָ�벻ͬ���ǵ�SafePtr��������ʱ�� Ӧȷ���ͷ�ӵ�е�ComicBook����
*/
class SafePtr{
private:
	ComicBook* ptr;
public:
	SafePtr(ComicBook *cb);  //���캯������ComicBook����cb����SafePtr����
	void reset(ComicBook *cb);
           //��������ָ����һ��ComicBook����cb������ʾ�� Ӧ�ͷ�ԭ�ж���
    ComicBook * revoke();
         //�ͷ�ԭ�ж��������Ȩ��������ָ�룬���������
	ComicBook * get() const;
		 //����ӵ�е�ComicBook����ָ�롣
	ComicBook & operator*() const;   //�����������ComicBook��������á�
    ComicBook * operator->() const;  //�����������ComicBook�����ָ�롣
    ~SafePtr(){delete ptr;} 
};

SafePtr::SafePtr(ComicBook *cb){
	ptr=cb;
}

//�����������ComicBook�����ָ�롣
ComicBook * SafePtr::get() const{	
	return ptr; 
} 

//����ӵ�е�ComicBook����ָ��
void SafePtr::reset(ComicBook *cb){
	ptr = NULL;
	ptr = cb;	
}

//�����������ComicBook�����ָ��
ComicBook * SafePtr::revoke(){
	ComicBook * pp=this->ptr;
	this->ptr=NULL;
	return pp;
}



//����->�������������ComicBook�����ָ��
ComicBook * SafePtr::operator->() const{
	ComicBook *ppp=this->get();
	return ppp;
}


//���أ������������ComicBook��������á�
ComicBook & SafePtr::operator*() const{
	ComicBook *pppp=this->get();
	return *pppp;
	
} 

/* ԭ����main���� 
int main(){
	ComicBook *p1 =new ComicBook;
	ComicBook *p2 =new ComicBook;
	delete p1;    //p1.reset
	p1=p2;       //p1.reset 
	p2=NULL;    //revoke�ͷź󣬷���һ��ָ�뽻��reset 	
	p1->getnum();  //get	
	delete p1;	
	return 0;	 
}
*/

int main(){
	SafePtr p1 =new ComicBook("����A",111);
	SafePtr p2 =new ComicBook("����B",222);
	SafePtr p3 =new ComicBook("����C",333);
	
	p3.get()->getnum();	  //����get() 
	(*p3).getnum();       //��������* 
	p3->getnum();         //��������->
	
	p1.reset(p2.revoke());	//����revoke,reset
	p1->getnum();     //�������  
	p2->getnum(); 
	
	return 0;	  
}







