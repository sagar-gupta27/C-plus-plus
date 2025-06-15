//Base class for default allocator as per STL standards

namespace std __attribute__((visibility("default"))){
    typedef long long unsigned int size_type;
    template<typename T>
    class _allocatorBase{
     public:

     //Defining constructors
     _allocatorBase(){

     }

     _allocatorBase(const _allocatorBase&){

     }

     template<typename T1>
     _allocatorBase(const _allocatorBase<T1>&){

     }

     //Destructor
     ~_allocatorBase(){

     }

     //The flow is like first just allocate the memory --> create object at pre-allocated memory --> destroy the object --> free the allocated memory

     T* allocate(size_type n){
       return static_cast<T*>(new [n*sizeof(T)]);
     }

     void deallocate(T* p , size_type n){
        operator delete(p,n);
     }

     void construct(T* ptr, T& val){
          //using placement new syntax: new (address) type(arguments)
          ::new((void*)ptr) T(val);
     }


     void destruct(T* ptr){
        ptr->~T(); // manually destroy the object
     }


     size_type max_size(){
        return std::size_t(-1)/ sizeof(T); // size_t(-1) --> give the largest possible number of size_t
     }


     //Overloaded operators
     template<typename _Arg>
     friend bool operator ==(const _allocatorBase& ,const _allocatorBase<_Arg>&){
        return false;
     }

     template<typename _Arg>
     friend bool operator!=(const _allocatorBase& ,const _allocatorBase<_Arg>&){
        return false;
     }

    };
}