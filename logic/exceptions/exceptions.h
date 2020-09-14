
#ifndef DNA_EXCEPTIONS_H
#define DNA_EXCEPTIONS_H

#include <stdexcept>


class MyExceptions : public std::runtime_error
{
public:
    MyExceptions(const std::string &arg) : runtime_error(arg) {};
    const char* what() const throw();

};

class InvalidDna : public MyExceptions
{
public:
    InvalidDna(const std::string &arg) : MyExceptions(arg) {};
    const char* what() const throw();

};


class NoNullTerminate : public MyExceptions
{
public:
    NoNullTerminate(const std::string &arg) : MyExceptions(arg) {};
    const char* what() const throw();

};

class InvalidLetter : public MyExceptions
{
public:
    InvalidLetter(const std::string &arg) : MyExceptions(arg) {};
    const char* what() const throw();
    
};

class UnableReadFromFile : public MyExceptions
{
public:
    UnableReadFromFile(const std::string &arg) : MyExceptions(arg) {};
    const char* what() const throw();

};

class UnableWriteToFile : public MyExceptions
{
public:
    UnableWriteToFile(const std::string &arg) : MyExceptions(arg) {};
    const char* what() const throw();

};

class InvalidCmdName : public MyExceptions
{
public:
    InvalidCmdName(const std::string &arg) : MyExceptions(arg) {};
    const char* what() const throw();

};


class InvalidAmountOfArguments : public MyExceptions
{
public:
    InvalidAmountOfArguments(const std::string &arg) : MyExceptions(arg) {};
    const char* what() const throw();

};


class InvalidArgument : public MyExceptions
{
public:
    InvalidArgument(const std::string &arg) : MyExceptions(arg) {};
    const char* what() const throw();

};


inline const char* MyExceptions::what() const throw()
{
    return "Ooooops, i got an exception...";
}

inline const char* InvalidDna::what() const throw()
{
    return "You have to give a c-string consists of the characters {A, C, T, G}";
}

inline const char* NoNullTerminate::what() const throw()
{
    return "You have to give a string that end by a null-terminator.";
}

inline const char* InvalidLetter::what() const throw()
{
    return "You have to give one of the letters: A, C, T, G";
}

inline const char* UnableReadFromFile::what() const throw()
{
    return "Unable read from file, sorry...";
}

inline const char* InvalidArgument::what() const throw()
{
    return "Invalid syntax of argument";
}

inline const char* InvalidCmdName::what() const throw()
{
    return "Unrecognized command";
}

inline const char* UnableWriteToFile::what() const throw()
{
    return "Unable write to file, sorry...";
}

inline const char* InvalidAmountOfArguments::what() const throw()
{
    return "You're missed or gave too much arguments...";
}


#endif //DNA_EXCEPTIONS_H
