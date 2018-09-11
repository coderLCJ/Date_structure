#include< iostream >  
using namespace std;  
const int maxsize=1000;  
template < class T >  
class Seqlist{  
public:  
      Seqlist():length(0) {}  
      Seqlist(const T a[],int n);  
      int Getlength();  
      void Printlist();  
      void Insert(int i,T x);  
      T Delete(int i);  
      T Get(int i);  
      int Locate(T x);  
private:  
      T date[maxsize];  
      int length;  

};  
template < class T >  
Seqlist< T >::Seqlist(const T a[],int n){  
      if(n>maxsize)  
         throw "error";   
      for(int i=0;i<n;i++){    
          date[i]=a[i];   
      }   
      length=n;    
}    
template < class T >    
int Seqlist< T >::Getlength(){    
      return length;    
}   
template < class T >   
void Seqlist< T >::Printlist(){   
      cout<<"遍历线性表的各个数据元素"<<endl;   
      for(int i=0;i<length;i++){   
          cout<<date[i]<<' ';   
      }   
      cout<<endl;   
}   
template < class T >   
void Seqlist< T >::Insert(int i,T x){   
      if(length>maxsize||i<1||i>length+1)   
         throw "error";   
      for(int j=length;j>=i;j--){   
          date[j]=date[j-1];   
      }   
      date[i-1]=x;   
      length++;   
}   
template < class T >   
T Seqlist< T >::Delete(int i){   
      if(length==0||i<1||i>length)   
         throw "error";   
      T x=date[i-1];   
      for(int j=i;j<length;j++){   
         date[j-1]=date[j];   
      }   
      length--;   
      return x;   
}   
template < class T >   
T Seqlist< T >::Get(int i){   
      if(i<1||i>length)   
         throw "error";   
      return date[i-1];   
}   
template < class T >   
int Seqlist< T >::Locate(T x){   
      for(int i=0;i<length;i++){   
          if(date[i]==x)   
             return i+1;   
      }   
      return 0;   
}   
int main(){   
      int a[1000],n;   
      cout<<"输入元素个数(<1000)"<<endl;   
      cin>>n;   
      cout<<"输入元素"<<endl;   
      for(int i=0;i<n;i++)   
          cin>>a[i];   
      Seqlist < int > list1(a,n);   
      list1.Printlist();   
      cout<<"向位置2插入元素0后";   
      list1.Insert(2,0);   
      list1.Printlist();      
      int x=list1.Delete(4);   
      cout<<"删除元素："<<x<<endl;   
      list1.Printlist();
      int p=list1.Locate(4);   
      cout<<"元素4的位置："<<p<<endl;   
}   
