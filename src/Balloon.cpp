#include "Balloon.h"

Balloon::Balloon(float x, float y, float r, float density, ofxBox2d &physics){
    shape = shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle());
    shape->setPhysics(density, 0.53, .1);
    shape->setMassFromShape = true;
    shape->setup(physics.getWorld(), x, y, r);
    mesh = ofMesh::sphere(r);
    radius = 1.0;
}

Balloon::~Balloon(){

}

void Balloon::draw(){
    ofPushMatrix();
        ofTranslate(shape->getPosition());
        ofRotateZ(shape->getRotation());
        ofScale(radius, radius, radius);
        ofSetColor(ofColor::orchid);
        mesh.draw();
        ofSetColor(ofColor::black);
        mesh.drawWireframe();
    ofPopMatrix();

    shape->draw();
}

void Balloon::inflate(float v){
    shape->setRadius(shape->getRadius() + v);
    radius += v;
    // shape->body->setMass(4.0/3.0 * 3.14159 * radius * radius * radius);
}
