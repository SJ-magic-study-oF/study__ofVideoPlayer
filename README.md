#study__ofVideoPlayer

##環境
*	Xcode : 7.2
*	oF : 0.9.3

##Contents
ofideoPlayerのtest.

*	結論から言うと、ofxHapPlayerを使用すべき。  
	ofxHapPlayerは、1920 x 1080(codec = Hap)を6file同時に走らせても60fps出た。  
	ofVideoPlayer x H264 or photo-jpgでは、640 x 360で6fileでもきつい。  
	さらに、update()し続けないと、changeのtimingでクッと止まってしまう。  
	さらには、motion-jpgは再生不可であった。


##note

