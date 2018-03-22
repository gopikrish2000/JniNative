#include <jni.h>
#include <string>
#include "realcode/headers/jniHelper.h"

using namespace std;

extern "C"
JNIEXPORT jstring JNICALL
Java_com_jni_gopi_jnisampleapplication_helpers_FirstJNI_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    string hello = "Hello from C++";

    char ary[] = "my first string";
    return env->NewStringUTF(ary);
}

extern "C"
JNIEXPORT jintArray JNICALL
Java_com_jni_gopi_jnisampleapplication_helpers_FirstJNI_sampleJNI(
        JNIEnv *env,
        jobject
) {
    static int a[] = {2, 4, 6};
//    int *pInt = a;
    jintArray ljarray = env->NewIntArray(3);
//    ljarray.p
//    ljarray[1] = 4;

    jint ljint = 4;
    jint *ref = a;
//    SetO
//    ljarray[0] = ljint;
//    copy()
    env->SetIntArrayRegion(ljarray, 0, 3, ref);
    return ljarray;
}


extern "C"
JNIEXPORT jdoubleArray JNICALL
Java_com_jni_gopi_jnisampleapplication_helpers_FirstJNI_sampleDoubleArrayFilter(JNIEnv *env,
                                                                                jobject instance,
                                                                                jdoubleArray doubleAry_,
                                                                                jdouble doubleNumber) {
    jint length = env->GetArrayLength(doubleAry_);
    jdouble *doubleAry = env->GetDoubleArrayElements(doubleAry_, NULL);
    jdouble *resultPtr = getDoublesGreaterThanNumber(doubleAry,length,
                                                     doubleNumber); // no need of typecast
    jdoubleArray resultAry = env->NewDoubleArray(length);
    env->SetDoubleArrayRegion(resultAry, 0, length, resultPtr);

    env->ReleaseDoubleArrayElements(doubleAry_, doubleAry, 0);
    return resultAry;
}