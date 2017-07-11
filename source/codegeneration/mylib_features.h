
// This is a generated file. Do not edit! [ADAPT]

#ifndef MYLIB_COMPILER_DETECTION_H
#define MYLIB_COMPILER_DETECTION_H

#ifdef __cplusplus
# define MYLIB_COMPILER_IS_Comeau 0
# define MYLIB_COMPILER_IS_Intel 0
# define MYLIB_COMPILER_IS_PathScale 0
# define MYLIB_COMPILER_IS_Embarcadero 0
# define MYLIB_COMPILER_IS_Borland 0
# define MYLIB_COMPILER_IS_Watcom 0
# define MYLIB_COMPILER_IS_OpenWatcom 0
# define MYLIB_COMPILER_IS_SunPro 0
# define MYLIB_COMPILER_IS_HP 0
# define MYLIB_COMPILER_IS_Compaq 0
# define MYLIB_COMPILER_IS_zOS 0
# define MYLIB_COMPILER_IS_XL 0
# define MYLIB_COMPILER_IS_VisualAge 0
# define MYLIB_COMPILER_IS_PGI 0
# define MYLIB_COMPILER_IS_Cray 0
# define MYLIB_COMPILER_IS_TI 0
# define MYLIB_COMPILER_IS_Fujitsu 0
# define MYLIB_COMPILER_IS_SCO 0
# define MYLIB_COMPILER_IS_AppleClang 0
# define MYLIB_COMPILER_IS_Clang 0
# define MYLIB_COMPILER_IS_GNU 0
# define MYLIB_COMPILER_IS_MSVC 0
# define MYLIB_COMPILER_IS_ADSP 0
# define MYLIB_COMPILER_IS_IAR 0
# define MYLIB_COMPILER_IS_MIPSpro 0

#if defined(__COMO__)
# undef MYLIB_COMPILER_IS_Comeau
# define MYLIB_COMPILER_IS_Comeau 1

#elif defined(__INTEL_COMPILER) || defined(__ICC)
# undef MYLIB_COMPILER_IS_Intel
# define MYLIB_COMPILER_IS_Intel 1

#elif defined(__PATHCC__)
# undef MYLIB_COMPILER_IS_PathScale
# define MYLIB_COMPILER_IS_PathScale 1

#elif defined(__BORLANDC__) && defined(__CODEGEARC_VERSION__)
# undef MYLIB_COMPILER_IS_Embarcadero
# define MYLIB_COMPILER_IS_Embarcadero 1

#elif defined(__BORLANDC__)
# undef MYLIB_COMPILER_IS_Borland
# define MYLIB_COMPILER_IS_Borland 1

#elif defined(__WATCOMC__) && __WATCOMC__ < 1200
# undef MYLIB_COMPILER_IS_Watcom
# define MYLIB_COMPILER_IS_Watcom 1

#elif defined(__WATCOMC__)
# undef MYLIB_COMPILER_IS_OpenWatcom
# define MYLIB_COMPILER_IS_OpenWatcom 1

#elif defined(__SUNPRO_CC)
# undef MYLIB_COMPILER_IS_SunPro
# define MYLIB_COMPILER_IS_SunPro 1

#elif defined(__HP_aCC)
# undef MYLIB_COMPILER_IS_HP
# define MYLIB_COMPILER_IS_HP 1

#elif defined(__DECCXX)
# undef MYLIB_COMPILER_IS_Compaq
# define MYLIB_COMPILER_IS_Compaq 1

#elif defined(__IBMCPP__) && defined(__COMPILER_VER__)
# undef MYLIB_COMPILER_IS_zOS
# define MYLIB_COMPILER_IS_zOS 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ >= 800
# undef MYLIB_COMPILER_IS_XL
# define MYLIB_COMPILER_IS_XL 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ < 800
# undef MYLIB_COMPILER_IS_VisualAge
# define MYLIB_COMPILER_IS_VisualAge 1

#elif defined(__PGI)
# undef MYLIB_COMPILER_IS_PGI
# define MYLIB_COMPILER_IS_PGI 1

