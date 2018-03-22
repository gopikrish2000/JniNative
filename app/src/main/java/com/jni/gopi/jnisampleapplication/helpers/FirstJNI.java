package com.jni.gopi.jnisampleapplication.helpers;

/**
 * Created by gopi on 22/03/18.
 */

public class FirstJNI {

    static {
        System.loadLibrary("native-lib");
    }

    public native String stringFromJNI();

    public native int[] sampleJNI();

    public native double[] sampleDoubleArrayFilter(double[] doubleAry, double doubleNumber);
}
