//模板类下的申明某函数模板为友元函数
//采用TDM-GCC 4.7.1 64-bit（DEV C++ 5.4.2）可编译成功
//源代码如有报错请尝试换用编译器 

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
	int _size;   //容量 
	int _len;    //有效元素个数 
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


//构造函数
template<class T>
iVector<T>::iVector(int n){
	_size = n;
	_len = 0;
	_vector = new T[n];	
}

//析构函数 
template<class T>
iVector<T>::~iVector(){
	delete [] _vector; 
} 

//begin:求开始的项
template<class T> 
typename iVector<T>::iterator iVector<T>::begin(){
	if (_len==0)
		throw _len;
	return _vector; 
}

//end:求最后的项
template<class T>
typename iVector<T>::iterator iVector<T>::end(){
	if (_len==0)
		throw _len;
	return _vector+_len-1;
}



//push_back: 在向量最后插入一项
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




// 重载[]输出第i项
template<class T>
T & iVector<T>::operator[](int n){
	if (n>=_len || n < 0)
		throw _len;
	return _vector[n];
}

//empty检查是否为空 
template<class T>
bool iVector<T>::empty() const{
	if (_len==0)
		return true;
	else{
		return false;
	}
}

//clear删除储存在vector中的所有元素.
template<class T>
void iVector<T>::clear(){
	for (int i = 0; i<_len;i++ )
		_vector[i]=NULL;
	_len=0;  
}

//交换 
template<class T>
void swap(T* c, T* d){
	T temp= *c;
	*c = *d;
	*d = temp;
}

//冒泡排序 
template<class iterator> 
void isort(iterator b, iterator e){
	int len=e-b+1;
	for(int i = 0 ;i < len; i++){             //控制总的趟数
        for(int j = 1 ;j < len-i; j++){       //一次冒泡排序的结果
        	if(  *(b+(j-1)) > *(b+j)  )
				swap(b+(j-1),b+j);
	
        }
    }	
}


/*
实现一个迭代器类iIterator，定义框架如下：
template<class T>
class iIterator {
protected:
T * _iterator;
...
} 将
题目3.2中typedef T * iterator;替换成typedef iIterator<T> iterator;，使得
iVector类正常工作。
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
	     
	T & operator*() const{      //重载* 
		return *_iterator;
	}
	friend T* operator+<T>(const iIterator<T> &ii, const int j);  
	int operator-(const iIterator &i) const{         //重载两个指针相减，结果为两指针间的元素个数 
		int len;
    	len= _iterator - i._iterator;
    	return len;  	
	} 
	 
};

template<class T>
T* operator+(const iIterator<T> &ii, const int j){    //重载+
		T* iii;
    	iii= ii._iterator + j; 
    	return iii;
}

}

using namespace THU; 

int main() {
	int n = 10; 
    iVector<int> a(n);
	cout<<"构造容量为10的vector，使用push_back()依次输入10-0"<<endl;			
    for (int i = 0; i < n+1; i++) {
        	try{
        		a.push_back(n-i); 
        	}
			catch(int){      //容量为10，输入11个数字，在输入最后一位数的时候会提示错误信息 
				cout<<"【警告】已超过容量上限，无法添加元素"<<n-i<<endl;   
			}            
    }
    
    cout<<"当前vector为："<<endl; 
    for (int i = 0; i < n; i++){
        		cout << a[i] << " ";	
	} 
    cout<<endl;
	cout<<endl;
	 
    cout<<"测试重载[]，vector[5]:"; 
    try{
    	cout<<a[5]<<endl;
    }
    catch(int){
    	cout<<"【警告】无法获取该元素"<<endl;
    }
    
    cout<<"测试begin()，第一个元素为:"<<*(a.begin())<<endl;    
    cout<<"测试end()，最后一个元素为:"<<*(a.end())<<endl; 
    isort(a.begin(),a.end());
    cout<<"显示isort结果，当前vector为："<<endl; 
    for (int i = 0; i < n; i++){
        		cout << a[i] << " ";	
	} 
    cout<<endl;
    cout<<endl;
    
    cout<<"使用pop_back()依次删除第9、8、7项"<<endl;			
    for (int i = 9; i > 6; i--) {
        	try{
        		a.pop_back(); 
        	}
			catch(int){
				cout<<"错误！已无元素可删"<<endl;
			}            
    }
    
    cout<<"显示push_back结果，当前vector为："<<endl; 
    for (int i = 0; i < 7; i++){
        		cout << a[i] << " ";	
	} 
    cout<<endl;
    
     
	
	cout<<"测试clear()，删除所有元素"<<endl;
	a.clear();
	
	cout<<"测试empty(), 当前vector是否为空：";
	if (a.empty()==true)
		cout<<"是"<<endl;
	else{
		cout<<"否"<<endl;
	}
    

    return 0;
}
