#include "ofApp.h"

/******************************
******************************/
ofApp::ofApp()
{
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetWindowShape(640, 360);
	
#ifdef SINGLE_FILE
	video.loadMovie("0.mov");
	video.play();
#else

	video_set[0].setup(0);
	video_set[1].setup(3);
	
	id_VideoSet = 0;
	b_shift = false;

#endif
}

//--------------------------------------------------------------
void ofApp::update(){
#ifdef SINGLE_FILE
	video.update();
#else
	video_set[id_VideoSet].update();
#endif
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground( 255, 255, 255 );	//Set white background

	ofSetColor( 255, 255, 255 );

#ifdef SINGLE_FILE
	video.draw(0, 0, ofGetWidth(), ofGetHeight());
#else
	video_set[id_VideoSet].draw();
#endif
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{	
			int temp = key - '0';
			
			if(b_shift){
				if(temp < NUM_VIDEO_SETS){
					id_VideoSet = temp;
				}
			}else{
				video_set[id_VideoSet].SetId(temp);
			}
		}			
			break;
			
		case 'f':
		{
			static bool b_FullScreen = false;
			
			b_FullScreen = !b_FullScreen;
			
			ofSetFullscreen(b_FullScreen);
		}
			break;
		
		case OF_KEY_SHIFT:
			if(b_shift)	b_shift = false;
			else		b_shift = true;
			
			printf("b_shift = %d\n", b_shift);
			
			break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
