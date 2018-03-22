package com.jni.gopi.jnisampleapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.jni.gopi.jnisampleapplication.helpers.FirstJNI;

import java.util.Arrays;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        FirstJNI firstJNI = new FirstJNI();
        String aryString = Arrays.toString(firstJNI.sampleJNI());
        double[] doubleGreaterThanNumberAry = firstJNI.sampleDoubleArrayFilter(new double[]{2, 5, 10, 12, 20}, 7);
        System.out.println("doubleGreaterThanNumberAry = " + Arrays.toString(doubleGreaterThanNumberAry));
        tv.setText(Arrays.toString(doubleGreaterThanNumberAry));
    }


}