#elif defined(_CRAYC)
# undef MYLIB_COMPILER_IS_Cray
# define MYLIB_COMPILER_IS_Cray 1

#elif defined(__TI_COMPILER_VERSION__)
# undef MYLIB_COMPILER_IS_TI
# define MYLIB_COMPILER_IS_TI 1

#elif defined(__FUJITSU) || defined(__FCC_VERSION) || defined(__fcc_version)
# undef MYLIB_COMPILER_IS_Fujitsu
# define MYLIB_COMPILER_IS_Fujitsu 1

#elif defined(__SCO_VERSION__)
# undef MYLIB_COMPILER_IS_SCO
# define MYLIB_COMPILER_IS_SCO 1

#elif defined(__clang__) && defined(__apple_build_version__)
# undef MYLIB_COMPILER_IS_AppleClang
# define MYLIB_COMPILER_IS_AppleClang 1

#elif defined(__clang__)
# undef MYLIB_COMPILER_IS_Clang
# define MYLIB_COMPILER_IS_Clang 1

#elif defined(__GNUC__)
# undef MYLIB_COMPILER_IS_GNU
# define MYLIB_COMPILER_IS_GNU 1

#elif defined(_MSC_VER)
# undef MYLIB_COMPILER_IS_MSVC
# define MYLIB_COMPILER_IS_MSVC 1

#elif defined(__VISUALDSPVERSION__) || defined(__ADSPBLACKFIN__) || defined(__ADSPTS__) || defined(__ADSP21000__)
# undef MYLIB_COMPILER_IS_ADSP
# define MYLIB_COMPILER_IS_ADSP 1

#elif defined(__IAR_SYSTEMS_ICC__ ) || defined(__IAR_SYSTEMS_ICC)
# undef MYLIB_COMPILER_IS_IAR
# define MYLIB_COMPILER_IS_IAR 1

#elif defined(_SGI_COMPILER_VERSION) || defined(_COMPILER_VERSION)
# undef MYLIB_COMPILER_IS_MIPSpro
# define MYLIB_COMPILER_IS_MIPSpro 1


#endif

#  if MYLIB_COMPILER_IS_AppleClang

#    if !(((__clang_major__ * 100) + __clang_minor__) >= 400)
#      error Unsupported compiler version
#    endif

# define MYLIB_COMPILER_VERSION_MAJOR (__clang_major__)
# define MYLIB_COMPILER_VERSION_MINOR (__clang_minor__)
# define MYLIB_COMPILER_VERSION_PATCH (__clang_patchlevel__)
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define MYLIB_SIMULATE_VERSION_MAJOR (_MSC_VER / 100)
#  define MYLIB_SIMULATE_VERSION_MINOR (_MSC_VER % 100)
# endif
# define MYLIB_COMPILER_VERSION_TWEAK (__apple_build_version__)

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_alignas)
#      define MYLIB_COMPILER_CXX_ALIGNAS 1
#    else
#      define MYLIB_COMPILER_CXX_ALIGNAS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_alignas)
#      define MYLIB_COMPILER_CXX_ALIGNOF 1
#    else
#      define MYLIB_COMPILER_CXX_ALIGNOF 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_constexpr)
#      define MYLIB_COMPILER_CXX_CONSTEXPR 1
#    else
#      define MYLIB_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_override_control)
#      define MYLIB_COMPILER_CXX_FINAL 1
#    else
#      define MYLIB_COMPILER_CXX_FINAL 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_noexcept)
#      define MYLIB_COMPILER_CXX_NOEXCEPT 1
#    else
#      define MYLIB_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_nullptr)
#      define MYLIB_COMPILER_CXX_NULLPTR 1
#    else
#      define MYLIB_COMPILER_CXX_NULLPTR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __cplusplus >= 201103L
#      define MYLIB_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define MYLIB_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_thread_local)
#      define MYLIB_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define MYLIB_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#  elif MYLIB_COMPILER_IS_Clang

