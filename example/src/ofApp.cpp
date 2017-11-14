#include "ofApp.h"


void ofApp::setup()
{
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    
    tg.setup("/dev/tty.MindWaveMobile-DevA", 115200);
    tg.addEventListener(this);
    
}


void ofApp::draw()
{
    // draw a blue rectangle for meditation
    ofSetColor(0, 174, 240);
    float meditationScaled = ofMap(meditation, 0, 100, 0, ofGetHeight());
    ofDrawRectangle(0, ofGetHeight(), ofGetWidth()*.5, -meditationScaled);
    ofDrawBitmapStringHighlight(ofToString(meditation), ofGetWidth()*.25, ofGetHeight()-50);
    
    // draw a red rectangle for attention
    ofSetColor(255, 107, 130);
    float attentionScaled = ofMap(attention, 0, 100, 0, ofGetHeight());
    ofDrawRectangle(ofGetWidth()*.5, ofGetHeight(), ofGetWidth()*.5, -attentionScaled);
    ofDrawBitmapStringHighlight(ofToString(attention), ofGetWidth()*.75, ofGetHeight()-50);
}


void ofApp::onThinkgearReady(ofxThinkgearEventArgs& args)
{
    ofLog() << "*** THINKGEAR Ready...";
}

void ofApp::onThinkgearConnecting(ofxThinkgearEventArgs& args)
{
    ofLog() << "*** THINKGEAR connecting...";
}

void ofApp::onThinkgearError(ofMessage& err)
{
    ofLog() << "*** THINKGEAR onError..." << err.message;
}

void ofApp::onThinkgearRaw(ofxThinkgearEventArgs& args)
{
    // raw data does not send at frame rate - it sends faster! 512 samples a second
    //ofLog() << "raw: " << args.raw;
}

void ofApp::onThinkgearBlinkStrength(ofxThinkgearEventArgs& args)
{
    // no visual indicator for blinks
    // only works when using the comms driver (TG_COMMS_DRIVER)
    ofLog() << "blink: " << (int)args.blinkStrength;
}

void ofApp::onThinkgearBattery(ofxThinkgearEventArgs& args)
{
    // battery never fires?
    ofLog() << "*** THINKGEAR battery: " << (int)args.battery;
}

void ofApp::onThinkgearPoorSignal(ofxThinkgearEventArgs& args)
{
    ofLog() << "poor signal: " << (int)args.poorSignal;
}

void ofApp::onThinkgearAttention(ofxThinkgearEventArgs& args)
{
    ofLog() << "attention: " << (int)args.attention;
    attention = args.attention;
}

void ofApp::onThinkgearMeditation(ofxThinkgearEventArgs& args)
{
    ofLog() << "meditation: " << (int)args.meditation;
    meditation = args.meditation;
}


void ofApp::onThinkgearEeg(ofxThinkgearEventArgs& args)
{
    // about the 8 eeg bands (Comparison table of EEG rhythmic activity frequency bands): http://en.wikipedia.org/wiki/Electroencephalography
    // about neurusky's interpretation: http://support.neurosky.com/kb/development-2/eeg-band-power-values-units-amplitudes-and-meaning
    
    stringstream eegBands;
    eegBands << "delta: " << args.eegDelta;
    eegBands << ", theta: " << args.eegTheta;
    eegBands << ", alpha low: " << args.eegLowAlpha;
    eegBands << ", alpha high: " << args.eegHighAlpha;
    eegBands << ", beta low: " << args.eegLowBeta;
    eegBands << ", beta high: " << args.eegHighBeta;
    eegBands << ", gamma low: " << args.eegLowGamma;
    eegBands << ", gamma high: " << args.eegHighGamma;
    ofLog() << eegBands.str();
}
