//===-  Rule_18_0_5.cpp - Checker for MISRA C++ 2008 rule 18-0-5-----------===//
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "misracpp2008.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/AST/ASTContext.h"
#include "clang/Basic/Diagnostic.h"
#include <string>
#include <set>

using namespace clang;

namespace misracpp2008 {

const static std::string ruleName = "18-0-5";

class Rule_18_0_5 : public RuleCheckerASTContext,
                    public RecursiveASTVisitor<Rule_18_0_5> {
private:
  static const std::set<std::string> illegalFunctions;
public:
  Rule_18_0_5() : RuleCheckerASTContext() {}
  bool VisitDeclRefExpr(DeclRefExpr *expr) {
    std::string funName = expr->getNameInfo().getAsString();
    if(illegalFunctions.count(funName)) {
      unsigned diagID = diagEngine->getCustomDiagID(
            diagLevel, "The unbounded functions of library <cstring> shall not be used.");
      diagEngine->Report(expr->getLocStart(), diagID);
    }
    return true;
  }

protected:
  virtual void doWork() {
    RuleCheckerASTContext::doWork();
    this->TraverseDecl(context->getTranslationUnitDecl());
  }
};

const std::set<std::string> Rule_18_0_5::illegalFunctions = { "strcpy",
                                                              "strcmp",
                                                              "strcat",
                                                              "strchr",
                                                              "strspn",
                                                              "strcspn",
                                                              "strpbrk",
                                                              "strrchr",
                                                              "strstr",
                                                              "strtok",
                                                              "strlen" };

static RuleCheckerASTContextRegistry::Add<Rule_18_0_5>
  X(ruleName.c_str(), "MISRA C++ 2008 rule checker");
}