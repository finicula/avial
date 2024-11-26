#include "include/AvialDialect.h"

#include "mlir/IR/Builders.h"      // For mlir::OpBuilder
#include "mlir/IR/Operation.h"     // For mlir::Operation
#include "mlir/IR/Dialect.h"       // For mlir::Dialect

#include "mlir/IR/AsmState.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Verifier.h"
#include "mlir/Parser/Parser.h"

#include "llvm/ADT/StringRef.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorOr.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"



class MLIRCodeGen : public Visitor
{

public:
    MLIRCodeGen() : 
        result(0), 
        context(),
        builder(&context),
        module(mlir::ModuleOp::create(builder.getUnknownLoc())) 
    {
        // Load Dialects here. 
        context.getOrLoadDialect<mlir::func::FuncDialect>();
        context.getOrLoadDialect<mlir::avial::AvialDialect>();

    }

    virtual void visitDeclarationStmt(const DeclarationStatement *dclstmt) override
    {
        
    }

    virtual void visitForallStmt(const ForallStatement *forAllStmt) override
    {
        
    }

    virtual void visitIfStmt(const IfStatement *ifStmt) override
    {
       
    }

    virtual void visitBoolExpr(const BoolExpr *boolExpr) override
    {
       
    }

    virtual void visitIncandassignstmt(const Incandassignstmt *incandassignstmt) override
    {
      
    }

    virtual void visitIdentifier(const Identifier *identifier) override
    {
    }

    virtual void visitReturnStmt(const ReturnStmt *returnStmt) override
    {
       
    }

    virtual void visitFunction(const Function *function) override
    {
        
        auto funcTy = builder.getFunctionType({},builder.getIntegerType(32));

        auto funcBl = mlir::func::FuncOp::create(builder.getUnknownLoc(), function->getfuncNameIdentifier(), funcTy);
        auto *entryBlock = funcBl.addEntryBlock();
        module.push_back(funcBl);
        builder.setInsertionPointToStart(entryBlock);
    }

    virtual void visitParamlist(const Paramlist *paramlist) override
    {

    }

    virtual void visitMethodcall(const Methodcall *methodcall) override
    {       
            
    }

    virtual void visitMemberaccess(const Memberaccess *memberaccess) override
    {
        
    }

    virtual void visitArglist(const Arglist *arglist) override
    {
        
    }

    virtual void visitArg(const Arg *arg) override
    {   
        
    }

    virtual void visitStatement(const Statement *statement) override
    {
    }

    virtual void visitStatementlist(const Statementlist *stmtlist) override
    {
            
    }

    virtual void visitType(const TypeExpr *type) override
    {
            
    }

    
    virtual void visitNumber(const Number *number) override
    {
           
    }

    
    virtual void visitExpression(const Expression *expr) override
    {
            
    }

    void printModule() {
        module.dump();
    }  





private:
    int result;
    map<string, int> variables;

    mlir::MLIRContext context;
    mlir::OpBuilder builder;
    mlir::ModuleOp module;

};

