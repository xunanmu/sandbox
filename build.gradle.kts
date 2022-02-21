@file:Suppress("RECEIVER_NULLABILITY_MISMATCH_BASED_ON_JAVA_ANNOTATIONS")

import org.jetbrains.kotlin.utils.addToStdlib.ifFalse
import java.net.URL
import com.google.common.io.Files

plugins {
    kotlin("multiplatform") version "1.6.10"
}

group = "me.xunanmu"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

("sched.klib" in mkdir("lib").list()).ifFalse {
    URL("https://gitee.com/xunanmu/klib/raw/master/linuxX64/sched.klib").apply {
        Files.write(readBytes(), file("lib/sched.klib"))
    }
}

("datetime.klib" in mkdir("lib").list()).ifFalse {
    URL("https://gitee.com/xunanmu/klib/raw/master/linuxX64/datetime.klib").apply {
        Files.write(readBytes(), file("lib/datetime.klib"))
    }
}
kotlin {

    linuxX64("native") {
        binaries {
            executable {
                entryPoint = "main"
            }
        }
    }
    sourceSets {
        val nativeMain by getting {
            dependencies {
                implementation(fileTree("lib"))
            }
        }
        val nativeTest by getting
    }
}
