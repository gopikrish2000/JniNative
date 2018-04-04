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
    int size = length;
    jdouble *resultPtr = getDoublesGreaterThanNumber(doubleAry, length, doubleNumber, &size); // no need of typecast
    jdoubleArray resultAry = env->NewDoubleArray(size);
    env->SetDoubleArrayRegion(resultAry, 0, size, resultPtr);

    env->ReleaseDoubleArrayElements(doubleAry_, doubleAry, 0);

    return resultAry;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_jni_gopi_jnisampleapplication_helpers_FirstJNI_startCameraPreview(JNIEnv *env,
                                                                           jobject instance,
                                                                           jbyteArray byteAry_) {
    jint length = env->GetArrayLength(byteAry_);
    jbyte *jbyte = env->GetByteArrayElements(byteAry_, NULL);
    char *charPointer = ((char *) jbyte);
    int lengthOfArray = length;
//    printf("data returned from startCameraPreview");
//    printf(charPointer);
    printf("%s", charPointer);
    env->ReleaseByteArrayElements(byteAry_, jbyte, 0);
    return env->NewStringUTF(charPointer);
}