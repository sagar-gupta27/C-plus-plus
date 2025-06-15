// Implementing vector class
namespace std{
   template<typename T>
   class allocator: public allocator_base<T>{

   };

template <typename T, typename Alloc = allocator<T>>
class vector
{
   // private memebers
   T *arr; // Main storage

   int size;
   int cap;
   int pos = 0;

public:
   // defining constructors

   // default constructor
   vector()
   {
      this->size = 0;
      this->cap = 0;
   }

   vector(size_type n)
   {
      this->size = n;
      this->cap = 2 * size;
      arr = new T[cap];
   }

   vector(size_type n, T &value)
   {
      this->size = n;
      this->cap = 2 * size;
      arr = new T[cap];

      for (int i = 0; i < size; i++)
      {
         arr[i] = value;
      }
   }

   vector(const vector &other)
   {
      this->size = other.size();
      this->cap = 2 * size;
      arr = new T[cap];

      for (int i = 0; i < size; i++)
      {
         arr[i] = other[i];
      }
   }

   vector(vector &&other)
   {
      this->size = other.size();
      this->cap = 2 * size;
      arr = new T[cap];

      for (int i = 0; i < size; i++)
      {
         arr[i] = other[i];
      }
   }

   vector(initialize_list<T> list)
   {
      // TODO::
   }

   // Destructor
   ~vector()
   {
      delete[] arr;
   }

   // Element Access
   T &at(size_type index)
   {
      if (index >= 0 && index < size)
         return arr[index];
   }

   T &operator[](size_type index)
   {
      return arr[index];
   }

   const T& operator[](size_type index)
   {
      return arr[index];
   }

   T &front()
   {
      return arr[0];
   }

   T &back()
   {
      return arr[pos - 1];
   }
   
   T* data(){
      return arr;
   }

   //Storage Related Functions
   size_type size()
   {
      return this->size;
   }

   size_type capacity()
   {
      return cap;
   }

   bool empty()
   {
      return size == 0;
   }
   
   size_type max_size(){
    
   }

   void reserve(size_type n){

   }

   // insertion function
   void push_back(const T &ele)
   {
      if (size == 0)
      {
         size = cap = 1;
         arr[size++] = ele;
         return;
      }

      // incase array is full create a double size array and copy all the elements
      if (size == cap)
      {
         cap = 2 * cap;
         T *temp = new T[cap];

         for (int i = 0; i < size; i++)
         {
            temp[i] = arr[i];
         }

         // insert new element
         temp[size++] = ele;

         delete[] arr;
         arr = temp;
         delete[] temp;
      }
      else
      {
         arr[size++] = ele;
      }
   }

   void push_back(T &&ele)
   {
      if (size == 0)
      {
         size = cap = 1;
         arr[size++] = ele;
         return;
      }

      // incase array is full create a double size array and copy all the elements
      if (size == cap)
      {
         cap = 2 * cap;
         T *temp = new T[cap];

         for (int i = 0; i < size; i++)
         {
            temp[i] = arr[i];
         }

         // insert new element
         temp[size++] = ele;

         delete[] arr;
         arr = temp;
         delete[] temp;
      }
      else
      {
         arr[size++] = ele;
      }
   }

   void pop_back()
   {
      if (size > 0)
      {
         size--;
      }

      return;
   }

   
};
}