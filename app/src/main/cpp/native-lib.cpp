#include <jni.h>
#include <string>
using namespace std;

extern "C"
JNIEXPORT jstring JNICALL
Java_com_jni_gopi_jnisampleapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    string hello = "Hello from C++";

    char ary[] = "my first string";
    return env->NewStringUTF(ary);
}

extern "C"
JNIEXPORT jintArray JNICALL
Java_com_jni_gopi_jnisampleapplication_MainActivity_sampleJNI(
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


/*
 * 1. // calling Java method from JNI
 *
 * JNIEXPORT void JNICALL
Java_Callbacks_nativeMethod(JNIEnv *env, jobject obj, jint depth)
{
    jclass cls = (*env)->GetObjectClass(env, obj);
    jmethodID mid = (*env)->GetMethodID(env, cls, "callback", "(I)V");
    if (mid == 0) {
        return;
    }
    printf("In C, depth = %d, about to enter Java\n", depth);
    (*env)->CallVoidMethod(env, obj, mid, depth);
    printf("In C, depth = %d, back from Java\n", depth);
}

 // 2. calling static Java method from JNI

 JNIEXPORT void JNICALL
Java_Callbacks_nativeMethod(JNIEnv *env, jobject obj, jint depth)
{
    jclass cls = (*env)->GetObjectClass(env, obj);
    jmethodID mid = (*env)->GetStaticMethodID(env, cls, "incDepth", "(I)I");
    if (mid == 0) {
        return;
    }
    depth = (*env)->CallStaticIntMethod(env, cls, mid, depth);
    ...
}

 // 3. Passing Array to JNI

 JNIEXPORT jint JNICALL
Java_IntArray_sumArray(JNIEnv *env, jobject obj, jintArray arr)
{
    int i, sum = 0;
    jsize len = (*env)->GetArrayLength(env, arr);
    jint *body = (*env)->GetIntArrayElements(env, arr, 0);
    for (i=0; i<len; i++) {
        sum += body[i];
    }
    (*env)->ReleaseIntArrayElements(env, arr, body, 0); // call release when ever Get... method has been called.
    return sum;
}

// 4. Synchronization in JNI

 (*env)->MonitorEnter(env, obj);
    ...                          // synchronized block //
(*env)->MonitorExit(env, obj);

 * */