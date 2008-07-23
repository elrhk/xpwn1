#ifndef LIBXPWN_H
#define LIBXPWN_H

typedef void (*LogMessageCallback) (const char * Message);

extern LogMessageCallback logCallback;

#if __STDC_VERSION__ < 199901L
# if __GNUC__ >= 2
#  define __func__ __FUNCTION__
# else
#  define __func__ "<unknown>"
# endif
#endif

#define XLOG(level, format, ...) Log(level, __FILE__, __LINE__, __func__, format, ## __VA_ARGS__)

#ifdef __cplusplus
extern "C" {
#endif
        void init_libxpwn();
        void libxpwn_log(LogMessageCallback callback);
        void Log(int level, const char* file, unsigned int line, const char* function, const char* format, ...);
        void TestByteOrder();
#ifdef __cplusplus
}
#endif

#endif

