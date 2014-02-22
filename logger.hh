#ifndef _LOGGER_HH
#define _LOGGER_HH 1

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <utility>  // pair

// have to do this here because of circular dependencies
#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
typedef struct YYLTYPE {
    int first_line;
    int first_column;
    int last_line;
    int last_column;
} YYLTYPE;

#define YYLTYPE_IS_DECLARED 1
#define YYLTYPE_IS_TRIVIAL 1
#endif

enum LogLevel {
  LOG_ERROR,            // errors
  LOG_WARN,             // warnings
  LOG_INTERAL_ERROR,    // internal errors
  LOG_INFO,             // what we're up to
  LOG_DEBUG,            // base debug messages
  LOG_DEBUG_MINOR,      // minor debug messages
  LOG_DEBUG_SPAM,       // spammy debug messages
  LOG_CONTINUE,         // continuation of last message
};

enum ErrorCode {
    // errors
    E_ERROR                 = 10000,
    E_DUPLICATE_DECLARATION,
    E_INVALID_OPERATOR,
    E_DEPRECATED,
    E_DEPRECATED_WITH_REPLACEMENT,
    E_WRONG_TYPE,
    E_UNDECLARED,
    E_UNDECLARED_WITH_SUGGESTION,
    E_INVALID_MEMBER,
    E_MEMBER_NOT_VARIABLE,
    E_MEMBER_WRONG_TYPE,
    E_ARGUMENT_WRONG_TYPE,
    E_TOO_MANY_ARGUMENTS,
    E_TOO_FEW_ARGUMENTS,
    E_CHANGE_STATE_IN_FUNCTION,
    E_WRONG_TYPE_IN_ASSIGNMENT,
    E_WRONG_TYPE_IN_MEMBER_ASSIGNMENT,
    E_RETURN_VALUE_IN_EVENT_HANDLER,
    E_BAD_RETURN_TYPE,
    E_NOT_ALL_PATHS_RETURN,
    E_SYNTAX_ERROR,
    E_GLOBAL_INITIALIZER_NOT_CONSTANT,
    E_NO_OPERATOR,
    E_NO_EVENT_HANDLERS,
    E_PARSER_STACK_DEPTH,
    E_BUILTIN_LVALUE,
    E_SHADOW_CONSTANT,
    E_ARGUMENT_WRONG_TYPE_EVENT,
    E_TOO_MANY_ARGUMENTS_EVENT,
    E_TOO_FEW_ARGUMENTS_EVENT,
    E_INVALID_EVENT,
    E_DUPLICATE_DECLARATION_EVENT,
    E_LAST,
    
    


    // warnings
    W_WARNING               = 20000,
    W_SHADOW_DECLARATION,
    W_ASSIGNMENT_IN_COMPARISON,
    W_CHANGE_TO_CURRENT_STATE,
    W_CHANGE_STATE_HACK_CORRUPT,
    W_CHANGE_STATE_HACK,
    W_MULTIPLE_JUMPS_FOR_LABEL,
    W_EMPTY_IF,
    W_BAD_DECIMAL_LEX,
    W_DECLARED_BUT_NOT_USED,
    W_UNUSED_EVENT_PARAMETER,
    W_LIST_COMPARE,
    W_CONDITION_ALWAYS_TRUE,
    W_CONDITION_ALWAYS_FALSE,
    W_MULTIPLE_EVENT_HANDLERS,
    W_LAST,
    
    
};

#define LOG         Logger::get()->log
#define LOGV        Logger::get()->logv
#define IN(v)       (v)->get_lloc()
#define LINECOL(l)  (l)->first_line, (l)->first_column
#define HERE        IN(this)
#define ERROR       Logger::get()->error


#ifdef WIN32 /* hi my name is ms and i am stupid */
#ifdef DEBUG_LEVEL
#define DEBUG LOG
#else /* not DEBUG_LEVEL */
#define DEBUG __noop
#endif /* not DEBUG_LEVEL */
#else /* not WIN32 */
#ifdef DEBUG_LEVEL
#define DEBUG LOG
#else /* not DEBUG_LEVEL */
#ifdef __GNUC__
#define DEBUG(args...)
#else /* not __GNUC__ */
#define DEBUG(...)
#endif /* not __GNUC__ */
#endif /* not DEBUG_LEVEL */
#endif /* not WIN32 */

// Logger for a script. Singleton
class Logger {
  public:
    // get current instance
    static Logger* get();
    ~Logger();

    void set_path(const char *fpath) ;
    void log(LogLevel type, YYLTYPE *loc, const char *fmt, ...);
    void logv(LogLevel type, YYLTYPE *loc, const char *fmt, va_list args, ErrorCode error=(ErrorCode)0);
    void error( YYLTYPE *loc, ErrorCode error, ... );
    void report();

    int     get_errors()    { return errors;    }
    int     get_warnings()  { return warnings;  }
    void    set_show_end(bool v) { show_end = v; }
    void    set_show_info(bool v){ show_info = v;}
    void    set_sort(bool v)     { sort = v;     }
    void    set_show_error_codes(bool v) { show_error_codes = v; }
    void    set_check_assertions(bool v) { check_assertions = v; }
    void    set_file_path(const char *v) { file_path = v; }

    void    add_assertion( int line, ErrorCode error ) {
      assertions.push_back( new std::pair<int, ErrorCode>( line, error ) );
    }

  protected:
    Logger() : errors(0), warnings(0), show_end(false), show_info(false), sort(true), show_error_codes(false), check_assertions(false), file_path(NULL), last_message(NULL), file(stderr) {};
    int     errors;
    int     warnings;
    bool    show_end;
    bool    show_info;
    bool    sort;
    bool    show_error_codes;
    bool    check_assertions;
    const char *file_path;
    class LogMessage *last_message;

  private:
    static Logger *instance;
    FILE    *file;
    std::vector<class LogMessage*>    messages;
    std::vector<ErrorCode>            errors_seen;
    std::vector< std::pair<int, ErrorCode>* >    assertions;
    static const char* error_messages[];
    static const char* warning_messages[];
};

////////////////////////////////////////////////////////////////////////////////
// Log message entry, for sorting
class LogMessage {
  public:
    LogMessage( LogLevel type, YYLTYPE *loc, char *message, ErrorCode error );
    ~LogMessage();

    LogLevel    get_type() { return type; }
    YYLTYPE    *get_loc()  { return &loc;  }
    ErrorCode   get_error() { return error; }
    void        cont(char *message);
    void        print(FILE *fp);

  private:
    LogLevel            type;
    
    // we need our own copy of loc, because messages logged in the parser will be
    // handing us a copy of a loc structure that is constantly changing, and will
    // be invalid when we go to sort.
    YYLTYPE             loc;

    std::vector<char*>  messages;
    ErrorCode           error;
};

#endif /* not LOGGER_HH */
