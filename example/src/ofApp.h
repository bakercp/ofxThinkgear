#pragma once


#include "ofMain.h"
#include "ofxThinkgear.h"


class ofApp: public ofBaseApp
{
public:
    void setup() override;
    void draw() override;

    ofxThinkgear tg;
    
    void onThinkgearError(ofMessage& err);
    void onThinkgearReady(ofxThinkgearEventArgs& args);
    void onThinkgearRaw(ofxThinkgearEventArgs& args);
    void onThinkgearBattery(ofxThinkgearEventArgs& args);
    void onThinkgearPoorSignal(ofxThinkgearEventArgs& args);
    void onThinkgearBlinkStrength(ofxThinkgearEventArgs& args);
    void onThinkgearAttention(ofxThinkgearEventArgs& args);
    void onThinkgearMeditation(ofxThinkgearEventArgs& args);
    void onThinkgearEeg(ofxThinkgearEventArgs& args);
    void onThinkgearConnecting(ofxThinkgearEventArgs& args);
    
    int attention = 0;
    int meditation = 0;
		
};
