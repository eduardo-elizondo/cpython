#ifndef Py_INTERNAL_UNICODEOBJECT_H
#define Py_INTERNAL_UNICODEOBJECT_H
#ifdef __cplusplus
extern "C" {
#endif

#if !defined(Py_BUILD_CORE) && !defined(Py_BUILD_CORE_BUILTIN)
#  error "this header requires Py_BUILD_CORE or Py_BUILD_CORE_BUILTIN define"
#endif

#include "unicodeobject.h"



#define Py_UNICODE_FILL(target, value, length) \
    do {Py_ssize_t i_; Py_UNICODE *t_ = (target); Py_UNICODE v_ = (value);\
        for (i_ = 0; i_ < (length); i_++) t_[i_] = v_;\
    } while (0)

#define Py_UNICODE_ISALNUM(ch) \
       (Py_UNICODE_ISALPHA(ch) || \
    Py_UNICODE_ISDECIMAL(ch) || \
    Py_UNICODE_ISDIGIT(ch) || \
    Py_UNICODE_ISNUMERIC(ch))

#define Py_UNICODE_MATCH(string, offset, substring) \
    ((*((string)->wstr + (offset)) == *((substring)->wstr)) && \
     ((*((string)->wstr + (offset) + (substring)->wstr_length-1) == *((substring)->wstr + (substring)->wstr_length-1))) && \
     !memcmp((string)->wstr + (offset), (substring)->wstr, (substring)->wstr_length*sizeof(Py_UNICODE)))

#define Py_UNICODE_ISALPHA(ch) _PyUnicode_IsAlpha(ch)
#define Py_UNICODE_ISLINEBREAK(ch) _PyUnicode_IsLinebreak(ch)
#define Py_UNICODE_ISDECIMAL(ch) _PyUnicode_IsDecimalDigit(ch)
#define Py_UNICODE_ISDIGIT(ch) _PyUnicode_IsDigit(ch)
#define Py_UNICODE_ISLOWER(ch) _PyUnicode_IsLowercase(ch)
#define Py_UNICODE_ISNUMERIC(ch) _PyUnicode_IsNumeric(ch)
#define Py_UNICODE_TOLOWER(ch) _PyUnicode_ToLowercase(ch)
#define Py_UNICODE_TOUPPER(ch) _PyUnicode_ToUppercase(ch)
#define Py_UNICODE_TOTITLE(ch) _PyUnicode_ToTitlecase(ch)
PyAPI_FUNC(int) _PyUnicode_IsAlpha(Py_UCS4 ch /* Unicode character */);
PyAPI_FUNC(int) _PyUnicode_IsLinebreak(const Py_UCS4 ch /* Unicode character */);
PyAPI_FUNC(int) _PyUnicode_IsDecimalDigit(Py_UCS4 ch/* Unicode character */);
PyAPI_FUNC(int) _PyUnicode_IsDigit(Py_UCS4 ch/* Unicode character */);
PyAPI_FUNC(int) _PyUnicode_IsLowercase(Py_UCS4 ch /* Unicode character */);
PyAPI_FUNC(int) _PyUnicode_IsNumeric(Py_UCS4 ch /* Unicode character */);
PyAPI_FUNC(Py_UCS4) _PyUnicode_ToLowercase(
    Py_UCS4 ch       /* Unicode character */
    ) /* Py_DEPRECATED(3.3) */;
PyAPI_FUNC(Py_UCS4) _PyUnicode_ToUppercase(
    Py_UCS4 ch       /* Unicode character */
    ) /* Py_DEPRECATED(3.3) */;
PyAPI_FUNC(Py_UCS4) _PyUnicode_ToTitlecase(
    Py_UCS4 ch       /* Unicode character */
    ) Py_DEPRECATED(3.3);

#ifdef __cplusplus
}
#endif
#endif   /* !Py_INTERNAL_UNICODEOBJECT_H */
