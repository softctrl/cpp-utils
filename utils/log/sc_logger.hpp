/*
 *
 * Author:
 *  Carlos Timoshenko
 *  carlostimoshenkorodrigueslopes@gmail.com
 *
 *  https://github.com/softctrl
 *
 * This project is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 */
#ifndef SCLOGGER_H
#define SCLOGGER_H

#define _SC_LOG_F(__fmt, ...) std::printf((__fmt), __VA_ARGS__);

#define _SC_LOG(__type, __tag, __msg) _SC_LOG_F("[%c]-[%s]-%s\n", (__type), (__tag), (__msg));
#define _SC_LOG_V(__type, __tag, __msg) _SC_LOG_F("[%c]-[%s]<%d>- [%s]-%s\n", (__type), __FILE__, __LINE__, (__tag), (__msg));

#define _i(__tag, __msg) _SC_LOG('I', (__tag), (__msg));
#define _i_(__tag, __msg) _SC_LOG_V('I', (__tag), (__msg));

#define _w(__tag, __msg) _SC_LOG_V('W', (__tag), (__msg));

#define _e(__tag, __msg) _SC_LOG_V('E', (__tag), (__msg));
#define _e_ld(__tag, __msg, __code) _SC_LOG_F("[E]-[%s]<%d>- [%s]-%s(code:%ld)\n", __FILE__, __LINE__, (__tag), (__msg), (__code));
#define _e_d(__tag, __msg, __code) _SC_LOG_F("[E]-[%s]<%d>- [%s]-%s(code:%d)\n", __FILE__, __LINE__, (__tag), (__msg), (__code));
#define _e_s(__tag, __msg, __value) _SC_LOG_F("[E]-[%s]<%d>- [%s]-%s[%s]\n", __FILE__, __LINE__, (__tag), (__msg), (__value));
#define _e_s_ld(__tag, __msg, __value, __code) _SC_LOG_F("[E]-[%s]<%d>- [%s]-%s[%s](code:%ld)\n", __FILE__, __LINE__, (__tag), (__msg), (__value), (__code));

#endif // SCLOGGER_H
