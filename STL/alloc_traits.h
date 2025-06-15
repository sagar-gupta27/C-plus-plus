#include "allocatorBase.h"
#include "idioms.h"

namespace std{
    template<typename _Alloc>
    struct alloc_traits{
         typedef _Alloc allocator_type;
         typedef typename _Alloc::value_type value_type;
         using pointer = __detected_or_t<value_type*,__pointer,_Alloc>; 
        //Constructor
        alloc_traits(){
       
        }


        //Trait Related Members
        using progagate_on_container_copy_assign = __detected_or_t<false_type,__pocca,_Alloc>
        using progagate_on_container_move_assign = __detected_or_t<false_type,__pocma,_Alloc>
        using progagate_on_container_swap= __detected_or_t<false_type,__pocs,_Alloc>;
        is_always_equal

    };
}