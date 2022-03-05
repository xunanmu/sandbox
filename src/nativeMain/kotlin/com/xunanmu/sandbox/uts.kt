package com.xunanmu.sandbox

class Uts(val filePath: String){
    var hostName: String
    var domainName: String
    var fileIndeo:Long
    constructor(filePath: String,hostName:String="",domainName:String = ""):this(filePath){
        this.hostName = hostName
        this.domainName = domainName
        println("constructor")
    }
    init {
        hostName ="1234"
        domainName="456"
        fileIndeo = 1256776
        println("12345")
    }
}