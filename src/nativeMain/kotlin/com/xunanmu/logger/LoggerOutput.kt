package com.xunanmu.logger

import platform.posix.*


inline fun output(string: String) = print("$string\n")
inline fun outputError(string: String) = fputs("$string\n", stderr)