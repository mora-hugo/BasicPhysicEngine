#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){
    FireBalls.Update();
    Bullets.Update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    FireBalls.Draw();
    Bullets.Draw();
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
    SpawnParticle(EndVector,NewVector.Multiply(0.025).Negate());
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

void ofApp::SpawnParticle(const Vector3D & Position, const Vector3D & Velocity)
{
    switch (CurrentParticleType)
    {
    case Bullet:
        Bullets.AddParticle(Position,Velocity.Multiply(2),20,5,5);
        break;
    case Fireball:
        FireBalls.AddParticle(Position,Velocity,30,5,5);
        break;
    default:
        break;

    }

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
