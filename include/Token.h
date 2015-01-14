#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token
{
    public:
        enum Type
        {
            UNUSED = 0,
            NUMBER,
            VARIABLE,//is constant?
            OPERATOR,//is unary, binary?
            FUNCTION,//is argument: single, double, etc?
        };

        Type tokenType;

        /** Default constructor */
        Token();
        Token(const std::string&, Type);
        /** Default destructor */
        virtual ~Token();

        std::string getString();

    protected:
    private:
        std::string tokenString;
};

#endif // TOKEN_H
