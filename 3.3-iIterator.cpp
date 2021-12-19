//ģ�����µ�����ĳ����ģ��Ϊ��Ԫ����
//����TDM-GCC 4.7.1 64-bit��DEV C++ 5.4.2���ɱ���ɹ�
//Դ�������б����볢�Ի��ñ����� 

# include<iostream>
namespace THU{
using std::cout;
using std::endl;


template<class iterator> void isort(iterator begin, iterator end); 
template<class T> class iVector;
template<class T> class iIterator; 
template<class T> void swap(T* c, T* d);  
 

template<class T>
class iVector {
protected:
	int _size;   //���� 
	int _len;    //��ЧԪ�ظ��� 
	T * _vector;  
public:
	iVector(int n) ;         
	~iVector();
	  
	typedef iIterator<T> iterator; 
	iterator begin();               
	iterator end();              
	void clear();                 
	bool empty() const;          
	void pop_back();
	void push_back(const T& v);     
	T& operator[](int n); 
	friend void isort<iterator>(iterator begin, iterator end);
	friend void swap<T>(T* c, T* d);          
};


//���캯��
template<class T>
iVector<T>::iVector(int n){
	_size = n;
	_len = 0;
	_vector = new T[n];	
}

//�������� 
template<class T>
iVector<T>::~iVector(){
	delete [] _vector; 
} 

//begin:��ʼ����
template<class T> 
typename iVector<T>::iterator iVector<T>::begin(){
	if (_len==0)
		throw _len;
	return _vector; 
}

//end:��������
template<class T>
typename iVector<T>::iterator iVector<T>::end(){
	if (_len==0)
		throw _len;
	return _vector+_len-1;
}



//push_back: ������������һ��
template<class T>
void iVector<T>::push_back(const T& v){
	if (_len==_size)
		throw _len; 
	else{
		_vector[_len]= v;
		_len+=1;
	}
}

//pop_back
template<class T>
void iVector<T>::pop_back(){
	if(_len == 0)
		throw _len; 
	else{
		_vector[_len-1]=NULL;
		_len-=1;	
	}
}




// ����[]�����i��
template<class T>
T & iVector<T>::operator[](int n){
	if (n>=_len || n < 0)
		throw _len;
	return _vector[n];
}

//empty����Ƿ�Ϊ�� 
template<class T>
bool iVector<T>::empty() const{
	if (_len==0)
		return true;
	else{
		return false;
	}
}

//clearɾ��������vector�е�����Ԫ��.
template<class T>
void iVector<T>::clear(){
	for (int i = 0; i<_len;i++ )
		_vector[i]=NULL;
	_len=0;  
}

//���� 
template<class T>
void swap(T* c, T* d){
	T temp= *c;
	*c = *d;
	*d = temp;
}

//ð������ 
template<class iterator> 
void isort(iterator b, iterator e){
	int len=e-b+1;
	for(int i = 0 ;i < len; i++){             //�����ܵ�����
        for(int j = 1 ;j < len-i; j++){       //һ��ð������Ľ��
        	if(  *(b+(j-1)) > *(b+j)  )
				swap(b+(j-1),b+j);
	
        }
    }	
}


/*
ʵ��һ����������iIterator�����������£�
template<class T>
class iIterator {
protected:
T * _iterator;
...
} ��
��Ŀ3.2��typedef T * iterator;�滻��typedef iIterator<T> iterator;��ʹ��
iVector������������
*/ 
template<class T> class iIterator; 
template<class T> T* operator+(const iIterator<T> &ii, const int j);

template<class T>
class iIterator {
protected:
	T * _iterator;
public:
	iIterator(){}
	iIterator(T * iterator){     
		_iterator=iterator; 
	}
	~iIterator(){_iterator=NULL;}
	     
	T & operator*() const{      //����* 
		return *_iterator;
	}
	friend T* operator+<T>(const iIterator<T> &ii, const int j);  
	int operator-(const iIterator &i) const{         //��������ָ����������Ϊ��ָ����Ԫ�ظ��� 
		int len;
    	len= _iterator - i._iterator;
    	return len;  	
	} 
	 
};

template<class T>
T* operator+(const iIterator<T> &ii, const int j){    //����+
		T* iii;
    	iii= ii._iterator + j; 
    	return iii;
}

}

using namespace THU; 

int main() {
	int n = 10; 
    iVector<int> a(n);
	cout<<"��������Ϊ10��vector��ʹ��push_back()��������10-0"<<endl;			
    for (int i = 0; i < n+1; i++) {
        	try{
        		a.push_back(n-i); 
        	}
			catch(int){      //����Ϊ10������11�����֣����������һλ����ʱ�����ʾ������Ϣ 
				cout<<"�����桿�ѳ����������ޣ��޷����Ԫ��"<<n-i<<endl;   
			}            
    }
    
    cout<<"��ǰvectorΪ��"<<endl; 
    for (int i = 0; i < n; i++){
        		cout << a[i] << " ";	
	} 
    cout<<endl;
	cout<<endl;
	 
    cout<<"��������[]��vector[5]:"; 
    try{
    	cout<<a[5]<<endl;
    }
    catch(int){
    	cout<<"�����桿�޷���ȡ��Ԫ��"<<endl;
    }
    
    cout<<"����begin()����һ��Ԫ��Ϊ:"<<*(a.begin())<<endl;    
    cout<<"����end()�����һ��Ԫ��Ϊ:"<<*(a.end())<<endl; 
    isort(a.begin(),a.end());
    cout<<"��ʾisort�������ǰvectorΪ��"<<endl; 
    for (int i = 0; i < n; i++){
        		cout << a[i] << " ";	
	} 
    cout<<endl;
    cout<<endl;
    
    cout<<"ʹ��pop_back()����ɾ����9��8��7��"<<endl;			
    for (int i = 9; i > 6; i--) {
        	try{
        		a.pop_back(); 
        	}
			catch(int){
				cout<<"��������Ԫ�ؿ�ɾ"<<endl;
			}            
    }
    
    cout<<"��ʾpush_back�������ǰvectorΪ��"<<endl; 
    for (int i = 0; i < 7; i++){
        		cout << a[i] << " ";	
	} 
    cout<<endl;
    
     
	
	cout<<"����clear()��ɾ������Ԫ��"<<endl;
	a.clear();
	
	cout<<"����empty(), ��ǰvector�Ƿ�Ϊ�գ�";
	if (a.empty()==true)
		cout<<"��"<<endl;
	else{
		cout<<"��"<<endl;
	}
    

    return 0;
}
