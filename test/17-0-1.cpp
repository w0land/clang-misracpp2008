// RUN: %clang -fsyntax-only -std=c++11 -ferror-limit=0 -Wno-macro-redefined -Wno-builtin-macro-redefined -Xclang -verify -Xclang -load -Xclang %llvmshlibdir/misracpp2008.so -Xclang -plugin -Xclang misra.cpp.2008 -Xclang -plugin-arg-misra.cpp.2008 -Xclang 17-0-1 %s

// Some allowed defines
#define LEGAL_DEFINE
#define DATE "today"
#define FILE myfile.cpp
#define LINE 123
#define STDC_HOSTED 1
#define TIME 0
#define STDC 1
#define ERRNO 99

#undef LEGAL_DEFINE
#undef DATE
#undef FILE
#undef LINE
#undef STDC_HOSTED
#undef TIME 
#undef STDC 
#undef ERRNO 
#undef ASSERT

// Disallowed usages
#define __cplusplus // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define __DATE__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define __FILE__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define __LINE__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define __STDC_HOSTED__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define __TIME__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define __STDC__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define __STDC_MB_MIGHT_NEQ_WC__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define __STDC_VERSION__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define __STDC_ISO_10646__// expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define __STDCPP_STRICT_POINTER_SAFETY__// expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define __STDCPP_THREADS__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define errno // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define assert // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define _ILLEGAL_NAME_WITH_UNDERSCORE_FIRST // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}

#undef __cplusplus // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef __DATE__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef __FILE__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef __LINE__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef __STDC_HOSTED__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef __TIME__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef __STDC__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef __STDC_MB_MIGHT_NEQ_WC__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef __STDC_VERSION__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef __STDC_ISO_10646__// expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef __STDCPP_STRICT_POINTER_SAFETY__// expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef __STDCPP_THREADS__ // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef errno // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef assert // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#undef _ILLEGAL_NAME_WITH_UNDERSCORE_FIRST // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}

#undef define // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}
#define define // expected-error {{Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined.}}

