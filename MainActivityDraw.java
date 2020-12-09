package com.example.myapplicationcb6;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.graphics.RectF;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(new MyView(this));
    }
    public class MyView extends View {
        public MyView(Context context){
            super(context);
        }
        @Override
        public void onDraw(Canvas canvas){
            //创建画笔
            Paint paint=new Paint();
            //设置画笔颜色
            paint.setColor(Color.RED);

            Rect r1=new Rect(100,300,600,500);
            //绘制矩形
            canvas.drawRect(r1,paint);

            paint.setColor(Color.RED);
            RectF r2 = new RectF(200.0f,600.0f,600.0f,800.0f);
            canvas.drawRect(r2,paint);
            //开启抗锯齿效果
            paint.setAntiAlias(true);
            paint.setColor(Color.BLUE);

            RectF oval1=new RectF(300.0f,900.0f,600.0f,1200.0f);
            paint.setColor(Color.RED);
            //绘制度的圆
            canvas.drawArc(oval1,90,180,true,paint);

            paint.setColor(Color.BLUE);
            RectF oval2=new RectF(300.0f,1200.0f,600.0f,1600.0f);
            //绘制90~135度的圆弧
            canvas.drawArc(oval2,90,135,true,paint);
        }

    }
}
