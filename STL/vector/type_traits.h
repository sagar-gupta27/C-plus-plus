namespace std{

    template<typename T, T val>
    struct varType_constant{
       static constexpr T   value = val;
       typedef T  value_type;
       typedef varType_constant<T, val> type;
       constexpr operator value_type() const noexcept {return value;}
    };

    using true_type = varType_constant<bool, true>;
    using false_type = varType_constant<bool,false>;
}