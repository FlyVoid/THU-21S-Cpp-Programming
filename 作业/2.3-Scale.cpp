/*��ҵ�� 
��ʵ��һ��������λ����Scale���ɱ�ʾ2~16��λ�ƣ����ַ���
0-9 A-F��ʾ0-15��
*/

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

class Scale{
public:
	Scale(int n);  //���캯��������һ��n����������ʼֵΪ0�� (2<=n<=16)
	void fromDec(long t); //��ʮ������tת����n����������¼ 
    long toDec() const; //����¼��n������ת����ʮ�����������ء�
	void print() const; // ��ӡ�����¼��n��������
	void clear(); //��ռ�¼��n������
    bool operator==(const Scale &s) const;  //�Ƚ�����n�������Ƿ���ȡ�
    bool operator<(const Scale &s) const; //�Ƚ�����n�������Ƿ�����С�ڹ�ϵ��
	bool operator<=(const Scale &s) const; //�Ƚ�����n�������Ƿ�����С�ڵ��ڹ�ϵ��
	Scale operator+(const Scale &s) ; //n�������ӷ�
	Scale & operator=(const Scale &s); //n��������ֵ
	long gett();    //��ȡʮ����t 
	string getnum(); //��ȡn������num
	~Scale();
    
private:
	int n;      //n���� 
	long t;    //ʮ������t
	string num;  //n������num(�ַ���) 
	long *p;	 //ָ����� 
};

Scale::Scale(int n){
	if (n<2 || n>16)
		cout<<"���������ת��2-16���ƣ�"<<endl;
	else{
		this->n=n;
		this->t=0;
		this->num=""; 
	}
}


void Scale::fromDec(long t)	{
	char n_num[n];    //���ַ���0-9 A-F��ʾ0-15��
    if(n<10){
		for(int i=0;i<n;i++)n_num[i]=i+48;
	}
    else{
        for(int i=0;i<n;i++)n_num[i]=i+48;
        for(int j=10;j<n;j++)n_num[j]='A'+j-10;
    }          

    int quotient;int remainder;
	string result="";   //result��������n������  
    
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
    	this->num +=result[i];       //result�������num 
    }
}

//����¼��n������ת����ʮ������������
long Scale::toDec() const{
	long tt=0;
	char n_num[n];    //���ַ���0-9 A-F��ʾ0-15��
    if(n<10){
		for(int i=0;i<n;i++)n_num[i]=i+48;
	}
    else{
        for(int i=0;i<n;i++)n_num[i]=i+48;
        for(int j=10;j<n;j++)n_num[j]='A'+j-10;
    } 
	
	for(int i=0 ; i< num.length();i++){ //ÿһλ��n�����ɴη��ɵ�ʮ������ 
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

// ��ӡ�����¼��n������
void Scale::print() const{
	cout<<this->num<<"��n��������"<<endl;
}

//��ռ�¼��n������
void Scale::clear(){
	this->num="";
	this->t=0;
}


//�Ƚ�����n�������Ƿ���ȡ�
bool Scale::operator==(const Scale &s) const{
    if( this->toDec() == s.toDec()){
        return true;
    }else{
        return false;
    }
}

//�Ƚ�����n�������Ƿ�����С�ڹ�ϵ
bool Scale::operator<(const Scale &s) const{
	if( this->toDec() < s.toDec()){
        return true;
    }else{
        return false;
    }
}

//�Ƚ�����n�������Ƿ�����С�ڵ��ڹ�ϵ
bool Scale::operator<=(const Scale &s) const{
	if( this->toDec() <= s.toDec()){
        return true;
    }else{
        return false;
    }
}


//n�������ӷ�
Scale Scale::operator+(const Scale &s){
	Scale ss(n);
    ss.t= toDec() + s.toDec(); 
    return ss;
} 

//n��������ֵ 
Scale & Scale::operator=(const Scale &s){
	if(this==&s) {
		return *this;  //�����Ը�ֵ 
	} 
	else{
		delete p;        //�ͷ��ڴ� 
		p = new long;     //�����ڴ�
		p = s.p;            //�����ڴ�
		return *this;
	}    	 
}

Scale::~Scale(){
	delete p;
}

//��ȡʮ����t 
long Scale::gett(){
	return this->t; 
}   
//��ȡn������num
string Scale::getnum(){
	return this->num; 
} 	
	
int main(){
	Scale s1(16);
	s1.fromDec(56);
	cout<<"s1=";
	s1.print();
	cout<<"s1="<<s1.toDec()<<"��ʮ��������"<<endl;
	Scale s2(16);
	s2.fromDec(44);
	cout<<"s2=";
	s2.print();
	cout<<"s2="<<s2.toDec()<<"��ʮ��������"<<endl;
	
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
	cout<<"s3=s1="<<s3.toDec() <<"��ʮ��������"<<endl;
	cout<<"s3=s1="<<s3.getnum() <<"��n��������"<<endl; 
	
	Scale s4 = (s1+s2);
	s4.fromDec(s4.gett());
	cout<<"s4= s1+s2="<<s4.gett() <<"��ʮ��������"<<endl;
	cout<<"s4= s1+s2="<<s4.getnum() <<"��n��������"<<endl; 
		
	return 0;
} 



