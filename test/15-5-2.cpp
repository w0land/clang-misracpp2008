// RUN: %clang -fsyntax-only -ferror-limit=0 -Wno-macro-redefined -Wno-builtin-macro-redefined -Xclang -verify -Xclang -load -Xclang %llvmshlibdir/misracpp2008%pluginext -Xclang -plugin -Xclang misra.cpp.2008 -Xclang -plugin-arg-misra.cpp.2008 -Xclang 15-5-2 %s
#include <stdexcept>

class A {
public:
  void fun() throw(std::runtime_error, std::domain_error) {
    throw std::logic_error(""); // expected-error {{Where a function’s declaration includes an exception-specification, the function shall only be capable of throwing exceptions of the indicated type(s).}}
  }
};


//void bar() throw (std::logic_error) {
  //if (true) {
    //throw std::logic_error("");
  //}
//}
//void fun() throw(std::logic_error) {
  //bar();
//}


/* vim:set ft=cpp ts=2 sw=2 sts=2 cindent: */
