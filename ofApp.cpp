#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){
    System.Update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    System.Draw();
    if(bDrawLine)
    {
        ofSetColor(ofColor::white);
        ofDrawLine(StartingVector.GetX(),StartingVector.GetY(),ofGetMouseX(),ofGetMouseY());
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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
    bDrawLine = true;

    StartingVector = Vector3D(x,y);
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    bDrawLine = false;
    const Vector3D EndVector(x,y);
    const Vector3D NewVector = EndVector.Sub(StartingVector);
    Particle * t = System.AddParticle(EndVector,NewVector.Multiply(0.025).Negate(),10,5);
    cout << NewVector.GetX() << "," << NewVector.GetY() << endl;
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
