/*作业三 
请实现一个常数进位制类Scale，可表示2~16进位制，用字符集
0-9 A-F表示0-15。
*/

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

class Scale{
public:
	Scale(int n);  //构造函数：创建一个n进制数，初始值为0。 (2<=n<=16)
	void fromDec(long t); //将十进制数t转换成n进制数并记录 
    long toDec() const; //将记录的n进制数转换成十进制数并返回。
	void print() const; // 打印输出记录的n进制数。
	void clear(); //清空记录的n进制数
    bool operator==(const Scale &s) const;  //比较两个n进制数是否相等。
    bool operator<(const Scale &s) const; //比较两个n进制数是否满足小于关系。
	bool operator<=(const Scale &s) const; //比较两个n进制数是否满足小于等于关系。
	Scale operator+(const Scale &s) ; //n进制数加法
	Scale & operator=(const Scale &s); //n进制数赋值
	long gett();    //获取十制数t 
	string getnum(); //获取n进制数num
	~Scale();
    
private:
	int n;      //n进制 
	long t;    //十进制数t
	string num;  //n进制数num(字符串) 
	long *p;	 //指针变量 
};

Scale::Scale(int n){
	if (n<2 || n>16)
		cout<<"本程序仅能转换2-16进制！"<<endl;
	else{
		this->n=n;
		this->t=0;
		this->num=""; 
	}
}


void Scale::fromDec(long t)	{
	char n_num[n];    //用字符集0-9 A-F表示0-15。
    if(n<10){
		for(int i=0;i<n;i++)n_num[i]=i+48;
	}
    else{
        for(int i=0;i<n;i++)n_num[i]=i+48;
        for(int j=10;j<n;j++)n_num[j]='A'+j-10;
    }          

    int quotient;int remainder;
	string result="";   //result存放逆序的n进制数  
    
	if(t>=n){
		while(t>=n){
        quotient = t / n;
        remainder = t % n;
        result += n_num[remainder];
        t = quotient;
    	}
    	result += n_num[quotient];
	}
	else{
		result += n_num[t];
	}

    for(int i=result.length()-1;i>=0;i--){
    	this->num +=result[i];       //result逆序存入num 
    }
}

//将记录的n进制数转换成十进制数并返回
long Scale::toDec() const{
	long tt=0;
	char n_num[n];    //用字符集0-9 A-F表示0-15。
    if(n<10){
		for(int i=0;i<n;i++)n_num[i]=i+48;
	}
    else{
        for(int i=0;i<n;i++)n_num[i]=i+48;
        for(int j=10;j<n;j++)n_num[j]='A'+j-10;
    } 
	
	for(int i=0 ; i< num.length();i++){ //每一位乘n的若干次方可得十进制数 
		for(int j=0; j<n;j++){
			if(num[i]==n_num[j]){		
				tt+= j * pow(n,num.length()-1-i); 
			}
			else{
			}
		}	
	} 
	return tt; 
}

// 打印输出记录的n进制数
void Scale::print() const{
	cout<<this->num<<"（n进制数）"<<endl;
}

//清空记录的n进制数
void Scale::clear(){
	this->num="";
	this->t=0;
}


//比较两个n进制数是否相等。
bool Scale::operator==(const Scale &s) const{
    if( this->toDec() == s.toDec()){
        return true;
    }else{
        return false;
    }
}

//比较两个n进制数是否满足小于关系
bool Scale::operator<(const Scale &s) const{
	if( this->toDec() < s.toDec()){
        return true;
    }else{
        return false;
    }
}

//比较两个n进制数是否满足小于等于关系
bool Scale::operator<=(const Scale &s) const{
	if( this->toDec() <= s.toDec()){
        return true;
    }else{
        return false;
    }
}


//n进制数加法
Scale Scale::operator+(const Scale &s){
	Scale ss(n);
    ss.t= toDec() + s.toDec(); 
    return ss;
} 

//n进制数赋值 
Scale & Scale::operator=(const Scale &s){
	if(this==&s) {
		return *this;  //避免自赋值 
	} 
	else{
		delete p;        //释放内存 
		p = new long;     //申请内存
		p = s.p;            //拷贝内存
		return *this;
	}    	 
}

Scale::~Scale(){
	delete p;
}

//获取十制数t 
long Scale::gett(){
	return this->t; 
}   
//获取n进制数num
string Scale::getnum(){
	return this->num; 
} 	
	
int main(){
	Scale s1(16);
	s1.fromDec(56);
	cout<<"s1=";
	s1.print();
	cout<<"s1="<<s1.toDec()<<"（十进制数）"<<endl;
	Scale s2(16);
	s2.fromDec(44);
	cout<<"s2=";
	s2.print();
	cout<<"s2="<<s2.toDec()<<"（十进制数）"<<endl;
	
	if(s1 == s2)
        cout<<"s1 == s2"<<endl;
    
    if(s1 < s2)
        cout<<"s1 < s2"<<endl;
    else
    	cout<<"s1 >= s2"<<endl;
    
	if(s1 <= s2)
        cout<<"s1 <= s2"<<endl;
    else
    	cout<<"s1 > s2"<<endl;
    
    
    Scale s3= s1;
	cout<<"s3=s1="<<s3.toDec() <<"（十进制数）"<<endl;
	cout<<"s3=s1="<<s3.getnum() <<"（n进制数）"<<endl; 
	
	Scale s4 = (s1+s2);
	s4.fromDec(s4.gett());
	cout<<"s4= s1+s2="<<s4.gett() <<"（十进制数）"<<endl;
	cout<<"s4= s1+s2="<<s4.getnum() <<"（n进制数）"<<endl; 
		
	return 0;
} 



