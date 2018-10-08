package com.zkp.inc.hpdfpro;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

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
        int retCode = generatePdf(etText.getText().toString(), Integer.parseInt(etSize.getText().toString()), Float.parseFloat(etSpace.getText().toString()));
        if (retCode == 0) {
            Toast.makeText(this, "生成PDF文件成功,\n位置/sdcard/test.pdf", Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(this, "生成PDF文件失败", Toast.LENGTH_SHORT).show();
        }
    }

    public native int generatePdf(String text, int txtSize, float space);
}
