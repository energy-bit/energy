package com.example.shiyan_3;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class LoginActivity extends AppCompatActivity {
    private final static String TAG="LoginActivity";
    private EditText txtUserid;
    private EditText txtPwd;//
    private Button btnLogin;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        Log.v(TAG,"进入LoginActivity");
        btnLogin=(Button) findViewById(R.id.button_login);
        txtUserid=(EditText) findViewById(R.id.editText_userid);
        txtPwd=(EditText)findViewById(R.id.editText_password);
        btnLogin.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                if(txtUserid.getText().toString().equals("jhl")&&txtPwd.getText().toString().equals("123")){
                    Intent it =new Intent(LoginActivity.this,SuccessActivity.class);
                    it.putExtra("userid",txtUserid.getText().toString());
                    startActivity(it);
                }else{
                    Intent it=new Intent(LoginActivity.this,FailureActivity.class);
                    startActivity(it);
                }
            }
        });
    }
}
