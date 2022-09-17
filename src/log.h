#ifndef LOG_H__
#define LOG_H__

#include <stdarg.h>

#define LOG_DEBUG_TYPE 0
#define LOG_MSG_TYPE   1
#define LOG_WARN_TYPE  2
#define LOG_ERR_TYPE   3

void myhttp_log(int serverity, const char *msg);
void myhttp_logx(int serverity, const char *errstr, const char *fmt, va_list ap);
void myhttp_msgx(const char *fmt, ...);
void myhttp_debugx(const char *fmt, ...);

#define LOG_MSG(msg) myhttp_log(LOG_MSG_TYPE, msg)
#define LOG_ERR(msg) myhttp_log(LOG_ERR_TYPE, msg)

#endif // !LOG_H
