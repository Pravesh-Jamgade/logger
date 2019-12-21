# logger
Simple logging header written in C++. Helps in writing logs/comments, easy enabling/disabling of comments in output and passing multiple parameters to analyze in the output.

main.cpp is containing the usage of logger. main.cpp converts the infix expression to postfix. In between code, logger::log(arg1, arg2, arg3, ...) method is called, in the output arg1,arg2... will be present and allows us crosschecking ouput of suspicious stage. Log/comments made with logger can be disabled/enabled while initating instance of logger e.g logger l(true) -- enables output logging, whereas l(false) --disables.

