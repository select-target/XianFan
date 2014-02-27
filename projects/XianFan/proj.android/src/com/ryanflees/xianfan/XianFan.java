/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package com.ryanflees.xianfan;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.FrameLayout;

public class XianFan extends Cocos2dxActivity{
	
	static XianFan xianfanActivity = null;
	
	View m_view = null;
	FrameLayout m_viewLayout = null;
	
    protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);	
		xianfanActivity = this;
		m_viewLayout = new FrameLayout(this);
		addContentView(m_viewLayout, new LayoutParams(LayoutParams.FILL_PARENT, LayoutParams.FILL_PARENT));
    }
    
    static XianFan getInstance()
    {
    	return xianfanActivity;
    }
    
    public void showCustomView()
    {
    	//return;
    	
    	this.runOnUiThread(new Runnable(){

			@SuppressLint("SetJavaScriptEnabled")
			@Override
			public void run() {
				LoginLinearLayout loginLayout = new LoginLinearLayout(xianfanActivity);
				m_viewLayout.addView(loginLayout);
				
//				WebView webView = new WebView(xianfanActivity);
//				webView.getSettings().setJavaScriptEnabled(true);   
//				webView.getSettings().setBuiltInZoomControls(true);
//				webView.loadUrl("http://www.baidu.com");
//				webView.requestFocus();
//				webView.setWebViewClient(new WebViewClient(){       
//                    public boolean shouldOverrideUrlLoading(WebView view, String url) {   
//                        if(url.indexOf("tel:")<0){
//                            view.loadUrl(url); 
//                        }
//                        return true;       
//                    }    
//                });
//				m_viewLayout.addView(webView);
				
			}
    	});
    	
    }
    
    public Cocos2dxGLSurfaceView onCreateView() {
    	Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
    	// XianF an should create stencil buffer
    	glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
    	
    	return glSurfaceView;
    }

    static {
        System.loadLibrary("cocos2dcpp");
    }     
}
