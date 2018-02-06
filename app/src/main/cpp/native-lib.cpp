#include <jni.h>
#include <string>
#include <stdio.h>
#include <string.h>

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_javahe_ndkbeiginner_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jint
JNICALL
Java_com_javahe_ndkbeiginner_file_FileUtil_createNewFile
        (JNIEnv *env, jclass, jstring jfileName){
    char* fileName;
    FILE *stream = fopen("/sdcard/tmp/txt.txt", "w");
    if (NULL == stream) {
        printf("file open filed");
        return -1;
    } else {
        char data[] = {'h','e','l','l','o','\n'};
        size_t lenth = sizeof(data) / sizeof(data[0]);
        if(lenth!=fwrite(data, sizeof(char),lenth,stream)) {
            printf("write file failed");
            return 2;
        } else {
            return 1;
        }
    }

}
