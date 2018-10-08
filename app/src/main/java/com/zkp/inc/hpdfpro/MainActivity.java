package com.zkp.inc.hpdfpro;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.CheckBox;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    private EditText etText, etSize, etSpace;

    static {
        System.loadLibrary("hpdf-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        etText = findViewById(R.id.et_text);
        etSize = findViewById(R.id.et_size);
        etSpace = findViewById(R.id.et_space);
    }

    /**
     * 生成PDF文件
     *
     * @param view
     */
    public void generate(View view) {
        generatePdf(etText.getText().toString(), Integer.parseInt(etSize.getText().toString()), Float.parseFloat(etSpace.getText().toString()));
    }

    public native int generatePdf(String text, int txtSize, float space);
}
