#ifndef _CODE_TOOLS_
#define _CODE_TOOLS_

#include "ast.h"
#include "ShaderHolder.h"
#include <string>


#define MAIN_FUNC_SIGNATURE "main"
#define EMIT_VERTEX_SIGNATURE "EmitVertex"
#define END_PRIMITIVE_SIGNATURE "EndPrimitive"

struct exec_list;

__inline std::string FormatSourceRange(const YYLTYPE& range)
{
    char locText[128];

    sprintf(locText, "%4d:%3d - %4d:%3d", range.first_line, range.first_column - 1,
                                        range.last_line, range.last_column - 1);
    return std::string(locText);
}

void dumpNodeInfo(ast_node* node);
void dumpDbgStack(AstStack *stack);

long strToSwizzleIdx(const char*);
std::string getMangledName(ast_function_definition*  func);
char* getFunctionName(const char* in);
int getFunctionDebugParameter(ast_function_definition* node);
ast_node* getSideEffectsDebugParameter(ir_call* ir, int pnum);

bool list_iter_check(ir_instruction* const ir, int& state);
bool dbg_state_not_match(ast_node* node, enum ast_dbg_state state);


#endif

