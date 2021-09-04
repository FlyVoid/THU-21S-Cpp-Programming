//作业1：ComicBook(后面) 
//作业2：Bookmanager 
#include<iostream>
#include<cstring>
using namespace std;

class ComicBook; 
class BookManager{
private:	
	string name ;          //书名 
	int num ;              //类别号 
	static int total;      //统计书总数
	static string arrayname[199];    //储存对象以便后续查找 
	static int arraynum[199];        //储存对象以便后续查找 
public: 
	 BookManager(){}
     BookManager( string name, int num) ;   //构造函数 
     ~BookManager(){} 
     
	 int getNum(string name);         //根据书名返回的类别号
	 void add(ComicBook *cb, int n, string names[]);   //向集合A中添加一本书。n为与之相关的漫画书数量， names字符串数组为这n本书的名字。 
	 friend int count(const BookManager & bm);       //统计BookManager当前管理的图书（集合A） 的数量
	  
     void set(int num);        //设置类别号 
     void setName(string name); //设置书名            
	 int get() ;                //获取类别号
	 string getName() ;         //获取书名
 };


class ComicBook{
private:	
	string name ;   //漫画书名 
	int num ;       //类别号
	int* p; 
public: 
     ComicBook( string name, int num) ;   //构造函数 
     ~ComicBook(){} 
     void set(int num);        //设置类别号 
     void setName(string name); //设置书名            
	 int get() ;                //获取类别号
	 string getName() ;         //获取书名
	 friend void BookManager::add(ComicBook *cb, int n, string names[]);
 };
 
//构造函数 
ComicBook::ComicBook( string name, int num)  {
	this->name = name;
	this->num = num;
}

//设置类别号
void ComicBook::set(int num){
	this->num=num;
	cout<<"设置类别号为"<<this->num<<endl;     
}

//设置书名
void ComicBook::setName(string name){
    this->name = name; 
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





//BookManager构造函数 
int BookManager::total = 0;
string BookManager::arrayname[199]=" ";
int BookManager::arraynum[199]={0};
BookManager::BookManager( string name,  int num)  {
	this->name = name;
	this->num = num;
	total++; 
	for(int i=0;i<200;i++){        //存放name到数组arrayname 
		if(arrayname[i]==""){
	        arrayname[i] = name;
	        break;
	    }
	    else {}
    }
	for(int j=0;j<200;j++){          //存放num到数组arraynum 
		if(arraynum[j]==0){
	        arraynum[j] = num;
	        break;
	    }
	    else {}
    }	
}


//统计BookManager当前管理的图书 的数量
int count(const BookManager & bm){
	return bm.total;	
}


//获取类别号
int BookManager::get() {
	return this->num;
}

//获取书名
string BookManager::getName(){
	return this->name;
}

//根据书名返回的类别号
int BookManager::getNum(string name){
	int k;                            //遍历arrayname数组找到name对应的数组下标 
	for(int i=0;i<200;i++){            
		if(arrayname[i] == name){
	        k=i;
	        break;
	    }
	    else if(i==199){
	    	cout<<"未收录这本书"<<endl;
	    }
	    else{} 
    } 
	return arraynum[k];	
}         

//类别号从2开始，之后的每一本的类别号都为不在A中的最小素数。 
//特别的是，有些漫画书是同人作品，同人作品可能和A中的某些书有关
//那么它的类别号即为A中与之相关的书的类别号的最小公倍数。   
//向集合A中添加一本书。n为与之相关的漫画书数量， names字符串数组为这n本书的名字。
void BookManager::add(ComicBook *cb, int n, string names[]) {
	this->name = cb->name;
	           //存放names在cbname中对应的下标 
	int namenum[]={0}; 	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if (names[i]== ComicBook::cbname[j]){
				for(int t=0;t<n;t++){
					if(namenum[t]==0){
						namenum[t]=j;
					}
					else{}
				}
			} 
			else {} 
		}
		
	} 
			          	
	for(int k=0;k<n;k++){
		this->num *= ComicBook::cbnum[namenum[k]];   //num=相关书类别号的乘积和 
	} 
		
} 

//设置类别号
void BookManager::set(int num){
	this->num=num;
	cout<<"设置类别号为"<<this->num<<endl;     
}

//设置书名
void BookManager::setName(string name){
    this->name = name;
    cout<<"设置书名为"<<this->name<<endl;
}


int main(){
	ComicBook comic1;
	comic1.set(99);
	comic1.get(); 
	comic1.setName("《某漫画书》"); 
	comic1.getName();
	return 0;
}