#    if !(((__clang_major__ * 100) + __clang_minor__) >= 304)
#      error Unsupported compiler version
#    endif

# define MYLIB_COMPILER_VERSION_MAJOR (__clang_major__)
# define MYLIB_COMPILER_VERSION_MINOR (__clang_minor__)
# define MYLIB_COMPILER_VERSION_PATCH (__clang_patchlevel__)
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define MYLIB_SIMULATE_VERSION_MAJOR (_MSC_VER / 100)
#  define MYLIB_SIMULATE_VERSION_MINOR (_MSC_VER % 100)
# endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __has_feature(cxx_alignas)
#      define MYLIB_COMPILER_CXX_ALIGNAS 1
#    else
#      define MYLIB_COMPILER_CXX_ALIGNAS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __has_feature(cxx_alignas)
#      define MYLIB_COMPILER_CXX_ALIGNOF 1
#    else
#      define MYLIB_COMPILER_CXX_ALIGNOF 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __has_feature(cxx_constexpr)
#      define MYLIB_COMPILER_CXX_CONSTEXPR 1
#    else
#      define MYLIB_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __has_feature(cxx_override_control)
#      define MYLIB_COMPILER_CXX_FINAL 1
#    else
#      define MYLIB_COMPILER_CXX_FINAL 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __has_feature(cxx_noexcept)
#      define MYLIB_COMPILER_CXX_NOEXCEPT 1
#    else
#      define MYLIB_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __has_feature(cxx_nullptr)
#      define MYLIB_COMPILER_CXX_NULLPTR 1
#    else
#      define MYLIB_COMPILER_CXX_NULLPTR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __cplusplus >= 201103L
#      define MYLIB_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define MYLIB_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __has_feature(cxx_thread_local)
#      define MYLIB_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define MYLIB_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#  elif MYLIB_COMPILER_IS_GNU

#    if !((__GNUC__ * 100 + __GNUC_MINOR__) >= 404)
#      error Unsupported compiler version
#    endif

# define MYLIB_COMPILER_VERSION_MAJOR (__GNUC__)
# define MYLIB_COMPILER_VERSION_MINOR (__GNUC_MINOR__)
# if defined(__GNUC_PATCHLEVEL__)
#  define MYLIB_COMPILER_VERSION_PATCH (__GNUC_PATCHLEVEL__)
# endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define MYLIB_COMPILER_CXX_ALIGNAS 1
#    else
#      define MYLIB_COMPILER_CXX_ALIGNAS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define MYLIB_COMPILER_CXX_ALIGNOF 1
#    else
#      define MYLIB_COMPILER_CXX_ALIGNOF 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define MYLIB_COMPILER_CXX_CONSTEXPR 1
#    else
#      define MYLIB_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 407 && __cplusplus >= 201103L
#      define MYLIB_COMPILER_CXX_FINAL 1
#    else
#      define MYLIB_COMPILER_CXX_FINAL 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define MYLIB_COMPILER_CXX_NOEXCEPT 1
#    else
#      define MYLIB_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define MYLIB_COMPILER_CXX_NULLPTR 1
#    else
#      define MYLIB_COMPILER_CXX_NULLPTR 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define MYLIB_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define MYLIB_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define MYLIB_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define MYLIB_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#  elif MYLIB_COMPILER_IS_MSVC

#    if !(_MSC_VER >= 1600)
#      error Unsupported compiler version
#    endif

  /* _MSC_VER = VVRR */
# define MYLIB_COMPILER_VERSION_MAJOR (_MSC_VER / 100)
# define MYLIB_COMPILER_VERSION_MINOR (_MSC_VER % 100)
# if defined(_MSC_FULL_VER)
#  if _MSC_VER >= 1400
    /* _MSC_FULL_VER = VVRRPPPPP */
#   define MYLIB_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 100000)
#  else
    /* _MSC_FULL_VER = VVRRPPPP */
#   define MYLIB_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 10000)
#  endif
# endif
# if defined(_MSC_BUILD)
#  define MYLIB_COMPILER_VERSION_TWEAK (_MSC_BUILD)
# endif

