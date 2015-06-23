//===-  Rule_15_5_2.cpp - Checker for MISRA C++ 2008 rule 15-5-2-----------===//
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===---------------------------------------------------------------------===//

#include "clang/AST/ASTContext.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Basic/Diagnostic.h"
#include "misracpp2008.h"
#include <iostream>

using namespace clang;

namespace misracpp2008 {

class Rule_15_5_2 : public RuleCheckerASTContext,
                   public RecursiveASTVisitor<Rule_15_5_2> {
public:
  Rule_15_5_2() : RuleCheckerASTContext() {}

  //bool VisitFunctionDecl(FunctionDecl *F) {
    //if (doIgnore(F->getLocStart())) {
      //return true;
    //}
    //F->dumpColor();
    //return true;
  //}

  bool VisitDecl(Decl *D) {
    if (doIgnore(D->getLocStart())) {
      return true;
    }

    if (isa<FunctionDecl>(D)) {
    }

    return true;
  }

protected:
  virtual void doWork() override {
    RuleCheckerASTContext::doWork();
    this->TraverseDecl(context->getTranslationUnitDecl());
  }
};

static RuleCheckerASTContextRegistry::Add<Rule_15_5_2> X("15-5-2", "");
}
/* vim:set ft=cpp ts=2 sw=2 sts=2 cindent: */
