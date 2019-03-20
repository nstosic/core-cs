#if BUILD_ON_TRAVIS == 1
    #define ASSEMBLY_RETURN_TYPE(t) extern "C" t
    #define ASSEMBLY_DECLARATION(t, x) ASSEMBLY_RETURN_TYPE(t) _##x
    #define ASSEMBLY_CALL(x) _##x
#else
    #define ASSEMBLY_DECLARATION(t, x) extern "C" t x
    #define ASSEMBLY_CALL(x) x
#endif