#    if _MSC_VER >= 1900
#      define MYLIB_COMPILER_CXX_ALIGNAS 1
#    else
#      define MYLIB_COMPILER_CXX_ALIGNAS 0
#    endif

#    if _MSC_VER >= 1900
#      define MYLIB_COMPILER_CXX_ALIGNOF 1
#    else
#      define MYLIB_COMPILER_CXX_ALIGNOF 0
#    endif

#    define MYLIB_COMPILER_CXX_CONSTEXPR 0

#    if _MSC_VER >= 1700
#      define MYLIB_COMPILER_CXX_FINAL 1
#    else
#      define MYLIB_COMPILER_CXX_FINAL 0
#    endif

#    if _MSC_VER >= 1900
#      define MYLIB_COMPILER_CXX_NOEXCEPT 1
#    else
#      define MYLIB_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if _MSC_VER >= 1600
#      define MYLIB_COMPILER_CXX_NULLPTR 1
#    else
#      define MYLIB_COMPILER_CXX_NULLPTR 0
#    endif

#    if _MSC_VER >= 1900
#      define MYLIB_COMPILER_CXX_SIZEOF_MEMBER 1
#    else
#      define MYLIB_COMPILER_CXX_SIZEOF_MEMBER 0
#    endif

#    if _MSC_VER >= 1900
#      define MYLIB_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define MYLIB_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#  else
#    error Unsupported compiler
#  endif

#  if MYLIB_COMPILER_CXX_ALIGNAS
#    define MYLIB_ALIGNAS(X) alignas(X)
#  elif MYLIB_COMPILER_IS_GNU || MYLIB_COMPILER_IS_Clang || MYLIB_COMPILER_IS_AppleClang
#    define MYLIB_ALIGNAS(X) __attribute__ ((__aligned__(X)))
#  elif MYLIB_COMPILER_IS_MSVC
#    define MYLIB_ALIGNAS(X) __declspec(align(X))
#  else
#    define MYLIB_ALIGNAS(X)
#  endif


#  if MYLIB_COMPILER_CXX_ALIGNOF
#    define MYLIB_ALIGNOF(X) alignof(X)
#  elif MYLIB_COMPILER_IS_GNU || MYLIB_COMPILER_IS_Clang || MYLIB_COMPILER_IS_AppleClang
#    define MYLIB_ALIGNOF(X) __alignof__(X)
#  elif MYLIB_COMPILER_IS_MSVC
#    define MYLIB_ALIGNOF(X) __alignof(X)
#  endif


#  if MYLIB_COMPILER_CXX_CONSTEXPR
#    define MYLIB_CONSTEXPR constexpr
#  else
#    define MYLIB_CONSTEXPR
#  endif


#  if MYLIB_COMPILER_CXX_FINAL
#    define MYLIB_FINAL final
#  else
#    define MYLIB_FINAL
#  endif


#  if MYLIB_COMPILER_CXX_NOEXCEPT
#    define MYLIB_NOEXCEPT noexcept
#    define MYLIB_NOEXCEPT_EXPR(X) noexcept(X)
#  else
#    define MYLIB_NOEXCEPT
#    define MYLIB_NOEXCEPT_EXPR(X)
#  endif


#  if MYLIB_COMPILER_CXX_NULLPTR
#    define MYLIB_NULLPTR nullptr
#  else
#    define MYLIB_NULLPTR static_cast<void*>(0)
#  endif


#  if MYLIB_COMPILER_CXX_THREAD_LOCAL
#    define MYLIB_THREAD_LOCAL thread_local
#  elif MYLIB_COMPILER_IS_GNU || MYLIB_COMPILER_IS_Clang || MYLIB_COMPILER_IS_AppleClang
#    define MYLIB_THREAD_LOCAL __thread
#  elif MYLIB_COMPILER_IS_MSVC
#    define MYLIB_THREAD_LOCAL __declspec(thread)
#  else
// MYLIB_THREAD_LOCAL not defined for this configuration.
#  endif

#endif

#endif
