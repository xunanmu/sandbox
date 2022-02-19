package com.xunanmu.logger

import kotlin.math.sign

/**
 * 前景色枚举值
 * @param i
 */
enum class LoggerColor {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    CYAN,
    WHITE,
}


/**
 * 设置字符串的颜色
 *
 * @param any
 * @return Sting
 */
inline fun LoggerColor.setColor(any:Any?): String {
    return "\u001b[$3{this.ordinal}m${any?.toString()}\u001b[0m"
}

/**
 * 设置字符串的颜色,亮色
 *
 * @param any
 * @return Sting
 */
inline fun LoggerColor.setBrightColor(any:Any?): String {
    return "\u001b[9${this.ordinal}m${any?.toString()}\u001b[0m"
}


public val Any?.black : String
    get() = LoggerColor.BLACK.setColor(this)

public val Any?.red : String
    get() = LoggerColor.RED.setColor(this)

public val Any?.green : String
    get() = LoggerColor.GREEN.setColor(this)

public val Any?.yellow : String
    get() = LoggerColor.YELLOW.setColor(this)

public val Any?.blue : String
    get() = LoggerColor.BLUE.setColor(this)

public val Any?.purple : String
    get() = LoggerColor.PURPLE.setColor(this)

public val Any?.cyan : String
    get() = LoggerColor.CYAN.setColor(this)

public val Any?.white : String
    get() = LoggerColor.WHITE.setColor(this)

public val Any?.brightBlack : String
    get() = LoggerColor.BLACK.setBrightColor(this)

public val Any?.brightRed : String
    get() = LoggerColor.RED.setBrightColor(this)

public val Any?.brightGreen : String
    get() = LoggerColor.GREEN.setBrightColor(this)

public val Any?.brightYellow : String
    get() = LoggerColor.YELLOW.setBrightColor(this)

public val Any?.brightBlue : String
    get() = LoggerColor.BLUE.setBrightColor(this)

public val Any?.brightPurple : String
    get() = LoggerColor.PURPLE.setBrightColor(this)

public val Any?.brightCyan : String
    get() = LoggerColor.CYAN.setBrightColor(this)

public val Any?.brightWhite : String
    get() = LoggerColor.WHITE.setBrightColor(this)
