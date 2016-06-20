#study__ofVideoPlayer

##環境
*	Xcode : 7.2
*	oF : 0.9.3

##Contents
ofideoPlayerのtest.

*	結論から言うと、ofxHapPlayerを使用すべき。  
	ofxHapPlayerは、1920 x 1080(codec = Hap)を6file同時に走らせても60fps出た。  
	ofVideoPlayerは、640 x 360で6fileでもきつい。  
	さらに、update()し続けないと、changeのtimingでクッと止まってしまう。  
*	motion jpgは再生不可であった
*	h264 は、再生できたが、3File/setで2set準備し、切り替えを行うと切り替えのtimingでクッと止まってしまった。
	動画サイズは、640 x 360。


##注記

