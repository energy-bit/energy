package com.example.shiyan_3;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class SuccessActivity extends AppCompatActivity  {
    private final static String TAG="SuccessActivity";
    private Button btnBack;
    private TextView textView;
    private Button Ts;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_success);
        Log.v(TAG,"进入SuccessActivity");
        Intent it=this.getIntent();
        Bundle bundle=it.getExtras();
        final String userid=bundle.getString("userid");

        textView=(TextView)findViewById(R.id.textView);
        textView.setText("登录成功，Userid:"+userid);
        btnBack=(Button)findViewById(R.id.button_back);
        Ts=(Button)findViewById(R.id.tiaozhuan);
        btnBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });
        Ts.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent its=null;
                its=new Intent(SuccessActivity.this,XinActivity.class);
                startActivity(its);
            }
        });
    }
}
