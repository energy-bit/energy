package com.example.myapplicationcb5;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.KeyEvent;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private TextView mAlphavalueText;
    private ImageView mImage;
    private int mAlphavalue;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mImage = (ImageView)findViewById(R.id5.image);
        mAlphavalueText=(TextView)findViewById(R.id.alphavalue);
        mAlphavalue=100;
        mImage.setImageAlpha(mAlphavalue);
        mAlphavalueText.setText("Alpha= " + mAlphavalue * 100/255+ "%");
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event){
        switch(keyCode){
            case KeyEvent.KEYCODE_VOLUME_UP:
                mAlphavalue += 15;
                break;
            case KeyEvent.KEYCODE_VOLUME_DOWN:
                mAlphavalue -=15;
                break;
        }
        if(mAlphavalue>=255){
            mAlphavalue =255;
        }
        if(mAlphavalue<=0){
            mAlphavalue=0;
        }
        mImage.setImageAlpha(mAlphavalue);
        mAlphavalueText.setText("Alpha="+mAlphavalue*100/255+"%");
        return super.onKeyDown(keyCode,event);
    }
}
