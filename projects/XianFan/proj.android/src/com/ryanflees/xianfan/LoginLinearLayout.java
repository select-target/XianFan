package com.ryanflees.xianfan;

import android.content.Context;
import android.widget.LinearLayout;
import android.app.Activity;

public class LoginLinearLayout extends LinearLayout {

	public LoginLinearLayout(Context context)
	{
		super(context);
		((Activity) getContext()).getLayoutInflater().inflate(R.layout.login_account, this); 
	}
}
