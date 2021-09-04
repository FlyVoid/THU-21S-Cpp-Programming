//��ҵ1��ComicBook(����) 
//��ҵ2��Bookmanager 
#include<iostream>
#include<cstring>
using namespace std;

class ComicBook; 
class BookManager{
private:	
	string name ;          //���� 
	int num ;              //���� 
	static int total;      //ͳ��������
	static string arrayname[199];    //��������Ա�������� 
	static int arraynum[199];        //��������Ա�������� 
public: 
	 BookManager(){}
     BookManager( string name, int num) ;   //���캯�� 
     ~BookManager(){} 
     
	 int getNum(string name);         //�����������ص�����
	 void add(ComicBook *cb, int n, string names[]);   //�򼯺�A�����һ���顣nΪ��֮��ص������������� names�ַ�������Ϊ��n��������֡� 
	 friend int count(const BookManager & bm);       //ͳ��BookManager��ǰ�����ͼ�飨����A�� ������
	  
     void set(int num);        //�������� 
     void setName(string name); //��������            
	 int get() ;                //��ȡ����
	 string getName() ;         //��ȡ����
 };


class ComicBook{
private:	
	string name ;   //�������� 
	int num ;       //����
	int* p; 
public: 
     ComicBook( string name, int num) ;   //���캯�� 
     ~ComicBook(){} 
     void set(int num);        //�������� 
     void setName(string name); //��������            
	 int get() ;                //��ȡ����
	 string getName() ;         //��ȡ����
	 friend void BookManager::add(ComicBook *cb, int n, string names[]);
 };
 
//���캯�� 
ComicBook::ComicBook( string name, int num)  {
	this->name = name;
	this->num = num;
}

//��������
void ComicBook::set(int num){
	this->num=num;
	cout<<"��������Ϊ"<<this->num<<endl;     
}

//��������
void ComicBook::setName(string name){
    this->name = name; 
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





//BookManager���캯�� 
int BookManager::total = 0;
string BookManager::arrayname[199]=" ";
int BookManager::arraynum[199]={0};
BookManager::BookManager( string name,  int num)  {
	this->name = name;
	this->num = num;
	total++; 
	for(int i=0;i<200;i++){        //���name������arrayname 
		if(arrayname[i]==""){
	        arrayname[i] = name;
	        break;
	    }
	    else {}
    }
	for(int j=0;j<200;j++){          //���num������arraynum 
		if(arraynum[j]==0){
	        arraynum[j] = num;
	        break;
	    }
	    else {}
    }	
}


//ͳ��BookManager��ǰ�����ͼ�� ������
int count(const BookManager & bm){
	return bm.total;	
}


//��ȡ����
int BookManager::get() {
	return this->num;
}

//��ȡ����
string BookManager::getName(){
	return this->name;
}

//�����������ص�����
int BookManager::getNum(string name){
	int k;                            //����arrayname�����ҵ�name��Ӧ�������±� 
	for(int i=0;i<200;i++){            
		if(arrayname[i] == name){
	        k=i;
	        break;
	    }
	    else if(i==199){
	    	cout<<"δ��¼�Ȿ��"<<endl;
	    }
	    else{} 
    } 
	return arraynum[k];	
}         

//���Ŵ�2��ʼ��֮���ÿһ�������Ŷ�Ϊ����A�е���С������ 
//�ر���ǣ���Щ��������ͬ����Ʒ��ͬ����Ʒ���ܺ�A�е�ĳЩ���й�
//��ô�������ż�ΪA����֮��ص�������ŵ���С��������   
//�򼯺�A�����һ���顣nΪ��֮��ص������������� names�ַ�������Ϊ��n��������֡�
void BookManager::add(ComicBook *cb, int n, string names[]) {
	this->name = cb->name;
	           //���names��cbname�ж�Ӧ���±� 
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
		this->num *= ComicBook::cbnum[namenum[k]];   //num=��������ŵĳ˻��� 
	} 
		
} 

//��������
void BookManager::set(int num){
	this->num=num;
	cout<<"��������Ϊ"<<this->num<<endl;     
}

//��������
void BookManager::setName(string name){
    this->name = name;
    cout<<"��������Ϊ"<<this->name<<endl;
}


int main(){
	ComicBook comic1;
	comic1.set(99);
	comic1.get(); 
	comic1.setName("��ĳ�����顷"); 
	comic1.getName();
	return 0;
}






