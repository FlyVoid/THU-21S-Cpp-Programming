#include<iostream>
#include<cstring>
using namespace std;

class ComicBook{
private:	
	string name ;   //�������� 
	int num ;       //���� 
public: 
	 ComicBook(){}
     ComicBook( char* name, int num) ;   //���캯�� 
     ~ComicBook();
     void set(int num);        //�������� 
     void setName(string name); //��������            
	 int get() ;                //��ȡ����
	 string getName() ;         //��ȡ����
 };
 
//���캯�� 
ComicBook::ComicBook( char* name,  int num)  {
	this->name = new char[strlen(name)+1];
	strcpy(this->name,name);
	this->num = num;
}

//��������
ComicBook::~ComicBook(){
	delete [] name;
} 


//��������OKKKKKK
void ComicBook::set(int num){
	this->num=num;
	cout<<"��������Ϊ"<<this->num<<endl;     
}

//��������
void ComicBook::setName(string name){
    this->name = new char[sizeof(name)+1];
	name.copy(this->name,sizeof(name),0); 
	*(this->name + sizeof(name))='\0'; 
    cout<<"��������Ϊ"<<this->name<<endl;
}

//��ȡ����
int ComicBook::get() {
	cout<<"����Ϊ��"<<this->num<<endl; 
	return this->num;
}

//��ȡ����
string ComicBook::getName(){
	cout<<"����Ϊ��"<<this->name<<endl; 
	return this->name;
}

int main(){
	ComicBook comic1;
	comic1.set(99);
	comic1.get(); 
	comic1.setName("��ĳ�����顷"); 
	comic1.getName();
	return 0;
}


