#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"

/************************************************************
define
************************************************************/
// #define SINGLE_FILE

/************************************************************
class
************************************************************/

/**************************************************
**************************************************/
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

class VIDEO_SET{
private:
	enum{
		NUM_VIDEOS = 3,
	};
	
	int id;
	int offset;
	ofVideoPlayer video[NUM_VIDEOS];
	
	bool b_Ready;
	
public:
	VIDEO_SET()
	: b_Ready(false), id(0), offset(0)
	{
	}
	
	void setup(int _offset)
	{
		offset = _offset;
		
		for(int i = 0; i < NUM_VIDEOS; i++){
			char buf[500];
			sprintf(buf, "%d.mov", i + offset);
			
			video[i].loadMovie( buf );	//Load the video file
			
			video[i].setLoopState(OF_LOOP_NORMAL);
			video[i].setSpeed(1);					//Start the video to play	
			// video[i].setSpeed(0.5);
			
			video[i].setVolume(0);
			video[i].play();
		}
		
		b_Ready = true;
	}
	
	void update()
	{
		if(!b_Ready) return;
		
		for(int i = 0; i < NUM_VIDEOS; i++){
			video[i].update();
		}
	}
	
	void SetId(int _id)
	{
		if(0 <= id && id < NUM_VIDEOS){
			id = _id;
		}
	}
	
	void draw()
	{
		if(!b_Ready) return;
		
		video[id].draw(0, 0, ofGetWidth(), ofGetHeight());
	}
};
#pragma clang diagnostic pop


/**************************************************
**************************************************/
class ofApp : public ofBaseApp{
private:
		enum{
			NUM_VIDEO_SETS = 2,
		};
		
		VIDEO_SET video_set[NUM_VIDEO_SETS];
		int id_VideoSet;
		bool b_shift;
		
		ofVideoPlayer video;

	public:
		ofApp();
		
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
