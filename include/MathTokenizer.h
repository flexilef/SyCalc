#ifndef MATHTOKENIZER_H
#define MATHTOKENIZER_H

#include <vector>
#include "Token.h"

class MathTokenizer
{
public:
    /** Default constructor */
    MathTokenizer();
    MathTokenizer(const std::string&);
    /** Default destructor */
    virtual ~MathTokenizer();

    bool hasNext();
    Token getNextToken();
    void setInput(const std::string&);
    void clear();
    void dumpTokens();

protected:

private:

    std::string input;
    std::vector<Token> tokens;
    int tokenIndex;

    void tokenize();
    bool isNumber(const std::string&);
    bool isOperator(const std::string&);
    bool isFunction(const std::string&);
};

#endif // MATHTOKENIZER_H