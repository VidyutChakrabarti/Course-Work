package com.example.prac8_b4_68;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import android.Manifest;
import android.content.Context;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    private static final int MY_PERMISSIONS_REQUEST_SEND_SMS =1;
    SQLiteDatabase db;
Button sub, res, allf;
EditText name,roln, phn, markn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        sub = findViewById(R.id.sub);
        res = findViewById(R.id.reset);
        allf = findViewById(R.id.all);
        name = findViewById(R.id.name);
        roln = findViewById(R.id.roll);
        phn = findViewById(R.id.mob);
        markn = findViewById(R.id.mark);
        sub.setOnClickListener(this);
        res.setOnClickListener(this);
        allf.setOnClickListener(this);
        db = openOrCreateDatabase("StudentDB", Context.MODE_PRIVATE, null);
        db.execSQL("CREATE TABLE IF NOT EXISTS student(name VARCHAR,rollno VARCHAR,marks VARCHAR,phone VARCHAR);");

    }
    public void onClick(View view){
        Button b = (Button) view;
        String b_text = b.getText().toString();
switch(b_text.toLowerCase()){
    case "submit":{
        Cursor c = db.rawQuery("SELECT * FROM student WHERE name='"+name.getText()+"'", null);
        if (name.getText().toString().isEmpty() || phn.getText().toString().isEmpty() || roln.getText().toString().isEmpty()
        || markn.getText().toString().isEmpty()) {
            Toast.makeText(getApplicationContext(), "Enter all details to submit!",
                    Toast.LENGTH_LONG).show();
        } else if(c.moveToFirst()){
            Toast.makeText(getApplicationContext(), "Already registered.",
                    Toast.LENGTH_LONG).show();
    }else{
            db.execSQL("INSERT INTO student VALUES('"+name.getText()+"','"+roln.getText()+
                    "','"+markn.getText()+"','" + phn.getText()+"');");
            showMessage("Registration Successful!", "your application has been stored.");
            checkForSmsPermission();
            name.getText().clear();
            //phn.getText().clear();
            roln.getText().clear();
            markn.getText().clear();
        }
break;
}
    case "reset all fields":{
        name.getText().clear();
        phn.getText().clear();
        roln.getText().clear();
        markn.getText().clear();
        break;
    }
    case "display all registrations":{
        Cursor c=db.rawQuery("SELECT * FROM student", null);
        // Checking if no records found
        if(c.getCount()==0)
        {
            showMessage("Error", "No records found");
            return;
        }
        // Appending records to a string buffer
        StringBuffer buffer=new StringBuffer();
        while(c.moveToNext())
        {
            buffer.append("Name: "+c.getString(0)+"\n");
            buffer.append("Roll no: "+c.getString(1)+"\n");
            buffer.append("Marks: "+c.getString(2)+"\n");
            buffer.append("Phone no: "+c.getString(3)+"\n\n");
        }
        // Displaying all records
        showMessage("Student Details", buffer.toString());
    }}}
    public void showMessage(String title,String message)
    {
        AlertDialog.Builder builder=new AlertDialog.Builder(MainActivity.this);
        builder.setCancelable(true);
        builder.setTitle(title);
        builder.setMessage(message);
        builder.show();
    }
    private void checkForSmsPermission() {
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.SEND_SMS) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.SEND_SMS}, MY_PERMISSIONS_REQUEST_SEND_SMS);
        } else {
            sendSmsMessage();
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode == MY_PERMISSIONS_REQUEST_SEND_SMS) {
            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                sendSmsMessage();
            } else {
                Toast.makeText(this, "SMS permission required to send an SMS.", Toast.LENGTH_LONG).show();
            }
        }
    }
    private void sendSmsMessage() {
        SmsManager smsManager = SmsManager.getDefault();
        smsManager.sendTextMessage(phn.getText().toString(), null, "You have successfully registered for the scholarship scheme.", null, null);
        Toast.makeText(getApplicationContext(), "SMS sent.", Toast.LENGTH_LONG).show();
    }

    }