#include<iostream>
#include<cstring>
using namespace std;

class ComicBook{
private:	
	string name ;   //漫画书名 
	int num ;       //类别号 
public: 
	 ComicBook(){}
     ComicBook( char* name, int num) ;   //构造函数 
     ~ComicBook();
     void set(int num);        //设置类别号 
     void setName(string name); //设置书名            
	 int get() ;                //获取类别号
	 string getName() ;         //获取书名
 };
 
//构造函数 
ComicBook::ComicBook( char* name,  int num)  {
	this->name = new char[strlen(name)+1];
	strcpy(this->name,name);
	this->num = num;
}

//析构函数
ComicBook::~ComicBook(){
	delete [] name;
} 


//设置类别号OKKKKKK
void ComicBook::set(int num){
	this->num=num;
	cout<<"设置类别号为"<<this->num<<endl;     
}

//设置书名
void ComicBook::setName(string name){
    this->name = new char[sizeof(name)+1];
	name.copy(this->name,sizeof(name),0); 
	*(this->name + sizeof(name))='\0'; 
    cout<<"设置书名为"<<this->name<<endl;
}

//获取类别号
int ComicBook::get() {
	cout<<"类别号为："<<this->num<<endl; 
	return this->num;
}

//获取书名
string ComicBook::getName(){
	cout<<"书名为："<<this->name<<endl; 
	return this->name;
}

int main(){
	ComicBook comic1;
	comic1.set(99);
	comic1.get(); 
	comic1.setName("《某漫画书》"); 
	comic1.getName();
	return 0;
}


