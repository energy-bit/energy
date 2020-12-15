package com.example.myapplicationlhq15;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity  {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // 创建2个按钮控制服务
        Button btnStart = (Button) findViewById(R.id.button_start);
        Button btnStop =(Button)findViewById(R.id.button_stop);
        //此行需要找到id为button_stop的按钮。。。
        btnStart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
             Intent serviceIntent=new Intent(MainActivity.this,MyService.class);   // 通过Intent来启动
                //此行需要创建Intent对象serviceIntent。。。
                startService(serviceIntent);
            }
        });
        btnStop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent serviceIntent=new Intent(MainActivity.this,MyService.class); // 通过Intent来停止
                //此行需要创建Intent对象serviceIntent。。。
                stopService(serviceIntent);
            }
        });
    }
}